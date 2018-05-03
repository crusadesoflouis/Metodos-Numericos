#include <stdlib.h>
#include <vector>
#include <tuple>
#include <math.h>
#include <map>

using namespace std;

typedef int id;
typedef int dist;
typedef unsigned char uchar;

vector<tuple<string,int>> knn(vector<tuple<uchar*,int>> baseDeDatos, vector<tuple<uchar*,int>> nueva, vector<tuple<string,int>> nombresNueva, int k){
  vector<tuple<string,int>> respuesta;
  for (size_t i = 0; i < nueva.size(); i++) {
    vector<id,dist> masCercanos;
    for (size_t j = 0; j < baseDeDatos.size(); j++) {
      if(masCercanos.size() < k){ // si todavia no llene el vector agrego la imagen directamente
        masCercanos.push_back(make_tuple(get<1>(baseDeDatos[j],distancia(get<0>(baseDeDatos[j]),nueva[i]))));
      }else{
        // ordeno para tener el de mayor distancia al final
        masCercanos.sort(); // TODO: mejorar haciendo un insertion sort
        if(distancia(get<0>(baseDeDatos[j]),nueva[i]) < get<1>(masCercanos.back())){ // hay uno mas cercano que el mas lejano
          // saco el mas lejano
          masCercanos.pop_back();
          // agrego el nuevo
          masCercanos.push_back(make_tuple(get<1>(baseDeDatos[j],distancia(get<0>(baseDeDatos[j]),nueva[i]))));
        }
      }
    }
    // veo la moda
    map<id,int> frecuencias;
    for (size_t l = 0; l < k; l++) {
      if(frecuencias.count(get<0>(masCercanos[l]))) == 0){
        frecuencias[get<0>(masCercanos[l])] = 1;
      }else{
        ++frecuencias[get<0>(masCercanos[l])];
      }
    }
    int maximo = 0;
    int claveMaximo = 0;
    for (map<id,int>::iterator it=frecuencias.begin(); it!=frecuencias.end(); ++it) {
      if(it->second > maximo){
        maximo = it->second;
        claveMaximo = it->first;
      }
    }
    respuesta.push_back(make_tuple(get<0>(nombresNueva[i]),claveMaximo));
  }
}

double distancia(uchar* v1, uchar* v2){
  double respuesta = 0;
  for (size_t i = 0; i < v1.size(); i++) {
    respuesta += (v2-v1)*(v2-v1);
  }
  return sqrt(respuesta);
}
