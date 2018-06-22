#include "aplicadorRectas.h"
#include <string>
using namespace std;

int main(int argc, char **argv) {
    string nombreImagen;
    cin >> nombreImagen;
    bool hayQueAchicar;
    cin >> hayQueAchicar;
    int distRuido;
    cin >> distRuido;
    matrix original = matrix(nombreImagen);
    if (hayQueAchicar){
        original = original.discretizar();
    }
    // llamar a generar rectas a la matriz originial
    u_int ancho = original.dame_columnas();
    u_int alto = original.dame_filas();
    vector<Recta> rectas;
    GeneradorRectas::dame_rectas_sobre_base(rectas, 20, 20, alto, ancho);
    matrix destino_original(rectas.size(), alto*ancho);
    vector<float> velocidades(rectas.size());
    AplicadorRectas::aplicar_rectas(original, rectas, velocidades, destino_original);
    // proceso tomografico



    matrix ruido = destino_original.copiar_con_ruido(distRuido, 0.5, 1);
    // llamar a generar rectas a la matriz de ruido
    ancho = ruido.dame_columnas();
    alto = ruido.dame_filas();
    rectas.clear();
    GeneradorRectas::dame_rectas_sobre_base(rectas, 20, 20, alto, ancho);
    matrix destino(rectas.size(), alto*ancho);
    velocidades.clear();
    AplicadorRectas::aplicar_rectas(ruido, rectas, velocidades, destino);
    // hacer cuadrados minimos con la matriz de ruido
    ruido.guardarEnImagen(nombreImagen+".salida");
}
