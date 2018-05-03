#include <stdlib.h>
#include <vector>
#include <tuple>
#include "entradaSalida.cpp"
#include "clasificador.cpp"

using namespace std;

int main (int argc, char **argv){
  bool metodoConPCA = false;
  char *entrenamiento = NULL;
  char *test = NULL;
  char *salida = NULL;
  leerArgumentos(argc,argv,metodoConPCA,&entrenamiento,&test,&salida);
  vector<tuple<string,int>> nombresImagenesParaEntrenar = leerArchivo(entrenamiento);
  vector<tuple<string,int>> nombresImagenesAClasificar = leerArchivo(test);
  vector<tuple<uchar*,int>> imagenesParaEntrenar = cargarDatosDeImagenes(nombresImagenesParaEntrenar);
  vector<tuple<uchar*,int>> imagenesAClasificar = cargarDatosDeImagenes(nombresImagenesAClasificar);

  if(metodoConPCA){
    // hacerPCA();
  }
  vector<tuple<string,int>> solucion = knn(imagenesParaEntrenar,imagenesAClasificar, nombresImagenesAClasificar, 2);
  escribirArchivo(salida,solucion);
  return 0;
}
