#ifndef _matriz_h__

#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;
typedef unsigned int Columna;
typedef float Valor;
typedef float Constante;
typedef map<Columna, Valor> Fila;

class matriz {
public:
    matriz();

    matriz(unsigned int n);

    void agregar_links(unsigned int fila, unsigned int col);

    void rankear(unsigned int p);

    void multiplicacion(vector<Fila> &matriz_D);

    vector<Fila> restar(vector<Fila> &matriz_B);

    vector<Fila> multiplicacion_escalar(vector<Fila> &matriz_B);

    vector<Fila> eliminacion_gausiana();

    vector<float> buscar_solucion(vector<Fila> &matriz_B);

    void mostrar(unsigned int, unsigned int);

private:
    vector<Fila> filas;
    int tamanio;
};

#endif
