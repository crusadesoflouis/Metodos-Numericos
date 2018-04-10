#include "matriz.h"
#include <cmath>

float EPSILON = 0.0001;

// constructor de una matriz de tamaño n llena de ceros
matriz::matriz(unsigned int n) {
    filas.resize(n);
    tamanio = n;
    for (int i = 0; i < n; i++) {
        Fila fila;
        filas[i] = fila;
    }
}

// constructor de una matriz de tamaño n con unos en los indices de los links
matriz::matriz(unsigned int n, link links[], int m){
  tamanio = n;
  filas.resize(n);
  for (int i = 0; i < m; i++) {
    filas[get<0>(links[i])-1].insert(make_pair(get<1>(links[i])-1,1));
  }
}

// crea la matriz identidad
void matriz::crear_identidad() {
    for (unsigned int i = 1; i < tamanio + 1; i++) {
        agregar_links(i, i);
    }
}

// devuelve el elemento c de la fila f
float matriz::dame_elem_por_fila(Fila &F, unsigned int c) {
    std::map<Columna, Valor>::iterator it;
    it = F.find(c - 1);
    if (it != F.end()) {
        return it->second;
    } else {
        return 0;
    }
}

// combinacion lineal de las fila A y B. se modifica A. A <- A - constante*B
void matriz::resta_filas(Fila &A, Fila B, float constante) {
    //TODO: REFACTOR (no pasar filas, pasar indice de las filas).
    for (unsigned int i = 1; i <= tamanio; i++) {
        float elem_superior = dame_elem_por_fila(B, i);
        float elem_inferior = dame_elem_por_fila(A, i);
        float resultado = elem_inferior - (constante * elem_superior);

        if (resultado == 0) {
            A.erase(i - 1);
        } else if (elem_inferior != 0) {
            A.at(i - 1) = resultado;
        } else {
            pair<Columna, Valor> entry = make_pair(i, resultado);
            A.insert(entry);
        }
    }
}


void matriz::eliminacion_gausiana(matriz &L) {
    for (unsigned int j = 1; j <= tamanio - 1; j++) {
        for (unsigned int i = j + 1; i <= tamanio; i++) {
            // como la matriz es estrictamente diagonal dominante
            // nuestro a_j_j nunca va a ser cero
            float a_i_j = dame_elem_matriz(i, j);
            if (abs(a_i_j) > EPSILON){
              float a_j_j = dame_elem_matriz(j, j);
              float cociente = (a_i_j / a_j_j);
              L.agregar_elemento(i, j, cociente);
              //resta de diccionarios
              resta_filas(dame_fila(i), dame_fila(j), cociente);
            }
        }
        // std::cout << j << '\n';

    }
}

vector<float> matriz::solucion_lower() {
    vector<float> y;
    y.push_back(this->dame_elem_matriz(1, 1));
    for (unsigned int i = 2; i <= tamanio; i++) {
        float suma_parcial = 0;
        for (unsigned int j = 1; j <= y.size(); j++) {
            float elem_matriz = this->dame_elem_matriz(i, j);
            elem_matriz = elem_matriz * y[j - 1];
            suma_parcial = suma_parcial + elem_matriz;
        }

        y.push_back(1 - suma_parcial);
    }

    return y;
}

vector<float> matriz::solucion_upper(vector<float>& y) {
    vector<float> x;
    x.push_back(y[tamanio - 1]/this->dame_elem_matriz(tamanio, tamanio));
    for (unsigned int i = tamanio - 1; i >= 1; i--) {
        float suma_parcial = 0;
        for (unsigned int j = 1; j <= x.size(); j++) {
            float elem_matriz = this->dame_elem_matriz(i, i+j);
            elem_matriz = elem_matriz * x[x.size() - j];
            suma_parcial = suma_parcial + elem_matriz;
        }
        float resultado = (y[i-1] - suma_parcial)/this->dame_elem_matriz(i, i);
        x.push_back(resultado);
    }

    std::vector<float> reverse_x;
    for (unsigned int  i = 1; i <= tamanio; i++) {
      reverse_x.push_back(x[tamanio-i]);
    }
    return reverse_x;
}

