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
    matrix B_t = B.trasponer();
    B_t.mostrar();
    
    matrix A(3,3);  
    A.multiplicacion(B_t,B);

    A.mostrar();
    
    matrix D(3,3);
    matrix V(3,3);
    

    A.generacion_U_D(V,D,3);
    D.mostrar();
    V.mostrar();
    
    matrix S(3,3);
    S.matriz_Sigma(D);
    S.mostrar();

    matrix U(5,S.dame_rango());
    // a la mtrix D tenemos que sacarle la raiz
    B.conversionUaV(V,S,U);
    
    U.mostrar();


    matrix x(3,1);
    U = U.trasponer();
    x.SCML(U,S,V,b);

    x.mostrar();

}
