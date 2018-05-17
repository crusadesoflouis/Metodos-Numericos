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
      cout << "dimensiones (" << x.dame_filas() << "," << x.dame_columnas() << ")" << endl;
      vector<float> mu = x.vector_promedio();
      x.resta_matrix_vector(mu);
      x.division_escalar(sqrt(x.dame_filas()-1));
      matrix xt = x.trasponer();
      cout << "dimensiones (" << xt.dame_filas() << "," << xt.dame_columnas() << ")" << endl;
      matrix mx = matrix(x.dame_filas(),x.dame_filas());
      cout << "dimensiones (" << mx.dame_filas() << "," << mx.dame_columnas() << ")" << endl;
      mx.multiplicacion(x,xt);
      //mx.division_escalar(x.dame_filas()-1);
      matrix u = matrix(mx.dame_filas(),mx.dame_filas());
      cout << "dimensiones (" << u.dame_filas() << "," << u.dame_columnas() << ")" << endl;
      matrix d = matrix(mx.dame_filas(),mx.dame_filas());
      cout << "dimensiones (" << d.dame_filas() << "," << d.dame_columnas() << ")" << endl;
      mx.generacion_U_D(u,d,mx.dame_filas());
      matrix v = matrix(x.dame_columnas(),u.dame_columnas());
      cout << "dimensiones (" << v.dame_filas() << "," << v.dame_columnas() << ")" << endl;
      xt.conversionUaV(u,d,v);
      v = v.trasponer();
      cout << "dimensiones (" << v.dame_filas() << "," << v.dame_columnas() << ")" << endl;
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
