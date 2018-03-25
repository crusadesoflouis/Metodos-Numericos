#include <iostream>
#include <stdlib.h>
#include <tuple>
#include <vector>

using namespace std;

typedef int origen;
typedef int destino;
typedef tuple<origen,destino> link;


vector<link> leerSaltos(){
  int m; // m = total de links
  cin >> m;
  vector<link> links;
  for (size_t i = 0; i < m; i++) {
    origen desde;
    destino hacia;
    cin >> desde >> hacia;
    links.push_back(make_tuple(desde,hacia));
  }
  return links;
}

int leerCantidadDePaginas(){
  int n; // n = total de paginas
  cin >> n;
  return n;
}

void escribirSalida(int p, int ranking[], int cantidadPaginas){
  cout << p << endl;
  for (size_t i = 0; i < cantidadPaginas; i++) {
    cout << ranking[i] << endl;
  }
}
