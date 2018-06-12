#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <tuple>
#include <vector>

using namespace std;

typedef int origen;
typedef int destino;
typedef tuple<origen,destino> link;

void leerSaltos(fstream& archivo, link links[], int m){
  for (size_t i = 0; i < m; i++) {
    origen desde;
    destino hacia;
    archivo >> desde >> hacia;
    links[i] = make_tuple(desde,hacia);
  }
}

unsigned int leerCantidadDePaginas(fstream& archivo){
  unsigned int n; // n = total de paginas
  archivo >> n;
  return n;
}

void escribirSalida(fstream& archivo, float p, vector<float> ranking, int cantidadPaginas){
  archivo << p << endl;
  for (size_t i = 0; i < cantidadPaginas; i++) {
    archivo << ranking[i] << endl;
  }
}
