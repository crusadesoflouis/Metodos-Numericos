#include <random>
#include "generadorRectas.h"

using namespace std;

random_device randomDeviceS;

void GeneradorRectas::recta(Recta &recta, Punto a, Punto b) {
    int delta_y = (a.second - b.second);
    int delta_x = (a.first - b.first);
    double m = (double) delta_y / (double) delta_x;
    recta = make_pair(m, b);
}

void
GeneradorRectas::dame_rectas(vector<Recta> &rectas, Punto origen, int densidad, unsigned int ancho, unsigned int alto) {
    for (unsigned int i = origen.first + 1; i <= alto - 2; i = i + densidad) {
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
        if (origen.first != (unsigned int) i) {
            Punto nuevo = make_pair(i, alto - 1);
            Recta r;
            recta(r, nuevo, origen);
            rectas.push_back(r);
        }
    }
}

void GeneradorRectas::dame_rectas(vector<Recta> &rectas, vector<Punto> &origenes, int densidad, unsigned int ancho,
                                  unsigned int alto) {
    for (Punto origen : origenes) {
        dame_rectas(rectas, origen, densidad, alto, ancho);
    }
}

void GeneradorRectas::dame_rectas_sobre_base(vector<Recta> &rectas, int densidad, int distancia_entre_puntos,
                                             unsigned int alto,
                                             unsigned int ancho) {
    vector<Punto> puntos;
    for (uint i = 0; i < ancho; i = i + distancia_entre_puntos) {
        puntos.emplace_back(i, 0);
    }

    dame_rectas(rectas, puntos, densidad, ancho, alto);
}

void GeneradorRectas::dame_rectas_con_cantidad(vector<Recta> &rectas, int cantidad_de_rectas, unsigned int alto,
                                               unsigned int ancho) {
    // assert(cantidad_de_rectas % 4 == 0);
    // uniform_int_distribution x0(0, ancho - 1);  // rango [param1,param2]
    // uniform_int_distribution x1(0, ancho - 1);
    // uniform_int_distribution y1(0, ancho - 1);
    //
    // while (rectas.size() < cantidad_de_rectas) {
    //     Punto origen = make_pair(x0(randomDeviceS), 0);
    //     Punto destino = make_pair(x1(randomDeviceS), y1(randomDeviceS));
    //
    //     //TODO: revisar si hay alguna otra razon por la cual no querramos crear una recta con esos dos puntos.
    //     if (origen.first - destino.first != 0) {
    //         Recta r;
    //         recta(r, destino, origen);
    //         rectas.push_back(r);
    //     }
    // }
}

void GeneradorRectas::dame_rectas_sobre_base(vector<Recta> &rectas, int densidad, int distancia_entre_puntos,
                                             int distancia_entre_bases, unsigned int alto, unsigned int ancho) {
    vector<Punto> puntos;
    for (uint j = 0; j < alto; j = j + distancia_entre_bases) {
        for (uint i = 0; i < ancho; i = i + distancia_entre_puntos) {
            puntos.emplace_back(i, j);
        }
    }

    dame_rectas(rectas, puntos, densidad, ancho, alto);
}

void GeneradorRectas::dame_rectas_sobre_base_cuadratica(vector<Recta> &rectas, int densidad, int distancia_entre_puntos,
                                                        unsigned int alto, unsigned int ancho) {
    vector<Punto> puntos;
    for (uint j = 0; j < alto; j = (j + 1) * (j + 1)) {
        for (uint i = 0; i < ancho; i = i + distancia_entre_puntos) {
            puntos.emplace_back(i, j);
        }
    }

    dame_rectas(rectas, puntos, densidad, ancho, alto);
}
