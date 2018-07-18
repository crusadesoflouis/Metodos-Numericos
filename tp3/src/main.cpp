#include "aplicadorRectas.h"
#include <string>
using namespace std;

int main(int argc, char **argv) {
    /* Inicio de lectura de parametros*/
    int cant_reduccion;
    cin >> cant_reduccion;
    int cant_discretizacion;
    cin >> cant_discretizacion;
    string nombreImagen;
    cin >> nombreImagen;
    /* Fin*/

    matrix original = matrix(nombreImagen);
    for (unsigned int i = 0; i < cant_reduccion; ++i){
        original = original.reducir_tamano();
    }
    unsigned int ancho = original.dame_columnas();
    unsigned int alto = original.dame_filas();

    /* Creacion de las rectas*/

    vector<Recta> rectas;
    //generar_rectas(rectas, densidad, distancia entre puntos, alto, ancho)
    GeneradorRectas::dame_rectas_sobre_base_cuadratica(rectas, 1, 1, alto, ancho);
    cout << "cantidad de rectas es " << rectas.size() << endl; 
    /* Fin*/

    /* Creacion de la matriz D y el vector t*/
    matrix destino((unsigned int) rectas.size(), alto*ancho);
    //cout << "cantidad de rectas es " << rectas.size() << endl;
    vector<double> tiempos(rectas.size());
    AplicadorRectas::aplicar_rectas(original, rectas, tiempos, destino);

    /* Fin */
    

    /* Comenzamos las discretizacion de la matriz D*/   

    for (unsigned int i = 0; i < cant_discretizacion; ++i){
        destino = destino.discretizacion();
        original = original.reducir_tamano();
    } 

    /*Fin*/

    /* CML*/
    matrix tiemposMatriz((unsigned int) tiempos.size(),1);
    tiemposMatriz.pasar_vector_matriz(tiempos);
    cout << "Cuadrados_Minimos de la discretizacion" << endl;
    matrix velocidades_discre(destino.dame_columnas(), 1);
    destino.Cuadrados_Minimos(tiemposMatriz, velocidades_discre);
    /*Fin*/

    matrix velocidades_ori(ancho*alto,1);
    velocidades_ori.pasar_matriz_vector(original);

    /* Guardado de la imagen y muestro del ECM*/
        velocidades_discre.guardarEnImagen(nombreImagen+".salidaori");
        double error = velocidades_ori.ECM(velocidades_discre);
        cout << "error cuadratico medio es " << error << endl;
    /*FIn*/    


}
