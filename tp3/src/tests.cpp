#include <stdlib.h>
#include <vector>
#include "aplicadorRectas.h"


using namespace std;

matrix crear_matriz(int filas, int columnas, double valores[]) {
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
    std::cout << fila << " tuvieja\n";
    for (unsigned int i = 0; i < cantidadColumnas; i++) {
        for (unsigned int j = 0; j < cantidadColumnas; j++) {
            double elem = matriz.dame_elem_matrix(fila, i + j * cantidadColumnas);
            std::cout << ((elem == 0) ? " " : "*") << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}


int main(int argc, char **argv) {
//matrix imagen(argv[1]);
//imagen.mostrar();

double arr1[] = {1,2,3,4,5,6,7,
                1,2,3,4,5,6,7,
                1,2,3,4,5,6,7,
                1,2,3,4,5,6,7,
                1,2,3,4,5,6,7,
                1,2,3,4,5,6,7,
                1,2,3,4,5,6,7};

matrix imagen = crear_matriz(7,7,arr1);
u_int ancho = imagen.dame_columnas();
u_int alto = imagen.dame_filas();

vector<Recta> rectas;
GeneradorRectas::dame_rectas_sobre_base(rectas, 1, 1, alto, ancho);

//(n, n*m)
matrix destino(rectas.size(), imagen.dame_filas() * imagen.dame_columnas());
cout << destino.dame_filas() << ", " << destino.dame_columnas();

vector<double> velocidades(rectas.size());

AplicadorRectas::aplicar_rectas(imagen, rectas, velocidades, destino);
for (int i = 0; i < rectas.size(); ++i){
    mostrar(destino, i, imagen.dame_columnas());
}
matrix tiemposMatriz(velocidades.size(),1);
tiemposMatriz.pasar_vector_matriz(velocidades);
matrix velocidades_dis(destino.dame_columnas(),1); 
destino.Cuadrados_Minimos(tiemposMatriz,velocidades_dis);   
matrix velocidades_ori(49,1);
velocidades_ori.pasar_matriz_vector(imagen);
double error = velocidades_ori.ECM(velocidades_dis);
cout << "error cuadratico medio es " << error << endl;
destino.mostrar();
velocidades_dis.mostrar();
//velocidades_discre.guardarEnImagen(nombreImagen+".salida");
return 0;
}
