#include <stdlib.h>
#include <vector>
#include "aplicadorRectas.h"


using namespace std;

matrix crear_matriz(int filas, int columnas, double valores[]) {
    matrix nueva(filas, columnas);
    int c = 0;
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            nueva.agregar_elemento(i, j, valores[c]);
            c++;
        }
    }
    return nueva;
}

void mostrar(matrix &matriz, u_int fila, u_int cantidadColumnas) {
    std::cout << fila << " tuvieja\n";
    for (unsigned int i = 0; i < cantidadColumnas; i++) {
        for (unsigned int j = 0; j < cantidadColumnas; j++) {
            double elem = matriz.dame_elem_matrix(fila, i + j * cantidadColumnas);
            std::cout << ((elem == 0) ? " " : "*") << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {
    float arr1[] = {1,
                    2,
                    3,
                    4,
                    5,
                    6,
                    7,
                    8,
                    9};

    matrix imagen = crear_matriz(9, 1, arr1);
    matrix A(3, 3);
    A.vector_matriz(imagen);
    imagen.mostrar();
    A.mostrar();
    return 0;
}
