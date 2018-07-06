#include "aplicadorRectas.h"
#include <string>
using namespace std;

int main(int argc, char **argv) {
    int param = atoi(argv[1]);
    if (param == 0) {
        string nombreImagen = argv[3];
        matrix original = matrix(nombreImagen);
        matrix original_reduc(1,1);
        for (int i = 0; i < atoi(argv[2]); i++) {
          if (i == 0) {
            original_reduc = original.reducir_tamano();
          }else{
            original_reduc = original_reduc.reducir_tamano();
          }
        }
        matrix aux(original_reduc.dame_filas()*original_reduc.dame_columnas(),1);
        aux.pasar_matriz_vector(original_reduc);
        aux.archivoCSV("original_reducido.csv");
        u_int ancho = original_reduc.dame_columnas();
        u_int alto = original_reduc.dame_filas();
        vector<Recta> rectas;
        GeneradorRectas::dame_rectas_sobre_base_cuadratica(rectas, 1, 1, alto, ancho);
        matrix destino((unsigned int) rectas.size(), alto*ancho);
        cout << "cantidad de rectas es " << rectas.size() << endl;
        vector<double> tiempos(rectas.size());
        AplicadorRectas::aplicar_rectas(original_reduc, rectas, tiempos, destino);
        destino.archivoCSV("destino.csv");
        /*matrix matriz_discre = destino.discretizacion();
        matriz_discre = matriz_discre.discretizacion();
        matriz_discre = matriz_discre.discretizacion();*/
        //cout << "primera discretizacion " << destino.dame_filas() << ", " << destino.dame_columnas() << endl;
        matrix tiemposMatriz((unsigned int) tiempos.size(),1);
        tiemposMatriz.pasar_vector_matriz(tiempos);
        tiemposMatriz.archivoCSV("tiempo.csv");
        // cout << "Cuadrados_Minimos de la discretizacion" << endl;
        // matrix velocidades_discre(destino.dame_columnas(), 1);
        // destino.Cuadrados_Minimos(tiemposMatriz, velocidades_discre);
        // matrix velocidad_final((unsigned int) sqrt(velocidades_discre.dame_filas()), (unsigned int) sqrt(velocidades_discre.dame_filas()));
        // velocidad_final.vector_matriz(velocidades_discre);
        // velocidad_final.archivoCSV("velocidad_c++.csv");
        // cout << "calulo velocidad original" << endl;
        // matrix velocidades_ori(ancho*alto,1);
        // velocidades_ori.pasar_matriz_vector(original_reduc);
        // //velocidades_ori.guardarEnImagen(nombreImagen+".salidaori");
    }else{
        string nombreCSV = argv[2];
        string nombreDim = argv[3];
        string imgRed = argv[4];
        matrix v(nombreCSV,nombreDim);
        matrix ori_red(imgRed,nombreDim);
        double error = ori_red.ECM(v);
        cout << "error cuadratico medio es " << error << endl;
    }
return 0;
}
