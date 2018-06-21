#include "matrix.h"

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
    char * nombreImagen = NULL;
    cin >> nombreImagen;
    bool hayQueAchicar;
    cin >> hayQueAchicar;
    matrix original = matrix(nombreImagen);
    if (hayQueAchicar){
        original = original.discretizar();
    }
}
