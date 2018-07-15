#include <stdlib.h>
#include <vector>
#include <tuple>
#include <math.h>
#include <map>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "matrix.h"

using namespace std;

typedef int id;
typedef double dist;
typedef unsigned char uchar;

matrix aplicarTc(imagen a, matrix &v){
  vector<imagen> aux;
  aux.push_back(a);
  matrix x = matrix(aux);
  x = x.trasponer();
  matrix resultado = matrix(v.dame_filas(),x.dame_columnas());
  resultado.multiplicacion(v,x);
  return resultado;
}

void insertarOrdenado(vector<tuple<id,dist>>& masCercanos, tuple<id,dist> nuevoElemento){
  masCercanos.push_back(nuevoElemento);
  int i = masCercanos.size()-2;
  while (i >= 0 && get<1>(masCercanos[i]) >= get<1>(nuevoElemento)){
    swap(masCercanos[i],masCercanos[i+1]);
    --i;
  }
}

vector<tuple<string,int>> knn(vector<imagen> baseDeDatos, vector<imagen> nueva, unsigned int k){
  vector<tuple<string,int>> respuesta;
  for (unsigned int i = 0; i < nueva.size(); i++) {
    vector<tuple<id,dist>> masCercanos;
    for (unsigned int j = 0; j < baseDeDatos.size(); j++) {
      if(masCercanos.size() < k){ // si todavia no llene el vector agrego la imagen directamente
        insertarOrdenado(masCercanos,make_tuple(baseDeDatos[j].getId(),baseDeDatos[j].distancia(nueva[i])));
      }else{
        if(baseDeDatos[j].distancia(nueva[i]) < get<1>(masCercanos.back())){ // hay uno mas cercano que el mas lejano
          // saco el mas lejano
          masCercanos.pop_back();
          // agrego el nuevo
          insertarOrdenado(masCercanos,make_tuple(baseDeDatos[j].getId(),baseDeDatos[j].distancia(nueva[i])));
        }
      }
    }
    // veo la moda
    map<id,tuple<int,dist>> frecuencias;
    for (size_t l = 0; l < k; l++) {
      if(frecuencias.count(get<0>(masCercanos[l])) == 0){
        frecuencias[get<0>(masCercanos[l])] = make_tuple(1,get<1>(masCercanos[l]));
      }else{
        ++get<0>(frecuencias[get<0>(masCercanos[l])]);
        get<1>(frecuencias[get<0>(masCercanos[l])]) += get<1>(masCercanos[l]);
      }
    }
    int maximo = 0;
    int claveMaximo = 0;
    double distanciaMinima = get<1>(frecuencias[get<0>(masCercanos[0])]);
    for (map<id,tuple<int,dist>>::iterator it=frecuencias.begin(); it!=frecuencias.end(); ++it) {
      if((get<0>(it->second) == maximo && distanciaMinima > get<1>(it->second)) || get<0>(it->second) > maximo){
        maximo = get<0>(it->second);
        distanciaMinima = get<1>(it->second);
        claveMaximo = it->first;
      }
    }
    respuesta.push_back(make_tuple(nueva[i].getPath(),claveMaximo));
  }
  return respuesta;
}

void leerArgumentos(int argc, char **argv, bool &pca, bool &alternativo, char **entrenamiento, char **test, char **resultado){
  int c;
  while ((c = getopt (argc, argv, "m:i:o:q:a")) != -1)
    switch (c){
      case 'm':
        pca = *optarg == '1';
        break;
      case 'a':
        alternativo = *optarg == '0';
        break;
      case 'i':
        *entrenamiento = optarg;
        break;
      case 'q':
        *test = optarg;
        break;
      case 'o':
        *resultado = optarg;
        break;
      default:
        abort();
    }
}

