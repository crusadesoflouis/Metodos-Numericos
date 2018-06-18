#include <stdlib.h>
#include <vector>
#include <tuple>
#include <math.h>
#include "entradaSalida.cpp"
#include "clasificador.cpp"
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

int main(int argc, char **argv) {

    // supongo que B = A*A^t entonces B pertenece a R^nxn
    matrix B(3,3,[1, 2, 3,
                  2, 3, 4,
                  3, 5, 9]);
    B.mostrar();
    
    matrix D(3,3);
    matrix U(3,3);
    matrix V(3,3);

    B.generacion_U_D(U,D,3);
    matrix B_t = B.trasponer();
    B_t.mostrar();

    // a la mtrix D tenemos que sacarle la raiz
    B_t.conversionUaV(U,D,V);
    
    U.mostrar();
    V.mostrar();
    D.mostrar();

}
