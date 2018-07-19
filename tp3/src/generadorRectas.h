#include <stdlib.h>
#include <vector>
#include <tuple>
#include <math.h>
#include <cassert>

using namespace std;

typedef pair<unsigned int, unsigned int> Punto;
typedef pair<double, Punto> Recta;

class GeneradorRectas {
public:
    static void dame_rectas(vector<Recta> &rectas, Punto origen, int densidad, unsigned int ancho, unsigned int alto);

    static void
    dame_rectas_sobre_base(vector<Recta> &rectas, int densidad, int distancia_entre_puntos, unsigned int alto,
                           unsigned int ancho);

    static void
    dame_rectas_sobre_base(vector<Recta> &rectas, int densidad, int distancia_entre_puntos, int distancia_entre_bases,
                           unsigned int alto, unsigned int ancho);

    static void dame_rectas_sobre_base_cuadratica(vector<Recta> &rectas, int densidad, int distancia_entre_puntos,
                                                  unsigned int alto, unsigned int ancho);

    static void
    dame_rectas(vector<Recta> &rectas, vector<Punto> &origenes, int densidad, unsigned int ancho, unsigned int alto);

    static void dame_rectas_con_cantidad(vector<Recta> &rectas, int cantidad_de_rectas, unsigned int alto,
                                         unsigned int ancho);

private:
    static void recta(Recta &recta, Punto a, Punto b);


};
