#ifndef _matrix_h__

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
using namespace std;
class matrix {
public:
    // funciones esenciales para poder manejarnos con las matrices
    ~matrix();
    matrix(unsigned int n,unsigned int m);
    matrix(char* nombreArchivo);
    //matrix(vector<imagen> imagenes);
    void agregar_elemento(uint fila, uint columna, float elemento);
    float dame_elem_matrix(unsigned int fila, unsigned int columna);
    unsigned int dame_columnas();
    unsigned int dame_filas();
    vector<vector<float>> dameMatriz();
    // funciones que operan con matrices
    matrix trasponer();
    void multiplicacion(matrix &A,matrix &B);
    void restar(matrix&A);
    void suma(matrix&A);
    void multiplicacion_escalar(float escalar);
    void division_escalar(float escalar);
    int dame_rango();
    // normas
    void normalizar_2();
    // funciones para diagonalizar una matriz
    float metodo_potencia(matrix &x, int repeticiones, matrix &autovector);
    void deflacion(matrix &autovector, float autovalor);
    void generacion_U_D(matrix& autovectores,matrix& autovalores, int alfa);
    void conversionUaV(matrix& U,matrix &D,matrix &V);
    void matriz_Sigma(matrix &D); 
    // funciones complementarias
    bool verificacion(matrix autovector, float lambda);
    bool comparar(matrix &b);
    void absoluto();
    void rellenar_columna_con_vector(uint columna, matrix& V);
    //Cuadrados minimos
    void SCML(matrix& U,matrix &S,matrix &V,matrix &b);
    //nos sirve para poder ver las matrices
    void mostrar();
private:
    vector<vector <float> > matriz;
    unsigned int filas;
    unsigned int columnas;
};

#endif
