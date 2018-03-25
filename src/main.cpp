#include <iostream>
#include <stdlib.h>
#include "entradaSalida.cpp"
#include "matriz.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  // leo la entrada
  int cantidadPaginas = leerCantidadDePaginas();
  vector<link> links = leerSaltos();
  int p = atoi(argv[2]);
  // construyo la matriz y resuelvo el problema
  matriz matrix = matriz(cantidadPaginas, links);
  int solucion[cantidadPaginas];
  matrix.rankear(solucion,p); // no le paso la cantidad de paginas porque tiene que ser un atributo interno de matriz
  // escribo la salida
  escribirSalida(p,solucion,cantidadPaginas);
  return 0;
}
