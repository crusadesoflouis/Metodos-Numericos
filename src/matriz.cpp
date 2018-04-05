#include "matriz.h"

matriz::matriz() {
}

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

void matriz::mostrar(unsigned int fila, unsigned int columna) {
    std::cout << filas[fila - 1].at(columna - 1) << '\n';
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

void matriz::multiplicacion(vector<Fila> &matriz_D) {

}

vector<Fila> matriz::restar(vector<Fila> &matriz_B) {
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
