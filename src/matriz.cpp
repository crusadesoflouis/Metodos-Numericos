#include "matriz.h"

matriz::matriz() {
}

matriz::matriz(unsigned int n) {
    filas.resize(n);

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
