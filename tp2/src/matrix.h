#ifndef _matrix_h__

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
using namespace std;
class matrix {
public:
    // Fila& operator[] (unsigned int  x) {
    //   return filas[x];
    // }
    ~matrix();
    matrix(unsigned int n,unsigned int m);
    matrix(imagen i);
    void agregar_elemento(uint fila, uint columna, float elemento);
    void mostrar();
    matrix trasponer();
    void resta_matrix_vector(vector<float> &v);
    void multiplicacion_escalar(float escalar);
    void division_escalar(float escalar);
    void multiplicacion(matrix &A,matrix &B);
    unsigned int dame_filas();
    unsigned int dame_columnas();
    float dame_elem_matrix(unsigned int fila, unsigned int columna);
    vector<float> vector_promedio();
    void normalizar();
    void normalizar_2();
    float metodo_potencia(matrix &x, int repeticiones, matrix &autovector);
    void generacion_U_D(matrix& autovectores,matrix& autovalores);
    bool verificacion(matrix autovector, float lambda);
    void restar(matrix&A);
    void absoluto();
    void conversionUaV(matrix& U,matrix &D,matrix &V);
    bool comparar(matrix &b);
    void rellenar_columna_con_vector(uint columna, matrix& V);
    void deflacion(matrix &autovector, float autovalor);
private:
    vector<vector <float> > matriz;
    unsigned int filas;
    unsigned int columnas;
};

#endif
