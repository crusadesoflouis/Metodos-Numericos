#include <iostream>
#include <stdlib.h>
#include "entradaSalida.cpp"
#include "matriz.cpp"
#include <vector>
#include <string>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[]) {
    // leo la entrada
    float p = atof(argv[2]);
    fstream archivo(argv[1], ios_base::in);
    unsigned int cantidadPaginas = leerCantidadDePaginas(archivo);
    int m; // m = total de links
    archivo >> m;
    link links[m];
    leerSaltos(archivo,links,m);
    archivo.close();
    // construyo la matriz y resuelvo el problema
    matriz matrix = matriz(cantidadPaginas, links,m);
    vector<float> solucion = matrix.rankear(p); // no le paso la cantidad de paginas porque tiene que ser un atributo interno de matriz
    // normalizo el vector
    float suma = 0;
    for (size_t i = 0; i < cantidadPaginas; i++) {
      suma += solucion[i];
    }
    for (size_t i = 0; i < cantidadPaginas; i++) {
      solucion[i] /= suma;
    }
    // escribo la salida
    string nombreArchivo = (string) argv[1];
    nombreArchivo = nombreArchivo + ".out";
    fstream archivoSalida(nombreArchivo,fstream::in | fstream::out | fstream::trunc);
    escribirSalida(archivoSalida,p,solucion,cantidadPaginas);
    return 0;
}
