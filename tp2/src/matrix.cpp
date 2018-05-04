#include <assert.h>
#include "matrix.h"
float EPSILON = 0.001;

// constructor de una matrix de tamaño n llena de ceros

matrix::~matrix(){}

matrix::matrix(unsigned int filas,unsigned int columnas ) {

    matriz.resize(filas);
    for (unsigned int  i = 0; i < filas; i++) {
      matriz[i].resize(columnas);
    }
    for (size_t i = 0; i < filas; i++) {
      for (size_t j = 0; j < columnas; j++) {
        matriz[i][j] = 0;
      }
    }
    this->filas = filas;
    this->columnas = columnas;
}

  unsigned int matrix::dame_filas(){
    return this->filas;
}
  unsigned int matrix::dame_columnas(){
    return this->columnas;
}


// T tiene que llegar creada tiene que tener las dimensiones de la traspuesta de A e inicializada con 0
  void matrix::trasponer(matrix &T){
    for (size_t i = 0; i < filas; i++) {
      for (size_t j = 0; j < columnas; j++) {
        T.agregar_elemento(j,i,dame_elem_matrix(i,j));
      }
    }
}

  vector<float> matrix::vector_promedio(){
    vector<float> promedio;
    promedio.resize(dame_columnas());
    for (size_t i = 0; i < columnas; i++) {
      float sumatoria = 0;
      for (size_t j = 0; j < filas; j++) {
        sumatoria = sumatoria + dame_elem_matrix(j,i);
      }
      promedio[i] = sumatoria/dame_filas();
    }
    return promedio;
  }

  void matrix::resta_matrix_vector(vector<float> &v){
  for (size_t j = 0; j < dame_columnas(); j++) {
    for (size_t i = 0; i < dame_filas(); i++) {
      float elemento = dame_elem_matrix(i,j);
      agregar_elemento(i,j, elemento - v[j]);
    }
  }
}

  void matrix::division_escalar(unsigned int escalar){
    for (size_t i = 0; i < dame_filas(); i++) {
      for (size_t j = 0; j < dame_columnas(); j++) {
        float division = dame_elem_matrix(i,j)/escalar;
        agregar_elemento(i,j, division);
      }
    }
}

float producto_interno(matrix &A,matrix &B,unsigned int fila, unsigned int columna){
  float resultado = 0;
  for (size_t i = 0; i < A.dame_columnas(); i++) {
    resultado = resultado + A.dame_elem_matrix(fila,i)*B.dame_elem_matrix(i,columna);
  }
  return resultado;
}

void matrix::multiplicacion(matrix &A, matrix &B){
  for (size_t i = 0; i < this->dame_filas(); i++) {
    for (size_t j = 0; j < this->dame_columnas(); j++) {
      this->agregar_elemento(i,j,producto_interno(A, B, i, j));
    }
  }
}

void matrix::mostrar() {
    std::cout << '\n';
    for (unsigned int  i = 0; i < filas; i++) {
      for (unsigned int  j = 0; j < columnas; j++) {
        std::cout << dame_elem_matrix(i,j) << ' ';
      }
      std::cout << '\n';
    }
    std::cout << '\n';
}


float matrix::dame_elem_matrix(unsigned int fila, unsigned int columna) {
  return matriz[fila][columna];
}


void matrix::agregar_elemento(uint fila, uint columna, float elemento){
    matriz[fila][columna] = elemento;
}
