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

vector<tuple<string,int>> knn(vector<imagen> baseDeDatos, vector<imagen> nueva, int k){
  vector<tuple<string,int>> respuesta;
  for (size_t i = 0; i < nueva.size(); i++) {
    vector<tuple<id,dist>> masCercanos;
    for (size_t j = 0; j < baseDeDatos.size(); j++) {
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
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            nueva.agregar_elemento(i, j, valores[c]);
            c++;
        }
    }
    return nueva;
}

int main(int argc, char **argv) {
  //imagen a = imagen("../datosEntrenamiento/ImagenesCaras/s1/1.pgm",8);
  //a.guardar();
  // matrix U(3, 3);
  // matrix D(3, 3);
  // matrix B_1_T(B_1);
  // B_1.generacion_U_D(U, D);
  // U.mostrar();
  // D.mostrar();
  //
  // matrix V(3,3);
  // B_1_T.conversionUaV(U,D,V);
  // std::cout << "b_1_t" << '\n';
  // std::cout << "v" << '\n';
  // V.mostrar();
  //
  //
  // matrix autovector_1(3, 1);
  // V_1.normalizar();
  //

  // float arr1[] = {1, 2, 1, 0,
  //                 2, 2, 0, 0};
  //
  // matrix B_1 = crear_matriz(2, 4, arr1);
  //
  // // float arr2[] = {2,
  // //                 2,
  // //                 3};
  // // matrix V_1 = crear_matriz(3, 1, arr2);
  // matrix U(2, 2);
  // matrix D(2, 2);
  // matrix B_1_T(4,2);
  // B_1.mostrar();
  // B_1_T = B_1.trasponer();
  // std::cout << "mostrar trspuesta" << '\n';
  // B_1_T.mostrar();
  // B_1.generacion_U_D(U, D);
  // U.mostrar();
  // D.mostrar();
  //
  // matrix V(4,4);
  // B_1_T.conversionUaV(U,D,V);
  // std::cout << "b_1_t" << '\n';
  // std::cout << "v" << '\n';
  // V.mostrar();
  // float valor_1 = B_1.metodo_potencia(V_1, 25, autovector_1);
  // autovector_1.mostrar();
  // cout << "autovalor: " << valor_1 <<'\n';
  // matrix vector_resultado_1(3,1);
  // vector_resultado_1.multiplicacion(B_1,autovector_1);
  // autovector_1.multiplicacion_escalar(valor_1);
  // vector_resultado_1.mostrar();
  // autovector_1.mostrar();



  // //K = 6.7 converge con un error de un 30%% en el autovector pero acierta en el autovalor
  // float arr3[] = {3, 1, 2,
  //                 1, 9, 4,
  //                 2, 4, 6};
  // matrix B_2 = crear_matriz(3, 3, arr3);
  //
  // float arr4[] = {84,
  //                 17,
  //                 14};
  // matrix V_2 = crear_matriz(3, 1, arr4);
  //
  // matrix autovector_2(3, 1);
  // V_2.normalizar();
  //
  // float valor_2 = B_2.metodo_potencia(B_2, V_2, 25, autovector_2);
  //
  // autovector_2.mostrar();
  // cout << "autovalor: " << valor_2 <<'\n';
  // matrix vector_resultado_2(3,1);
  // vector_resultado_2.multiplicacion(B_2,autovector_2);
  // autovector_2.multiplicacion_escalar(valor_2);
  // vector_resultado_2.mostrar();
  // autovector_2.mostrar();


  //K = 1.4 error de 2-8% en el autovector, 0 en el autovalor
  // float arr5[] = {0, 1, 7,
  //                 1, 9, 0.1,
  //                 7, 0.1, 1};
  // matrix B = crear_matriz(3, 3, arr5);
  //
  // float arr6[] = {84,
  //                 17,
  //                 14};
  // matrix V = crear_matriz(3, 1, arr6);
  //
  // matrix autovector(3, 1);
  // V.normalizar();
  //
  // float valor = B.metodo_potencia(B, V, 5000000, autovector);
  //
  // autovector.mostrar();
  // cout << "autovalor: " << valor <<'\n';
  //
  // K = 253!!  30 a 50% en el autovector 0% en el autovalor
  // float arr5[] = {0, 1, 7,
  //                 1, 0, 0.1,
  //                 7, 0.1, 0};
  // matrix B = crear_matriz(3, 3, arr5);
  //
  // float arr6[] = {84,
  //                 17,
  //                 14};
  // matrix V = crear_matriz(3, 1, arr6);
  //
  // matrix autovector(3, 1);
  // V.normalizar();
  //
  // float valor = B.metodo_potencia(B, V, 1500, autovector);
  //
  // autovector.mostrar();
  // cout << "autovalor: " << valor <<'\n';
  //
  // matrix vector_resultado(3,1);
  // vector_resultado.multiplicacion(B,autovector);
  // autovector.multiplicacion_escalar(valor);
  // vector_resultado.mostrar();
  // autovector.mostrar();

  return 0;

}
