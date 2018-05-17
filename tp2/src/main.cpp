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
      vector<float> mu = x.vector_promedio();
      x.resta_matrix_vector(mu);
      x.division_escalar(sqrt(x.dame_filas()-1));
      matrix xt = x.trasponer();
      matrix mx = matrix(x.dame_filas(),x.dame_filas());
      mx.multiplicacion(x,xt);
      //mx.division_escalar(x.dame_filas()-1);
      matrix u = matrix(mx.dame_filas(),mx.dame_filas());
      matrix d = matrix(mx.dame_filas(),mx.dame_filas());
      mx.generacion_U_D(u,d,mx.dame_filas());
      matrix v = matrix(u.dame_filas(),u.dame_columnas());
      mx.conversionUaV(u,d,v);
      v = v.trasponer();
      // aplico el cambio de base a las imagenes
      for(int i = 0; i < imagenesParaEntrenar.size(); ++i){
      	// aplico tc
      	matrix tc = aplicarTc(imagenesParaEntrenar[i], v);
      	imagenesParaEntrenar[i].setData(tc.dameMatriz());
      }
      for (int i = 0; i < imagenesAClasificar.size(); ++i){
      	// calculo x(raya)*
        imagenesAClasificar[i].calcularXRaya(mu,imagenesParaEntrenar.size());
        // aplico tc
        matrix tc = aplicarTc(imagenesAClasificar[i], v);
        imagenesAClasificar[i].setData(tc.dameMatriz());
      }
    }
    vector<tuple<string,int>> solucion = knn(imagenesParaEntrenar,imagenesAClasificar,5);
    escribirArchivo(salida,solucion);
}
