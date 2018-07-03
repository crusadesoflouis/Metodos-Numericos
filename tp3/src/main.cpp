#include "aplicadorRectas.h"
#include <string>
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
    //original_reduc = original_reduc.reducir_tamano();
    //original_reduc = original_reduc.reducir_tamano();
    if (param == 0) {
        u_int ancho = original_reduc.dame_columnas();
        u_int alto = original_reduc.dame_filas();
        vector<Recta> rectas;
        //generar_rectas(rectas, densidad, distancia entre puntos, alto, ancho)
        GeneradorRectas::dame_rectas_sobre_base_cuadratica(rectas, 3, 3, alto, ancho);
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
        cout << "Cuadrados_Minimos de la discretizacion" << endl;
        matrix velocidades_discre(destino.dame_columnas(), 1);
        destino.Cuadrados_Minimos(tiemposMatriz, velocidades_discre);
        matrix velocidad_final((unsigned int) sqrt(velocidades_discre.dame_filas()), (unsigned int) sqrt(velocidades_discre.dame_filas()));
        velocidad_final.vector_matriz(velocidades_discre);
        velocidad_final.archivoCSV("velocidad_c++.csv");
        cout << "calulo velocidad original" << endl;
        matrix velocidades_ori(ancho*alto,1);
        velocidades_ori.pasar_matriz_vector(original_reduc);
        //velocidades_ori.guardarEnImagen(nombreImagen+".salidaori");
        double error = velocidades_ori.ECM(velocidades_discre);
        cout << "error cuadratico medio es " << error << endl;
    }else{
        string nombreCSV;
        cin >> nombreCSV;
        string nombreDim;
        cin >> nombreDim; 
        matrix v(nombreCSV,nombreDim);

    }
    /*cout << "Cuadrados_Minimos de la discretizacion" << endl;

    matrix velocidades_discre(destino.dame_columnas(), 1);
    destino.Cuadrados_Minimos(tiemposMatriz, velocidades_discre);
    velocidades_discre.mostrar();
    cout << "calulo velocidad original" << endl;
    
    matrix velocidades_ori(original_reduc.dame_filas()*original_reduc.dame_columnas(),1);
    velocidades_ori.pasar_matriz_vector(original_reduc);
    //velocidades_ori.guardarEnImagen(nombreImagen+".salidaori");
    float error = velocidades_ori.ECM(velocidades_discre);
    cout << "error cuadratico medio es " << error << endl;
    velocidades_discre.guardarEnImagen(nombreImagen+".salida");*/



    // error cuadratico medio es 1.29119e+06 cuadrilla igual a la imagen
    // error cuadratico medio es 4.10889e+06 cuadrilla tamaño 128x128
}
