#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "imagen.hpp"

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
