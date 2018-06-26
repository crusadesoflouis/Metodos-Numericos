#include <stdlib.h>
#include <vector>
#include "aplicadorRectas.h"


using namespace std;

matrix crear_matriz(int filas, int columnas, float valores[]) {
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
    std::cout << '\n';
    for (unsigned int i = 0; i < cantidadColumnas; i++) {
        for (unsigned int j = 0; j < cantidadColumnas; j++) {
            float elem = matriz.dame_elem_matrix(fila, i + j * cantidadColumnas);
            std::cout << ((elem == 0) ? " " : "*") << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}


int main() {

    float arr1[] = {0,1,0,1,0,3,2,1,2,0,1,3,4,5,3,6,
                    2,2,1,0,1,2,1,3,1,0,1,3,4,5,4,1,
                    3,3,9,2,1,2,3,1,2,1,3,1,2,3,1,2,
                    1,1,1,0,1,0,1,2,0,3,1,0,2,1,0,3,
                    5,5,6,1,0,2,1,2,3,1,4,1,2,5,1,2};

    matrix B = crear_matriz(5,16,arr1);
    B.mostrar();
    matrix matriz_discre = B.discretizacion();
    matriz_discre.mostrar();
}
