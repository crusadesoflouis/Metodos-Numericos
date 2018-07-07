#include "aplicadorRectas.h"
#include <string>

using namespace std;

void experimentarConRuido(int argc, char **argv) {
  //experimento con lena reduciendo minimo 1 vez para que no explote
  string nombreImagen = argv[3];
  matrix original = matrix(nombreImagen);
  int tipo_ruido = atoi(argv[4]);
  int desvioStandard = atoi(argv[5]);
  int densidad = atoi(argv[6]);
  int distancia_entre_puntos = atoi(argv[7]);
  unsigned long int media = original.media_matrix();
  matrix original_con_ruido = original.copiar_con_ruido(tipo_ruido,media,desvioStandard);
  original_con_ruido.archivoCSV("_originalconruidored.csv");
  matrix original_reducida_con_ruido(1,1);
  matrix original_reduc(1,1);
  for (int i = 0; i < atoi(argv[2]); i++) {
    if (i == 0) {
      original_reducida_con_ruido = original_con_ruido.reducir_tamano();
      original_reduc = original.reducir_tamano();
    }else{
      original_reduc = original_reduc.reducir_tamano();
      original_reducida_con_ruido = original_reducida_con_ruido.reducir_tamano();
    }
  }
  u_int ancho = original_reduc.dame_columnas();
  u_int alto = original_reduc.dame_filas();
  matrix aux(alto*ancho,1);
  aux.pasar_matriz_vector(original_reduc);
  aux.archivoCSV(nombreImagen+"_red.csv");
  vector<Recta> rectas;
  GeneradorRectas::dame_rectas_sobre_base_cuadratica(rectas, densidad,distancia_entre_puntos, alto, ancho);
  matrix destino((unsigned int) rectas.size(), alto*ancho);
  cout << "cantidad de rectas es " << rectas.size() << endl;
  vector<double> tiempos(rectas.size());
  AplicadorRectas::aplicar_rectas(original_reducida_con_ruido, rectas, tiempos, destino);
  destino.archivoCSV("tipo_ruido "+to_string(tipo_ruido)+" densidad " +to_string(densidad) +" matriz_rectas.csv");
  matrix tiemposMatriz((unsigned int) tiempos.size(),1);
  tiemposMatriz.pasar_vector_matriz(tiempos);
  tiemposMatriz.archivoCSV(nombreImagen+"_tiempos.csv");

}



int main(int argc, char **argv) {
    // int param = atoi(argv[1]);
    // if (param == 0) {
    //     string nombreImagen = argv[3];
    //     matrix original = matrix(nombreImagen);
    //     matrix original_reduc(1,1);
    //     for (int i = 0; i < atoi(argv[2]); i++) {
    //       if (i == 0) {
    //         original_reduc = original.reducir_tamano();
    //       }else{
    //         original_reduc = original_reduc.reducir_tamano();
    //       }
    //     }
    //     matrix aux(original_reduc.dame_filas()*original_reduc.dame_columnas(),1);
    //     aux.pasar_matriz_vector(original_reduc);
    //     aux.archivoCSV("original_reducido.csv");
    //     u_int ancho = original_reduc.dame_columnas();
    //     u_int alto = original_reduc.dame_filas();
    //     vector<Recta> rectas;
    //     GeneradorRectas::dame_rectas_sobre_base_cuadratica(rectas, 1, 1, alto, ancho);
    //     matrix destino((unsigned int) rectas.size(), alto*ancho);
    //     cout << "cantidad de rectas es " << rectas.size() << endl;
    //     vector<double> tiempos(rectas.size());
    //     AplicadorRectas::aplicar_rectas(original_reduc, rectas, tiempos, destino);
    //     destino.archivoCSV("destino.csv");
    //     /*matrix matriz_discre = destino.discretizacion();
    //     matriz_discre = matriz_discre.discretizacion();
    //     matriz_discre = matriz_discre.discretizacion();*/
    //     //cout << "primera discretizacion " << destino.dame_filas() << ", " << destino.dame_columnas() << endl;
    //     matrix tiemposMatriz((unsigned int) tiempos.size(),1);
    //     tiemposMatriz.pasar_vector_matriz(tiempos);
    //     tiemposMatriz.archivoCSV("tiempo.csv");
    // }else{
    //     string nombreCSV = argv[2];
    //     string nombreDim = argv[3];
    //     string imgRed = argv[4];
    //     matrix v(nombreCSV,nombreDim);
    //     matrix ori_red(imgRed,nombreDim);
    //     double error = ori_red.ECM(v);
    //     cout << "error cuadratico medio es " << error << endl;
    // }

    experimentarConRuido(argc, argv);
    return 0;
}
