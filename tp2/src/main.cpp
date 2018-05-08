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
    float arr6[] = {-3, 0.1, 1,
                    0.1, 5, 0.6,
                    1, 0.6, 2};
    matrix B = crear_matriz(3, 3, arr6);

    float arr7[] = {2,
                    2,
                    3};
    matrix V = crear_matriz(3, 1, arr7);

    matrix autovector(3, 1);
    V.normalizar();

    float valor = B.metodo_potencia(B, V, 5000000, autovector);

    autovector.mostrar();
    cout << "autovalor:" << valor;

    return 0;
}
