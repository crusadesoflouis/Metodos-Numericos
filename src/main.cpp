#include <iostream>
#include <stdlib.h>
#include "entradaSalida.cpp"
#include "matriz.h"
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    // leo la entrada
    float p = atof(argv[2]);
    fstream archivo(argv[1], ios_base::in);
    int cantidadPaginas = leerCantidadDePaginas(archivo);
    vector<link> links = leerSaltos(archivo);
    archivo.close();
    // construyo la matriz y resuelvo el problema
    matriz matrix = matriz(cantidadPaginas, links);
    float solucion[cantidadPaginas];
    matrix.rankear(solucion,p); // no le paso la cantidad de paginas porque tiene que ser un atributo interno de matriz
    // escribo la salida
    string nombreArchivo = (string) argv[1];
    nombreArchivo = nombreArchivo + ".out";
    fstream archivoSalida(nombreArchivo,fstream::in | fstream::out | fstream::trunc);
    escribirSalida(archivoSalida,p,solucion,cantidadPaginas);
    return 0;
}