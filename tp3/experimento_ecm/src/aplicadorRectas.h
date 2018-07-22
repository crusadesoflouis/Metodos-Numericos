#include <stdlib.h>
#include <vector>
#include <tuple>
#include <math.h>
#include "matrix.h"
#include "generadorRectas.h"

using namespace std;

typedef pair<unsigned int, unsigned int> Punto;
typedef pair<double, Punto> Recta;

enum Rotacion {
    SIN_ROTAR,
    CUARTO,
    MEDIA,
    TRES_CUARTOS
};

class AplicadorRectas {
public:
    static void aplicar_rectas(matrix &imagen, vector<Recta> &rectas, vector<double> &velocidades, matrix &destino);

    static void
    aplicar_rectas_con_rotaciones(matrix &imagen, vector<Recta> &rectas, vector<double> &velocidades, matrix &destino);

private:

    static void aplicar(uint posicion, Recta &recta, matrix &imagen, matrix &destino, vector<double> &velocidades);

    static void dame_proximo_punto(Recta &recta, double &i, double &j);

    static void aplicar_con_rotacion(unsigned int posicion, Recta &recta, matrix &imagen, matrix &destino,
                                     vector<double> &velocidades, Rotacion rotacion);

    static Punto rotar(unsigned int i, unsigned int j, unsigned int tam_imagen, Rotacion rotacion);
};