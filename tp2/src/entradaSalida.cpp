#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include "../ppmloader/ppmloader.h"

using namespace std;

void leerArgumentos(int argc, char **argv, bool &metodo, char **entrenamiento, char **test, char **resultado){
  int c;
  while ((c = getopt (argc, argv, "m:i:o:q:")) != -1)
    switch (c){
      case 'm':
        metodo = *optarg == '1';
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

vector<tuple<string,int>> leerArchivo(char* nombreArchivo){
  vector<tuple<string,int>> imagenes;
  fstream archivo(nombreArchivo, ios_base::in);
  while (archivo.good()) {
    string lineaActual;
    getline(archivo, lineaActual);
    string path;
    string id;
    getline((stringstream)lineaActual, path, ',');
    getline((stringstream)lineaActual, id, ',');
    imagenes.push_back(make_tuple(path,stoi(id)));
  }
  archivo.close();
  return imagenes;
}

vector<tuple<uchar*,int>> cargarDatosDeImagenes(vector<tuple<string,int>> listaImagenes){
  vector<tuple<uchar*,int>> datosDeImagenes;
  for (size_t i = 0; i < listaImagenes.size(); i++) {
    uchar *datos = NULL;
    int width = 0;
    int height = 0;
    PPM_LOADER_PIXEL_TYPE pt = PPM_LOADER_PIXEL_TYPE_INVALID;
    LoadPPMFile(&datos, &width, &height, &pt, get<0>(listaImagenes[i]).c_str());
    datosDeImagenes.push_back(make_tuple(datos,get<1>(listaImagenes[i])));
  }
  return datosDeImagenes;
}

void escribirArchivo(char* nombreArchivo, vector<tuple<string,int>> solucion){
  fstream archivo(nombreArchivo, ios_base::out);
  for (size_t i = 0; i < solucion.size(); i++) {
    archivo << get<0>(solucion[i]) << ", " << get<1>(solucion[i]) << endl;
  }
  archivo.close();
}
