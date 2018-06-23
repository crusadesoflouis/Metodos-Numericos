#include <stdlib.h>
#include <vector>
#include "aplicadorRectas.h"


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

void mostrar(matrix &matriz, u_int fila, u_int cantidadColumnas) {
    std::cout << '\n';
    for (unsigned int i = 0; i < cantidadColumnas; i++) {
        for (unsigned int j = 0; j < cantidadColumnas; j++) {
            float elem = matriz.dame_elem_matrix(fila, i + j * cantidadColumnas);
            std::cout << ((elem == 0) ? " " : "*") << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}


int main(int argc, char **argv) {
    matrix imagen(argv[1]);
    //imagen.mostrar();

    u_int ancho = imagen.dame_columnas();
    u_int alto = imagen.dame_filas();

    vector<Recta> rectas;
    GeneradorRectas::dame_rectas_sobre_base(rectas, 20, 20, alto, ancho);

    //(n, n*m)
    matrix destino(rectas.size(), imagen.dame_filas() * imagen.dame_columnas());
    cout << destino.dame_filas() << ", " << destino.dame_columnas();

    vector<float> velocidades(rectas.size());
    Recta patologica = rectas[28];
    rectas.clear();
    rectas.push_back(patologica);

    AplicadorRectas::aplicar_rectas(imagen, rectas, velocidades, destino);

    mostrar(destino, 0, imagen.dame_columnas());
    return 0;
}
