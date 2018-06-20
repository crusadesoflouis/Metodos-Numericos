#include "generadorRectas.h"

using namespace std;

void GeneradorRectas::recta(Recta &recta, Punto a, Punto b) {
    int delta_y = (a.second - b.second);
    int delta_x = (a.first - b.first);
    float m = (float) delta_y / (float) delta_x;
    recta = make_pair(m, b);
}

void GeneradorRectas::dame_rectas(vector<Recta> &rectas, Punto origen, int densidad, int ancho, int alto) {
    assert(origen.second == 0);
    for (int i = 0; i <= alto - 2; i = i + densidad) {
            Punto nuevo_izq = make_pair(0, i);
            Punto nuevo_der = make_pair(ancho - 1, i);

            if (origen.first != 0) {
                Recta r_izq;
                recta(r_izq, nuevo_izq, origen);
                rectas.push_back(r_izq);
            }

            if (origen.first != ancho - 1) {
                Recta r_der;
                recta(r_der, nuevo_der, origen);
                rectas.push_back(r_der);
            }
    }

    for (int i = ancho - 1; i >= 0; i = i - densidad) {
        if (origen.first != i) {
            Punto nuevo = make_pair(i, alto - 1);
            Recta r;
            recta(r, nuevo, origen);
            rectas.push_back(r);
        }
    }

}
