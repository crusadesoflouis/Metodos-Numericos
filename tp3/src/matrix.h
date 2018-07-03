#ifndef _matrix_h__

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <random>
#include <cassert>
#include <cstring>
#include "ppmloader.h"

using namespace std;

class matrix {
public:
    // funciones esenciales para poder manejarnos con las matrices
    ~matrix();

    matrix(unsigned int n, unsigned int m);

    matrix(string nombreArchivo);

    matrix(string matrizArchivo, string dimensionArchivo);

    void agregar_elemento(uint fila, uint columna, double elemento);

    double dame_elem_matrix(unsigned int fila, unsigned int columna);

    unsigned int dame_columnas();

    unsigned int dame_filas();

    vector<vector<double>> dameMatriz();

    // funciones que operan con matrices
    matrix trasponer();

    void multiplicacion(matrix &A, matrix &B);

    void restar(matrix &A);

    void suma(matrix &A);

    void multiplicacion_escalar(double escalar);

    void division_escalar(double escalar);

    int dame_rango();

    //reduciones de matrices y discretizaciones
    matrix discretizacion();

    matrix reducir_tamano();

    void pasar_vector_matriz(vector<double> &velocidades);

    void pasar_matriz_vector(matrix &imagen_ori);

    void vector_matriz(matrix &imagen_ori);

    // normas
    void normalizar_2();

    // funciones para diagonalizar una matriz
    double metodo_potencia(matrix &x, int repeticiones, matrix &autovector);

    void deflacion(matrix &autovector, double autovalor);

    void generacion_U_D(matrix &autovectores, matrix &autovalores, int alfa);

    void conversionUaV(matrix &U, matrix &D, matrix &V);

    void matriz_Sigma(matrix &D);

    // funciones complementarias
    bool verificacion(matrix autovector, double lambda);

    bool comparar(matrix &b);

    void absoluto();

    void rellenar_columna_con_vector(uint columna, matrix &V);

    matrix copiar_con_ruido(int tipo_ruido, double param1, double param2);

    //Cuadrados minimos
    void SCML(matrix &U, matrix &S, matrix &V, matrix &b);

    void Cuadrados_Minimos(matrix &b, matrix &res);

    double ECM(matrix &vel_discreta);

    // salida
    void mostrar();

    void guardarEnImagen(string nombreArchivo);

    void archivoCSV(string nombreArchivo);

private:
    vector<vector<double>> matriz;
    unsigned int filas;
    unsigned int columnas;
};

#endif
