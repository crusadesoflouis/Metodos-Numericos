#ifndef _matriz_h__

#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <utility>

using namespace std;
typedef unsigned int Columna;
typedef float Valor;
typedef float Constante;
typedef map<Columna, Valor> Fila;

class matriz {
public:

    // Fila& operator[] (unsigned int  x) {
    //   return filas[x];
    // }


    matriz(unsigned int n);

    void agregar_links(unsigned int fila, unsigned int col);

    void agregar_elemento(unsigned int fila, unsigned int col, float valor);

    void crear_identidad();


    void rankear(unsigned int p);

    void multiplicacion(vector<float> &matriz_D);

    vector<Fila> restar_identidad(vector<Fila> &matriz_B);

    vector<Fila> multiplicacion_escalar(vector<Fila> &matriz_B);

    //L debe venir inicializada con unos en la diagonal
    void eliminacion_gausiana(matriz &L);

    vector<float> buscar_solucion(vector<Fila> &matriz_B);


    void mostrar();

    float dame_elem_matriz(unsigned int f, unsigned int c);
    //funciones auxiliares


    vector<float> solucion_lower(matriz &L);

    vector<float> solucion_lower();

    vector<float> solucion_upper(vector<float> &y);

private:
    vector<Fila> filas;
    unsigned int tamanio;

    void resta_filas(Fila &A, Fila B, float consante);

    float dame_elem_por_fila(Fila &F, unsigned int c);

    Fila & dame_fila(unsigned int f);

};

#endif
