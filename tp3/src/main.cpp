#include "aplicadorRectas.h"
#include <string>
using namespace std;

int main(int argc, char **argv) {
    string nombreImagen;
    cin >> nombreImagen;
    bool hayQueAchicar;
    cin >> hayQueAchicar;
    matrix original = matrix(nombreImagen);
    if (hayQueAchicar){
        original = original.discretizar();
    }
    // llamar a generar rectas a la matriz originial
    u_int ancho = original.dame_columnas();
    u_int alto = original.dame_filas();
    vector<Recta> rectas;
    cout << "primera fase" << endl;
    GeneradorRectas::dame_rectas_sobre_base(rectas, 20, 20, alto, ancho);
    matrix destino(rectas.size(), alto*ancho);
    vector<float> velocidades(rectas.size());
    cout << "face rectas" << endl;
    AplicadorRectas::aplicar_rectas(original, rectas, velocidades, destino);
    cout << "segunda fase" << endl;
    matrix velocidadesMatriz(velocidades.size(),1);
    velocidadesMatriz.pasar_vector_matriz(velocidades);
    cout << "Cuadrados_Minimos" << endl;
    matrix solucion = destino.Cuadrados_Minimos(velocidadesMatriz);
    solucion.mostrar();
    solucion.guardarEnImagen(nombreImagen+".salida");
}
