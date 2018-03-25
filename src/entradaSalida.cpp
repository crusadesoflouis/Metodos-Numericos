#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <tuple>
#include <vector>

using namespace std;

typedef int origen;
typedef int destino;
typedef tuple<origen,destino> link;

vector<link> leerSaltos(fstream& archivo){
  int m; // m = total de links
  archivo >> m;
  vector<link> links;
  for (size_t i = 0; i < m; i++) {
    origen desde;
    destino hacia;
    archivo >> desde >> hacia;
    links.push_back(make_tuple(desde,hacia));
  }
  return links;
}

int leerCantidadDePaginas(fstream& archivo){
  int n; // n = total de paginas
  archivo >> n;
  return n;
}

void escribirSalida(fstream& archivo, float p, float ranking[], int cantidadPaginas){
  archivo << p << endl;
  for (size_t i = 0; i < cantidadPaginas; i++) {
    archivo << ranking[i] << endl;
  }
}
