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
      // x nxm
      matrix x = matrix(imagenesParaEntrenar);
      // mu mx1
      vector<float> mu = x.vector_promedio();
      x.resta_matrix_vector(mu);
      x.division_escalar(sqrt(x.dame_filas()-1));
      // xt mxn
      matrix xt = x.trasponer();
      // mx nxn ya que se multiplica x*xt
      matrix mx = matrix(x.dame_filas(),x.dame_filas());
      mx.multiplicacion(x,xt);
      // u nxn
      matrix u = matrix(mx.dame_filas(),mx.dame_filas());
      // d nxn
      matrix d = matrix(mx.dame_filas(),mx.dame_filas());
      int alfa = 50;
      mx.generacion_U_D(u,d,alfa);
      // v m x alpha
      matrix v = matrix(x.dame_columnas(),alfa);
      xt.conversionUaV(u,d,v);
      // vt alpha x m
      v = v.trasponer();
      // aplico el cambio de base a las imagenes
      for(int i = 0; i < imagenesParaEntrenar.size(); i++){
        imagenesParaEntrenar[i].calcularXRaya(mu,imagenesParaEntrenar.size());
      	// aplico tc
        // tc alpha x 1
      	matrix tc = aplicarTc(imagenesParaEntrenar[i], v);
      	imagenesParaEntrenar[i].setData(tc.dameMatriz());
      }
      for (int i = 0; i < imagenesAClasificar.size(); i++){
      	// calculo x(raya)*
        imagenesAClasificar[i].calcularXRaya(mu,imagenesParaEntrenar.size());
        // aplico tc
        matrix tc = aplicarTc(imagenesAClasificar[i], v);
        imagenesAClasificar[i].setData(tc.dameMatriz());
      }
    }
    vector<tuple<string,int>> solucion = knn(imagenesParaEntrenar,imagenesAClasificar,8);
    escribirArchivo(salida,solucion);
}
