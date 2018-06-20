#include <stdlib.h>
#include <vector>
#include <tuple>
#include <math.h>

using namespace std;

typedef pair<unsigned int, unsigned int> Punto;
typedef pair<float, Punto> Recta;

class GeneradorRectas {
public:
    static void dame_rectas(vector<Recta> &rectas, Punto origen, int densidad, int ancho, int alto);

private:
    static void recta(Recta &recta, Punto a, Punto b);
};
