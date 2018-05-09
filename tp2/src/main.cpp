#include <stdlib.h>
#include <vector>
#include <tuple>
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
  srand(time(NULL));
    bool metodoConPCA = false;
    char *entrenamiento = NULL;
    char *test = NULL;
    char *salida = NULL;
    leerArgumentos(argc,argv,metodoConPCA,&entrenamiento,&test,&salida);
    vector<imagen> imagenesParaEntrenar = leerArchivo(entrenamiento);
    vector<imagen> imagenesAClasificar = leerArchivo(test);

    /*
    if(metodoConPCA){
      for (size_t i = 0; i < imagenesAClasificar.size(); i++) {
        matrix x = matrix(i);
        vector<float> mu = x.vector_promedio();
        x.resta_matrix_vector();
        x.division_escalar(sqrt(x.dame_filas()-1));
        matrix m = matrix(x.dame_filas(), x.dame_filas());
        m.multiplicacion(x,x.trasponer());
        matrix vectorInicial = matrix(x.dame_filas(),1,);
        matriz autovectores = matrix(x.dame_filas(),x.dame_filas());
        m.metodo_potencia(vectorInicial,1000,autovectores);
        m.deflacion(autovectores);
      }
    }
    */
    vector<tuple<string,int>> solucion = knn(imagenesParaEntrenar,imagenesAClasificar,5);
    escribirArchivo(salida,solucion);

    // main para prueba de matrix
    // K = 2.4 2%
    float arr1[] = {-3, 0.1, 1,
                    0.1, 5, 0.6,
                    1, 0.6, 2};
    matrix B_1 = crear_matriz(3, 3, arr1);

    float arr2[] = {2,
                    2,
                    3};
    matrix V_1 = crear_matriz(3, 1, arr2);

    B_1.deflacion(B_1,B_1);

    // matrix autovector_1(3, 1);
    // V_1.normalizar();
    //
    // float valor_1 = B_1.metodo_potencia(V_1, 25, autovector_1);
    // autovector_1.mostrar();
    // cout << "autovalor: " << valor_1 <<'\n';
    // matrix vector_resultado_1(3,1);
    // vector_resultado_1.multiplicacion(B_1,autovector_1);
    // autovector_1.multiplicacion_escalar(valor_1);
    // vector_resultado_1.mostrar();
    // autovector_1.mostrar();



    // //K = 6.7 converge con un error de un 30%% en el autovector pero acierta en el autovalor
    // float arr3[] = {3, 1, 2,
    //                 1, 9, 4,
    //                 2, 4, 6};
    // matrix B_2 = crear_matriz(3, 3, arr3);
    //
    // float arr4[] = {84,
    //                 17,
    //                 14};
    // matrix V_2 = crear_matriz(3, 1, arr4);
    //
    // matrix autovector_2(3, 1);
    // V_2.normalizar();
    //
    // float valor_2 = B_2.metodo_potencia(B_2, V_2, 25, autovector_2);
    //
    // autovector_2.mostrar();
    // cout << "autovalor: " << valor_2 <<'\n';
    // matrix vector_resultado_2(3,1);
    // vector_resultado_2.multiplicacion(B_2,autovector_2);
    // autovector_2.multiplicacion_escalar(valor_2);
    // vector_resultado_2.mostrar();
    // autovector_2.mostrar();


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
    //
    // K = 253!!  30 a 50% en el autovector 0% en el autovalor
    // float arr5[] = {0, 1, 7,
    //                 1, 0, 0.1,
    //                 7, 0.1, 0};
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
    // float valor = B.metodo_potencia(B, V, 1500, autovector);
    //
    // autovector.mostrar();
    // cout << "autovalor: " << valor <<'\n';
    //
    // matrix vector_resultado(3,1);
    // vector_resultado.multiplicacion(B,autovector);
    // autovector.multiplicacion_escalar(valor);
    // vector_resultado.mostrar();
    // autovector.mostrar();
    /*
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
    */

    return 0;
}
