#include <stdlib.h>
#include <vector>
#include <tuple>
#include <math.h>
#include "matrix.h"
#include "generadorRectas.h"

using namespace std;

typedef pair<unsigned int, unsigned int> Punto;
typedef pair<float, Punto> Recta;

class AplicadorRectas {
public:
    static void aplicar_rectas(matrix &imagen, vector<Recta> &rectas, vector<float> &velocidades, matrix &destino);

private:

    static void aplicar(uint posicion, Recta &recta, matrix &imagen, matrix &destino, vector<float> &velocidades);

    static void dame_proximo_punto(Recta &recta, float &i, float &j);
};