vector<imagen> leerArchivo(char* nombreArchivo){
  vector<imagen> imagenes;
  ifstream archivo(nombreArchivo, ios_base::in);
  while (!archivo.eof()) {
    string lineaActual;
    getline(archivo,lineaActual);
    if(lineaActual == ""){
      break;
    }
    string path;
    string id;
    stringstream linea(lineaActual);
    getline(linea, path, ',');
    getline(linea, id, ',');
    imagen actual = imagen(path,stoi(id));
    imagenes.push_back(actual);
  }
  archivo.close();
  return imagenes;
}

void escribirArchivo(char* nombreArchivo, vector<tuple<string,int>> solucion){
  fstream archivo(nombreArchivo, ios_base::out);
  for (size_t i = 0; i < solucion.size(); i++) {
    archivo << get<0>(solucion[i]) << ", " << get<1>(solucion[i]) << endl;
  }
  archivo.close();
}

matrix crear_matriz(int filas, int columnas, float valores[]) {
    matrix nueva(filas, columnas);
    int c = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            nueva.agregar_elemento(i, j, valores[c]);
            c++;
        }
    }
    return nueva;
}

int main(int argc, char **argv) {
  srand(time(NULL));
  int k = 5;
  //cin >> k;
  int alfa = 10;
  //cin >> alfa;
    bool metodoConPCA = false;
    bool metodoAlternativo = false;
    char *entrenamiento = NULL;
    char *test = NULL;
	char *salida = NULL;
    leerArgumentos(argc,argv,metodoConPCA,metodoAlternativo,&entrenamiento,&test,&salida);
    vector<imagen> imagenesParaEntrenar = leerArchivo(entrenamiento);
    vector<imagen> imagenesAClasificar = leerArchivo(test);
    if(metodoConPCA){
      // x nxm
      matrix x = matrix(imagenesParaEntrenar);
      // mu mx1
      vector<float> mu = x.vector_promedio();
      x.resta_matrix_vector(mu);
      x.division_escalar(sqrt(x.dame_filas()-1));
      // xt mxn
      matrix xt = x.trasponer();

      //Método alternativo: v mxAlpha
      //Sino: v mxm
      matrix v = matrix(x.dame_columnas(), metodoAlternativo ? alfa : x.dame_columnas());

      if(metodoAlternativo) {
          // mx nxn ya que se multiplica x*xt
          matrix mx = matrix(x.dame_filas(),x.dame_filas());
          mx.multiplicacion(x,xt);
          // u nxn
          matrix u = matrix(mx.dame_filas(),mx.dame_filas());
          // d nxn
          matrix d = matrix(mx.dame_filas(),mx.dame_filas());
          mx.generacion_U_D(u,d,alfa);
          // v m x alpha
          xt.conversionUaV(u,d,v);
          // vt alpha x m
          v = v.trasponer();
      } else {
          // mx mxm ya que se multiplica xt*x
          matrix mx = matrix(x.dame_columnas(),x.dame_columnas());
          mx.multiplicacion(xt,x);
          // v mxm, d mxm
          matrix d = matrix(x.dame_columnas(),x.dame_columnas());
          mx.generacion_U_D(v,d,alfa);
          // vt m x m
          v = v.trasponer();
      }

      // aplico el cambio de base a las imagenes
      for(unsigned int i = 0; i < imagenesParaEntrenar.size(); i++){
        imagenesParaEntrenar[i].calcularXRaya(mu,imagenesParaEntrenar.size());
      	// aplico tc
        // tc alpha x 1
      	matrix tc = aplicarTc(imagenesParaEntrenar[i], v);
      	imagenesParaEntrenar[i].setData(tc.dameMatriz());
      }
      for (unsigned int i = 0; i < imagenesAClasificar.size(); i++){
      	// calculo x(raya)*
        imagenesAClasificar[i].calcularXRaya(mu,imagenesParaEntrenar.size());
        // aplico tc
        matrix tc = aplicarTc(imagenesAClasificar[i], v);
        imagenesAClasificar[i].setData(tc.dameMatriz());
      }
    }
    vector<tuple<string,int>> solucion = knn(imagenesParaEntrenar,imagenesAClasificar,k);
    escribirArchivo(salida,solucion);
}
