#include <stdlib.h>
#include <vector>
#include <tuple>
#include <math.h>
//#include "entradaSalida.cpp"
#include "matrix.cpp"


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

int main() {

    // supongo que B = A*A^t entonces B pertenece a R^nxn
    float arr1[] = {1,2,3,
                    2,3,4,
                    3,4,9,
                    2,5,4,
                    3,1,2};

    float arr2[] = {1,
                    2,
                    3,
                    4,
                    5};                

    matrix b = crear_matriz(5,1,arr2);
    b.mostrar();
    matrix B = crear_matriz(5,3,arr1);
    B.mostrar();
    matrix x(3,1);
    x.Cuadrados_Minimos(B,b);

}
