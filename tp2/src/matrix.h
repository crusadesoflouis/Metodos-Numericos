#ifndef _matrix_h__

#include <iostream>
#include <vector>
#include <stdio.h>


using namespace std;
class matrix {
public:

    // Fila& operator[] (unsigned int  x) {
    //   return filas[x];
    // }

    ~matrix();

    matrix(unsigned int n,unsigned int m);
    unsigned int dame_filas();
    unsigned int dame_columnas();
    void agregar_elemento(uint fila, uint columna, float elemento);
    //
    // matrix(unsigned int n, link links[], int m);
    //
    // void agregar_links(unsigned int fila, unsigned int col);
    //
    // void agregar_elemento(unsigned int fila, unsigned int col, float valor);
    //
    // void crear_identidad();
    //
    // vector<float> suma_columnas();
    //
    // vector<float> suma_filas();
    //
    // vector<float> rankear(float p);
    //
    // void multiplicacion(vector<float> &matrix_D);
    //
    // void restar_identidad();
    //
    // void multiplicacion_escalar(float escalar);
    //
    // //L debe venir inicializada con unos en la diagonal
    // void eliminacion_gausiana(matrix &L);
    //
    // vector<float> buscar_solucion(vector<Fila> &matrix_B);
    //

    void mostrar();
    float dame_elem_matrix(unsigned int fila, unsigned int columna);
    void trasponer(matrix &T);

    vector<float> vector_promedio();
    // //funciones auxiliares
    //
    // vector<float> solucion_lower();
    //
    // vector<float> solucion_upper(vector<float> &y);

private:

    vector<vector <float> > matriz;
    unsigned int filas;
    unsigned int columnas;
    //
    // void resta_filas(Fila &A, Fila B, float consante);
    //
    // float dame_elem_por_fila(Fila &F, unsigned int c);
    //
    // Fila & dame_fila(unsigned int f);

};

#endif
