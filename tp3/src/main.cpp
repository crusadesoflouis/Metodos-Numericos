#include "aplicadorRectas.h"
#include <string>
using namespace std;

int main(int argc, char **argv) {
    string nombreImagen;
    cin >> nombreImagen;
    // bool hayQueAchicar;
    // cin >> hayQueAchicar;
    matrix original = matrix(nombreImagen);
    //matrix original_reduc = original.reducir_tamano();
    // if (hayQueAchicar){
    //     matrix original_reduc = original.reducir_tamano();
    // }
    // llamar a generar rectas a la matriz originial
    u_int ancho = original.dame_columnas();
    u_int alto = original.dame_filas();
    vector<Recta> rectas;
    //generar_rectas(rectas, densidad, distancia entre puntos, alto, ancho)
    GeneradorRectas::dame_rectas_sobre_base(rectas, 5, 20, alto, ancho);
    matrix destino(rectas.size(), alto*ancho);
    cout << "cantidad de rectas es " << rectas.size() << endl;
    vector<float> tiempos(rectas.size());
    AplicadorRectas::aplicar_rectas(original, rectas, tiempos, destino);
    //matrix matriz_discre = destino.discretizacion();
    //cout << "primera discretizacion " << matriz_discre.dame_filas() << ", " << matriz_discre.dame_columnas() << endl;
    matrix tiemposMatriz(tiempos.size(),1);
    tiemposMatriz.pasar_vector_matriz(tiempos);
    cout << "Cuadrados_Minimos de la discretizacion" << endl;
    matrix velocidades_discre = destino.Cuadrados_Minimos(tiemposMatriz);
    cout << "calulo velocidad original" << endl;
    matrix velocidades_ori(original.dame_filas()*original.dame_columnas(),1);
    velocidades_ori.pasar_matriz_vector(original);
    float error = velocidades_ori.ECM(velocidades_discre);
    cout << "error cuadratico medio es " << error << endl;
    velocidades_discre.guardarEnImagen(nombreImagen+".salida");



    // error cuadratico medio es 1.29119e+06 cuadrilla igual a la imagen
    // error cuadratico medio es 4.10889e+06 cuadrilla tamaño 128x128
}
