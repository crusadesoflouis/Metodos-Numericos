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
    if(metodoConPCA){
      matrix x = matrix(imagenesParaEntrenar);
      std::cout << "a" << '\n';
      vector<float> mu = x.vector_promedio();
      std::cout << "b" << '\n';
      x.resta_matrix_vector(mu);
      std::cout << "c" << '\n';
      x.division_escalar(sqrt(x.dame_filas()-1));
      matrix xt = x.trasponer();
      std::cout << "d" << '\n';
      matrix mx = matrix(x.dame_filas(),x.dame_filas());
      std::cout << "e" << '\n';
      mx.multiplicacion(x,xt);
      std::cout << "f" << '\n';
      //mx.division_escalar(x.dame_filas()-1);
      std::cout << "g" << '\n';
      matrix u = matrix(mx.dame_filas(),mx.dame_filas());
      matrix d = matrix(mx.dame_filas(),mx.dame_filas());
      mx.generacion_U_D(u,d);
      for (uint i = 0; i < 15; i++) {
      	cout << "elemento " << sqrt(d.dame_elem_matrix(i,i)) << endl;
      }
      //d.mostrar();
    }
    /*
    vector<tuple<string,int>> solucion = knn(imagenesParaEntrenar,imagenesAClasificar,5);
    escribirArchivo(salida,solucion);
    */
}