Fila &matriz::dame_fila(unsigned int f) {
    return filas[f - 1];
}

vector<float> matriz::rankear(float p) {

  // calculo la matriz diagonal
  vector<float> D = suma_columnas();
  // hago W*D
  this->multiplicacion(D);
  // hago p*W*D
  this->multiplicacion_escalar(p);
  // hago p*W*D-I
  this->restar_identidad();
  // hago I-p*W*D
  this->multiplicacion_escalar(-1);
  // hago la matriz L y la U
  matriz L(tamanio);
  L.crear_identidad();
  this->eliminacion_gausiana(L);
  // resuelvo LU x = e
  vector<float> Y = L.solucion_lower();
  return this->solucion_upper(Y);
}

void matriz::mostrar() {
    std::cout << '\n';
    for (unsigned int i = 1; i <= tamanio; i++) {
        if (filas[i - 1].empty() == true) {
            for (unsigned int k = 1; k <= tamanio; k++) {
                std::cout << "0 ";
            }
            std::cout << '\n';
        } else {
            for (unsigned int j = 1; j <= tamanio; j++) {
                cout << dame_elem_matriz(i, j) << " ";
            }
            std::cout << '\n';
        }
    }
}


float matriz::dame_elem_matriz(unsigned int f, unsigned int c) {
    std::map<Columna, Valor>::iterator it;
    it = filas[f - 1].find(c - 1);
    if (it != filas[f - 1].end()) {
        return it->second;
    } else {
        return 0;
    }
}


void matriz::agregar_links(unsigned int fila, unsigned int col) {
    pair<Columna, Valor> entry = make_pair(col - 1, 1);
    filas[fila - 1].insert(entry);
}


void matriz::agregar_elemento(unsigned int fila, unsigned int col, float valor) {
    pair<Columna, Valor> entry = make_pair(col - 1, valor);
    filas[fila - 1].insert(entry);
}

void matriz::multiplicacion(vector<float> &matriz_D) {

    for (unsigned int i = 0; i < tamanio; i++) {
        for (unsigned int j = 0; j < tamanio; j++) {
            std::map<Columna, Valor>::iterator it = filas[j].find(i);
            if (it != filas[j].end()) {
                //la clave está en la matriz
                if (matriz_D[i] != 0) {
                    // El elemento de la diagonal es =! a cero
                    it->second = it->second * matriz_D[i];
                } else {
                    filas[j].erase(it);
                }
            }
        }
    }
}

void matriz::restar_identidad() {
  for (size_t i = 0; i < tamanio; i++) {
    map<Columna,Valor>::iterator it = filas[i].find(i);
    if(it != filas[i].end()){
      // si esta resto 1 al valor que encontre
      it->second -= 1;
    }else{
      // no esta, agrego un -1
      filas[i].insert(make_pair(i,-1));
    }
  }
}

void matriz::multiplicacion_escalar(float escalar) {
  for (size_t i = 0; i < tamanio; i++) {
    for (map<Columna,Valor>::iterator it=filas[i].begin(); it!=filas[i].end(); ++it) {
      it->second *= escalar;
    }
  }
}

vector<float>  matriz::suma_columnas() {
  vector<float> A;
  for (unsigned int  j = 0; j < tamanio; j++) {
    float sumatoria = 0;
    for (unsigned int  i = 0; i < tamanio; i++) {
      std::map<Columna,Valor>::iterator it;
      it = filas[i].find(j);
      if (it != filas[i].end())
        sumatoria = sumatoria  + it->second;
      }

      if (sumatoria !=0) {
        A.push_back(1/sumatoria);
      }
      else{
        A.push_back(0);
      }
  }
  return A;
}

vector<float> matriz::buscar_solucion(vector<Fila> &matriz_B) {
    vector<float> A(tamanio);
    return A;
}
