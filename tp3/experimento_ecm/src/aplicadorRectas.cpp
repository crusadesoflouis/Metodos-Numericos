#include "aplicadorRectas.h"

void
AplicadorRectas::aplicar_rectas(matrix &imagen, vector<Recta> &rectas, vector<double> &velocidades, matrix &destino) {
    for (unsigned int i = 0; i < rectas.size(); ++i) {
        aplicar(i, rectas[i], imagen, destino, velocidades);
    }
}

void AplicadorRectas::aplicar(unsigned int posicion, Recta &recta, matrix &imagen, matrix &destino,
                              vector<double> &velocidades) {
    double velocidad = 0;

    Punto origen = recta.second;
    auto i = (double) origen.first;
    auto j = (double) origen.second;

    while (i < imagen.dame_filas() && 0 <= i && 0 <= j && j < imagen.dame_columnas()) {
        u_int i_destino = posicion;
        u_int j_destino = (imagen.dame_columnas() * (unsigned int) i) + (unsigned int) j;

        velocidad = velocidad + imagen.dame_elem_matrix((unsigned int) i, (unsigned int) j);
        destino.agregar_elemento(i_destino, j_destino, 1);
        dame_proximo_punto(recta, i, j);
    }

    velocidades[posicion] = velocidad;
}

void AplicadorRectas::dame_proximo_punto(Recta &recta, double &i, double &j) {
    double m = recta.first;
    (m >= 0) ? i++ : i--;
    j = j + abs(m);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//APLICADOR CON ROTACIONES

void AplicadorRectas::aplicar_rectas_con_rotaciones(matrix &imagen, vector<Recta> &rectas, vector<double> &velocidades,
                                                    matrix &destino) {
    for (unsigned int i = 0; i < rectas.size(); i = i + 4) {
        aplicar_con_rotacion(i, rectas[i], imagen, destino, velocidades, SIN_ROTAR);
        aplicar_con_rotacion(i + 1, rectas[i + 1], imagen, destino, velocidades, CUARTO);
        aplicar_con_rotacion(i + 2, rectas[i + 2], imagen, destino, velocidades, MEDIA);
        aplicar_con_rotacion(i + 3, rectas[i + 3], imagen, destino, velocidades, TRES_CUARTOS);
    }
}

void AplicadorRectas::aplicar_con_rotacion(unsigned int posicion, Recta &recta, matrix &imagen, matrix &destino,
                                           vector<double> &velocidades, Rotacion rotacion) {
    double velocidad = 0;

    Punto origen = recta.second;
    auto i = (double) origen.first;
    auto j = (double) origen.second;

    //TODO: REVISAR GUARDA
    while (i < imagen.dame_filas() && 0 <= i && 0 <= j && j < imagen.dame_columnas()) {
        Punto punto_rotado = rotar((unsigned int) i, (unsigned int) j, imagen.dame_filas(), rotacion);

        u_int i_destino = posicion;
        u_int j_destino = (imagen.dame_columnas() * punto_rotado.first) + punto_rotado.second;

        velocidad = velocidad + imagen.dame_elem_matrix(punto_rotado.first, punto_rotado.second);
        destino.agregar_elemento(i_destino, j_destino, 1);
        dame_proximo_punto(recta, i, j);
    }

    velocidades[posicion] = velocidad;
}

Punto AplicadorRectas::rotar(unsigned int i, unsigned int j, unsigned int tam_imagen, Rotacion rotacion) {
    int i_nuevo;
    int j_nuevo;

    switch (rotacion) {
        case SIN_ROTAR:
            i_nuevo = i;
            j_nuevo = j;
            break;
        case CUARTO:
            i_nuevo = j;
            j_nuevo = tam_imagen - i;
            break;
        case MEDIA:
            i_nuevo = tam_imagen - i;
            j_nuevo = tam_imagen - j;
            break;
        case TRES_CUARTOS:
            i_nuevo = tam_imagen - j;
            j_nuevo = i;
            break;
        default:
            i_nuevo = i;
            j_nuevo = j;
    }

    Punto punto_rotado = Punto(i_nuevo, j_nuevo);
    return punto_rotado;
}

