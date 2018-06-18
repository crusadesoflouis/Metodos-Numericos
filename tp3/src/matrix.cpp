#include <assert.h>
#include <cmath>
#include "matrix.h"
#include <random>
float EPSILON = 0.00001;

random_device randomDevice;
mt19937 generator(randomDevice());
uniform_real_distribution<float> distribution(-100,100);

//funciones auxiliares



float norma_euclidea_cuadrada(matrix &A, matrix &B) {
  matrix R(1, 1);
  R.multiplicacion(A, B);
  return R.dame_elem_matrix(0, 0);
}

float norma_2(matrix& A) {
  assert(A.dame_columnas() == 1);
  float sumatoria = 0;
  for (size_t i = 0; i < A.dame_filas(); i++) {
    sumatoria = sumatoria + pow(A.dame_elem_matrix(i,0),2);
  }
  return sqrt(sumatoria);
}

matrix crear_canonico(uint filas,uint i){
 matrix a(filas,1);
 a.agregar_elemento(i,0,1);
 return a;
}

float matrix::metodo_potencia(matrix &x, int repeticiones, matrix &autovector) {
  matrix v = x;
  unsigned int i = 0;
  float autovalor = 0;
  do{

    autovector.multiplicacion((*this), v);
    autovector.normalizar_2();
    v = autovector;

	matrix transpuesta_v = v.trasponer();
 	float norma_cuadrada = norma_euclidea_cuadrada(transpuesta_v, v);

	matrix C((*this).dame_filas(), 1);
	C.multiplicacion((*this), v);
  	matrix D(1, 1);
  	D.multiplicacion(transpuesta_v, C);

  	autovector = v;

	D.division_escalar(norma_cuadrada);
	autovalor = D.dame_elem_matrix(0, 0);
    ++i;
  }while (i < repeticiones && !verificacion(autovector,autovalor));

  return autovalor;
}

// constructor de una matrix de tamaño n llena de ceros

matrix::~matrix() {}

