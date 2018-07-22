#include "aplicadorRectas.h"
#include <string>

using namespace std;

void experimentarConRuido(int argc, char **argv) {
  //experimento con lena reduciendo minimo 1 vez para que no explote
  string nombreImagen = argv[2];
  string size = argv[3];
  matrix original = matrix(nombreImagen,size,0);
  // matrix original = matrix(nombreImagen);
  int tipo_ruido = 0;
  int median = 0;
  double desvioStandard = atof(argv[5]);
  int densidad = 1;
  int distancia_entre_puntos = 1;
  unsigned long int media = original.media_matrix();
  // original_con_ruido.archivoCSV(nombreImagen+"originalconruidored.csv");
  matrix original_reducida(1,1);
  // matrix original_reduc(1,1);
  for (int i = 0; i < atoi(argv[4]); i++) {
    if (i == 0) {
      original_reducida = original.reducir_tamano();
      // original_reduc = original.reducir_tamano();
    }else{
      original_reducida = original_reducida.reducir_tamano();
      // original_reducida_con_ruido = original_reducida_con_ruido.reducir_tamano();
    }
  }
  u_int ancho = original_reducida.dame_columnas();
  u_int alto = original_reducida.dame_filas();
  original_reducida.archivoCSV("reducida.csv");
  // matrix aux(alto*ancho,1);
  // aux.pasar_matriz_vector(original_reducida);
  // aux.archivoCSV(nombreImagen+"_red.csv");
  vector<Recta> rectas;
  GeneradorRectas::dame_rectas_sobre_base_cuadratica(rectas, densidad,distancia_entre_puntos, alto, ancho);
  matrix destino((unsigned int) rectas.size(), alto*ancho);
  vector<double> tiempos(rectas.size());
  AplicadorRectas::aplicar_rectas(original_reducida, rectas, tiempos, destino);
  matrix destino_ruido = destino.copiar_con_ruido(0,0,desvioStandard);
  destino.archivoCSV("destino.csv");
  matrix tiemposMatriz((unsigned int) tiempos.size(),1);
  tiemposMatriz.pasar_vector_matriz(tiempos);
  matrix tiempo_ruido = tiemposMatriz.copiar_con_ruido(0,0,desvioStandard);
  tiempo_ruido.archivoCSV("tiempos.csv");

}

void ecm_imagen(int argc, char **argv) {
  string original_reducida = argv[2];
  string original_reducida_dim = argv[3];
  string resultado = argv[4];
  string size = argv[5];
  matrix original = matrix(original_reducida, original_reducida_dim,0);
  matrix M_result = matrix(resultado,size,0);
  // M_result.mostrar();
  matrix imagen_vectorizada(M_result.dame_filas()*M_result.dame_columnas(),1);
  imagen_vectorizada.pasar_matriz_vector(M_result);
  imagen_vectorizada.guardarEnImagen("visualizacion.pgm");
  original.dame_filas();
  original.dame_columnas();
  M_result.dame_filas();
  M_result.dame_columnas();
  double error = M_result.ECM(original);
  std::cout << round(error) <<'\n';
}

int main(int argc, char **argv) {
  if (0 == atoi(argv[1])) {
    experimentarConRuido(argc, argv);
  }else{
    ecm_imagen(argc,argv);
  }


    return 0;
}
