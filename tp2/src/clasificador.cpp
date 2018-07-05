#include <map>
#include <algorithm>

using namespace std;

typedef int id;
typedef double dist;
typedef unsigned char uchar;

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
        // ordeno para tener el de mayor distancia al final
        sort(masCercanos.begin(),masCercanos.end(),[] (tuple<id,dist> a, tuple<id,dist> b) { return get<1>(a) < get<1>(b); }); // TODO: mejorar haciendo un insertion sort
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
    double distanciaMinima;
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