matrix::matrix(unsigned int filas, unsigned int columnas) {

  matriz.resize(filas);
  for (unsigned int i = 0; i < filas; i++) {
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

matrix::matrix(vector<imagen> imgs){
  columnas = imgs[0].tamanio(); // asumo que todas las imagenes tienen el mismo tamaño
  filas = imgs.size();
  matriz.resize(imgs.size());
  for (size_t i = 0; i < imgs.size(); i++) {
    vector<float> actual = imgs[i].data();
    for (size_t j = 0; j < imgs[0].tamanio(); j++) {
      matriz[i].push_back((float)actual[j]);
    }
  }
}

unsigned int matrix::dame_filas() {
  return this->filas;
}

unsigned int matrix::dame_columnas() {
  return this->columnas;
}

matrix matrix::trasponer() {
  matrix traspuesta = matrix(this->columnas,this->filas);
  for (size_t i = 0; i < filas; i++) {
    for (size_t j = 0; j < columnas; j++) {
      traspuesta.agregar_elemento(j, i, dame_elem_matrix(i, j));
    }
  }
  return traspuesta;
}


void matrix::division_escalar(float escalar) {
  //cout << escalar << "\n";
  //assert(abs(escalar) > EPSILON);
  for (size_t i = 0; i < dame_filas(); i++) {
    for (size_t j = 0; j < dame_columnas(); j++) {
      float division = dame_elem_matrix(i, j) / escalar;
      agregar_elemento(i, j, division);
    }
  }
}


void matrix::multiplicacion_escalar(float escalar) {
  //cout << escalar << "\n";
  //assert(abs(escalar) > EPSILON);
  for (size_t i = 0; i < dame_filas(); i++) {
    for (size_t j = 0; j < dame_columnas(); j++) {
      float division = dame_elem_matrix(i, j) * escalar;
      agregar_elemento(i, j, division);
    }
  }
}

float producto_interno(matrix &A, matrix &B, unsigned int fila, unsigned int columna) {
  float resultado = 0;
  for (size_t i = 0; i < A.dame_columnas(); i++) {
    resultado = resultado + A.dame_elem_matrix(fila, i) * B.dame_elem_matrix(i, columna);
  }
  return resultado;
}

void matrix::multiplicacion(matrix &A, matrix &B) {
  assert(A.dame_columnas() == B.dame_filas());
  for (size_t i = 0; i < this->dame_filas(); i++) {
    for (size_t j = 0; j < this->dame_columnas(); j++) {
      this->agregar_elemento(i, j, producto_interno(A, B, i, j));
    }
  }
}

void matrix::mostrar() {
  std::cout << '\n';
  for (unsigned int i = 0; i < filas; i++) {
    for (unsigned int j = 0; j < columnas; j++) {
      std::cout << dame_elem_matrix(i, j) << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

float matrix::dame_elem_matrix(unsigned int fila, unsigned int columna) {
  return matriz[fila][columna];
}


void matrix::agregar_elemento(uint fila, uint columna, float elemento) {
  if (abs(elemento) < EPSILON) {
    matriz[fila][columna] = 0;
  } else {
    matriz[fila][columna] = elemento;
  }
}


void matrix::normalizar_2() {
  assert(columnas == 1);
  float norma = norma_2(*this);
  division_escalar(norma);
}

bool matrix::verificacion(matrix autovector, float autovalor){
  matrix a(autovector.dame_filas(),1);
  a.multiplicacion((*this),autovector),
  autovector.multiplicacion_escalar(autovalor);
  return autovector.comparar(a);
}

bool matrix::comparar(matrix& b){
  matrix a(*this);
  a.restar(b);
  a.absoluto();
  for (size_t i = 0; i < a.dame_filas(); i++) {
    for (size_t j = 0; j < a.dame_columnas(); j++) {
      float elemento = a.dame_elem_matrix(i,j);
      if (elemento >= EPSILON) {
        return false;
      }
    }
  }
  return true;
}

void matrix::restar(matrix&A){
  assert(dame_filas() == A.dame_filas());
  assert(dame_columnas() == A.dame_columnas());
  for (size_t i = 0; i < dame_filas(); i++) {
    for (size_t j = 0; j < dame_columnas(); j++) {
      float elemento = A.dame_elem_matrix(i, j);
      elemento = dame_elem_matrix(i, j) - elemento;
      agregar_elemento(i, j, elemento);
    }
  }
}

void matrix::absoluto(){
  for (size_t i = 0; i < dame_filas(); i++) {
    for (size_t j = 0; j < dame_columnas(); j++) {
      float elemento = abs(dame_elem_matrix(i, j));
      agregar_elemento(i, j, elemento);
    }
  }
}

void matrix::deflacion(matrix &autovector, float autovalor){
  autovector.normalizar_2();
  matrix autovector_traspuesto = autovector.trasponer();
  matrix B(dame_filas(),dame_columnas());
  B.multiplicacion(autovector,autovector_traspuesto);
  B.multiplicacion_escalar(autovalor);
  restar(B);
}


void matrix::generacion_U_D(matrix& U,matrix& D, int alfa){
  assert(dame_filas() == dame_columnas());
  assert(dame_filas() == U.dame_columnas());
  assert(U.dame_filas() == U.dame_columnas());
  assert(D.dame_filas() == D.dame_columnas());
  assert(D.dame_filas() == U.dame_columnas());

  matrix autovector(dame_filas(),1);
  matrix x_0(dame_filas(),1);
  for (size_t i = 0; i < alfa; i++) {
    float autovalor = 0;
    //genera vector random
    // TODO: hacer un vector inicial con la media de la matriz
    for (size_t j = 0; j < x_0.dame_filas(); j++) {
	    x_0.agregar_elemento(j,0,rand()%100+1);
    }
    x_0.normalizar_2();

    autovalor = this->metodo_potencia(x_0,500,autovector);

    //si no son parecidos, cambiamos la semilla del vector
    //hacer deflacion

    U.rellenar_columna_con_vector(i, autovector);
    D.agregar_elemento(i, i, autovalor);
    this->deflacion(autovector,autovalor);
  }
}

void matrix::rellenar_columna_con_vector(uint columna, matrix& V){
  //asume que X (this) viene ya traspuesto
  V.normalizar_2();
  assert(V.dame_columnas() == 1);
  assert(V.dame_filas() == dame_filas());
  for (size_t i = 0; i < dame_filas(); i++) {
    agregar_elemento(i, columna, V.dame_elem_matrix(i, 0));
  }
}
//devuelve una matrix de nxm
void matrix::conversionUaV(matrix& U,matrix &D,matrix &V) {
  for (size_t i = 0; i < V.dame_columnas(); i++) {
    matrix  e_i = crear_canonico(U.dame_filas(),i);
    // e_i.mostrar();
    matrix u_i(U.dame_filas(),1);
    u_i.multiplicacion(U,e_i);
    // u_i.mostrar();
    // D.mostrar();
    float d_i_i = sqrt(abs(D.dame_elem_matrix(i,i)));
    // std::cout << "d " << d_i_i<<'\n';
    // mostrar();
    matrix v_i(dame_filas(),1);
    v_i.multiplicacion((*this),u_i);
    // v_i.mostrar();
    v_i.division_escalar(d_i_i);
    //v_i.normalizar_2();
    V.rellenar_columna_con_vector(i,v_i);
  }
}

vector<vector<float>> matrix::dameMatriz(){
  return matriz;
}