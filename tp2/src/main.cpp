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
#include "entradaSalida.cpp"

using namespace std;

int main (int argc, char **argv){
  bool metodoConPCA = false;
  char *entrenamiento = NULL;
  char *test = NULL;
  char *salida = NULL;
  leerArgumentos(argc,argv,metodoConPCA,&entrenamiento,&test,&salida);
  vector<tuple<string,int>> imagenesParaEntrenar = leerArchivo(entrenamiento);
  vector<tuple<string,int>> imagenesAClasificar = leerArchivo(test);
  // hacerMagia();
  vector<tuple<string,int>> solucion;
  escribirArchivo(salida,solucion);
  return 0;
}
