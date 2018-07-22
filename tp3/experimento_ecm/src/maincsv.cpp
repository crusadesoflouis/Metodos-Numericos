#include "aplicadorRectas.h"

using namespace std;

int main(int argc, char **argv) {
    int param;
    cin >> param;

    string nombreImagen;
    cin >> nombreImagen;
    // bool hayQueAchicar;
    // cin >> hayQueAchicar;
    matrix original = matrix(nombreImagen);
    matrix original_reduc = original.reducir_tamano();
    original_reduc = original_reduc.reducir_tamano();
    original_reduc = original_reduc.reducir_tamano();

    if (param == 0) {
        // if (hayQueAchicar){
        //     matrix original_reduc = original.reducir_tamano();
        // }
        // llamar a generar rectas a la matriz originial
        u_int ancho = original_reduc.dame_columnas();
        u_int alto = original_reduc.dame_filas();
        vector<Recta> rectas;
        //generar_rectas(rectas, densidad, distancia entre puntos, alto, ancho)
        GeneradorRectas::dame_rectas_sobre_base(rectas, 1, 1, alto, ancho);
        matrix destino((unsigned int) rectas.size(), alto * ancho);
        cout << "cantidad de rectas es " << rectas.size() << endl;
        vector<float> tiempos(rectas.size());
        AplicadorRectas::aplicar_rectas(original_reduc, rectas, tiempos, destino);

        destino.matrix2csv("destino.csv");
    } else {
        string nombreCSV;
        string nombreDim;
        cin >> nombreCSV;
        cin >> nombreDim;

        fstream dimensiones(nombreDim, ios::out);
        int filas = dimensiones.get();
        int columnas = dimensiones.get();

        matrix velocidades((unsigned int) filas, (unsigned int) columnas);
        velocidades.csv2Matrix(nombreCSV);

        velocidades.mostrar();
        cout << "calulo velocidad original" << endl;

        matrix velocidades_ori(original_reduc.dame_filas() * original_reduc.dame_columnas(), 1);
        velocidades_ori.pasar_matriz_vector(original_reduc);
        //velocidades_ori.guardarEnImagen(nombreImagen+".salidaori");
        float error = velocidades_ori.ECM(velocidades);
        cout << "error cuadratico medio es " << error << endl;
        velocidades.guardarEnImagen(nombreImagen + ".salida");
    }

    // error cuadratico medio es 1.29119e+06 cuadrilla igual a la imagen
    // error cuadratico medio es 4.10889e+06 cuadrilla tamaño 128x128
}
