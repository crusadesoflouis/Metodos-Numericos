#include "matriz.h"



matriz::matriz(unsigned int n) {
    filas.resize(n);
    tamanio = n;
    for (int i = 0; i < n; i++) {
        Fila fila;
        filas[i] = fila;
    }
}

vector<Fila> matriz::eliminacion_gausiana() {
    vector<Fila> A(tamanio);
    return A;
}

void matriz::rankear(unsigned int p) {
}

void matriz::mostrar() {
  std::cout << '\n';
    for (unsigned int  i = 0; i < tamanio; i++) {
      if (filas[i].empty() == true) {
        for (unsigned int  k = 0; k < tamanio; k++) {
          std::cout << "0 ";
        }
      std::cout << '\n';
      }
      else{
        for (unsigned int j = 0; j < tamanio; j++) {
          std::map<Columna ,Valor>::iterator it;
           it = filas[i].find(j);

           if (it != filas[i].end()) {
             std::cout << it->second << " ";
           }
          else{
               std::cout << "0 ";
          }
        }
        std::cout << '\n';
    }
  }
}


void matriz::agregar_links(unsigned int fila, unsigned int col) {
    pair<Columna, Valor> entry = make_pair(col - 1, 1);
    filas[fila - 1].insert(entry);
}

void matriz::multiplicacion(vector<float> &matriz_D) {

  for (unsigned int  i = 0; i < tamanio; i++) {
      for (unsigned int  j = 0; j < tamanio; j++) {
         std::map<Columna,Valor>::iterator it = filas[j].find(i);
         if (it != filas[j].end()){
           //la clave está en la matriz
           if (matriz_D[i] != 0) {
             // El elemento de la diagonal es =! a cero
             it->second = it->second*matriz_D[i];
           }
           else{
             filas[j].erase(it);
           }
         }
      }
  }
}

vector<Fila> matriz::restar_identidad(vector<Fila> &matriz_B) {
    vector<Fila> A(tamanio);
    return A;
}

vector<Fila> matriz::multiplicacion_escalar(vector<Fila> &matriz_B) {
    vector<Fila> A(tamanio);
    return A;
}

vector<float> matriz::buscar_solucion(vector<Fila> &matriz_B) {
    vector<float> A(tamanio);
    return A;
}
