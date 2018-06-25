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

    float arr1[] = {10,15,23,4,3,2,9,15,
                    31,12,26,15,11,16,21,9,
                    21,10,4,9,11,15,9,8,
                    12,21,15,33,15,11,21,31};

    float arr2[] = {2,
                    1,
                    3,
                    5};

    matrix B = crear_matriz(4,8,arr1);
    matrix b = crear_matriz(4,1,arr2);
    B.mostrar();
    b.mostrar();
    matrix solucion = B.Cuadrados_Minimos(b);
    solucion.mostrar();                

}
