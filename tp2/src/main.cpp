#include <stdlib.h>
#include <vector>
#include <tuple>
#include <cmath>
// #include "entradaSalida.cpp"
// #include "clasificador.cpp"
#include "matrix.cpp"


using namespace std;

matrix crear_matriz(int filas, int columnas, float valores[]){
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

int main (int argc, char **argv){
  // bool metodoConPCA = false;
  // char *entrenamiento = NULL;
  // char *test = NULL;
  // char *salida = NULL;
  // leerArgumentos(argc,argv,metodoConPCA,&entrenamiento,&test,&salida);
  // vector<imagen> imagenesParaEntrenar = leerArchivo(entrenamiento);
  // vector<imagen> imagenesAClasificar = leerArchivo(test);
  //
  // if(metodoConPCA){
  //   //hacerPCA();
  // }
  // vector<tuple<string,int>> solucion = knn(imagenesParaEntrenar,imagenesAClasificar,2);
  // escribirArchivo(salida,solucion);

  // main para prueba de matrix
  // int arr[] = {1, 5, 4,
  //              2, 3, 1};
  // matrix A = crear_matriz(2, 3, arr);
  //
  // int arr2[] = {7, 2,
  //               6, 3,
  //               1, 4};
  // matrix B = crear_matriz(3, 2, arr2);
  //
  // // A.mostrar();
  // // B.mostrar();
  //
  // matrix R(2, 2);
  //
  // R.multiplicacion(A, B);
  //
  // // R.mostrar();
  //
  // int arr3[] = {7, 2, 1, 1,
  //              0, 1, 0, 1};
  //
  // int arr4[] = {0, 3, 1,
  //               2, -1, 0,
  //               2, -1, 9,
  //               2, -1, 8};
  //
  // matrix C = crear_matriz(2, 4, arr3);
  // matrix D = crear_matriz(4, 3, arr4);
  //
  // // C.mostrar();
  // // D.mostrar();
  //
  // matrix R2(2, 3);
  // R2.multiplicacion(C, D);
  //
  //
  //
  float arr5[] = {1, 1, 1};

  matrix V = crear_matriz(3, 1, arr5);
  matrix V_T = crear_matriz(1, 3, arr5);

  float arr6[]= {1, 0, 2,
               0, 3, 0,
               2, 0, 2};
  matrix B = crear_matriz(3,3,arr6);
  matrix autovalor(3,1);
  float valor = metodo_potencia(B,V,5000000,autovalor);


  // std::cout << norma_Inf(F) << '\n';
  // std::cout << norma_euclidea_cuadrada(E,F) << '\n';
  // R2.mostrar();
  // matrix T(A.dame_columnas(),A.dame_filas());
  // A.trasponer(T);
  // vector<float> promedio = A.vector_promedio();
  // A.resta_matrix_vector(promedio);
  // A.mostrar();
  // A.division_escalar(2);



  return 0;
}
