#include "matrix.h"
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
    // proceso tomografico
    matrix ruido = original.copiar_con_ruido(distRuido, 0.5, 1);
    // llamar a generar rectas a la matriz de ruido
    // hacer cuadrados minimos con la matriz de ruido
    ruido.guardarEnImagen(nombreImagen+".salida");
}
