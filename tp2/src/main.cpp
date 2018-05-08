#include <stdlib.h>
#include <vector>
//#include "entradaSalida.cpp"
//#include "clasificador.cpp"
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
    /*bool metodoConPCA = false;
    char *entrenamiento = NULL;
    char *test = NULL;
    char *salida = NULL;
    leerArgumentos(argc,argv,metodoConPCA,&entrenamiento,&test,&salida);
    vector<imagen> imagenesParaEntrenar = leerArchivo(entrenamiento);
    vector<imagen> imagenesAClasificar = leerArchivo(test);

    if(metodoConPCA){
      //hacerPCA();
    }
    vector<tuple<string,int>> solucion = knn(imagenesParaEntrenar,imagenesAClasificar,5);
    escribirArchivo(salida,solucion);*/

    //main para prueba de matrix
    //K = 2.4
    // float arr1[] = {-3, 0.1, 1,
    //                 0.1, 5, 0.6,
    //                 1, 0.6, 2};
    // matrix B = crear_matriz(3, 3, arr1);

    // float arr2[] = {2,
    //                 2,
    //                 3};
    // matrix V = crear_matriz(3, 1, arr2);
    //
    // matrix autovector(3, 1);
    // V.normalizar();
    //
    // float valor = B.metodo_potencia(B, V, 5000000, autovector);
    //
    // autovector.mostrar();
    // cout << "autovalor: " << valor <<'\n';


    //K = 6.7 converge con un error de un 30%% en el autovector pero acierta en el autovalor
    // float arr3[] = {3, 1, 2,
    //                 1, 9, 4,
    //                 2, 4, 6};
    // matrix B = crear_matriz(3, 3, arr3);
    //
    // float arr4[] = {84,
    //                 17,
    //                 14};
    // matrix V = crear_matriz(3, 1, arr4);
    //
    // matrix autovector(3, 1);
    // V.normalizar();
    //
    // float valor = B.metodo_potencia(B, V, 5000000, autovector);
    //
    // autovector.mostrar();
    // cout << "autovalor: " << valor <<'\n';

    //K = 1.4 error de 2-8% en el autovector, 0 en el autovalor
    // float arr5[] = {0, 1, 7,
    //                 1, 9, 0.1,
    //                 7, 0.1, 1};
    // matrix B = crear_matriz(3, 3, arr5);
    //
    // float arr6[] = {84,
    //                 17,
    //                 14};
    // matrix V = crear_matriz(3, 1, arr6);
    //
    // matrix autovector(3, 1);
    // V.normalizar();
    //
    // float valor = B.metodo_potencia(B, V, 5000000, autovector);
    //
    // autovector.mostrar();
    // cout << "autovalor: " << valor <<'\n';

    // K = 253!!  30 a 50% en el autovector 0% en el autovalor
    float arr5[] = {0, 1, 7,
                    1, 0, 0.1,
                    7, 0.1, 0};
    matrix B = crear_matriz(3, 3, arr5);

    float arr6[] = {84,
                    17,
                    14};
    matrix V = crear_matriz(3, 1, arr6);

    matrix autovector(3, 1);
    V.normalizar();

    float valor = B.metodo_potencia(B, V, 5000000, autovector);

    autovector.mostrar();
    cout << "autovalor: " << valor <<'\n';

    return 0;
}
