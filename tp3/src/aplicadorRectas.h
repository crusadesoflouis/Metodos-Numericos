#include <stdlib.h>
#include <vector>
#include <tuple>
#include <math.h>
#include "matrix.h"
#include "generadorRectas.h"

using namespace std;

typedef pair<unsigned int, unsigned int> Punto;
typedef pair<double, Punto> Recta;

class AplicadorRectas {
public:
    static void aplicar_rectas(matrix &imagen, vector<Recta> &rectas, vector<double> &velocidades, matrix &destino);

private:

    static void aplicar(uint posicion, Recta &recta, matrix &imagen, matrix &destino, vector<double> &velocidades);

    static void dame_proximo_punto(Recta &recta, double &i, double &j);
};