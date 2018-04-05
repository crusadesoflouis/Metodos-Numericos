#include "matriz.h"



matriz::matriz(unsigned int n) {
    filas.resize(n);
    tamanio = n;
    for (int i = 0; i < n; i++) {
        Fila fila;
        filas[i] = fila;
    }
}




void matriz::crear_identidad() {
  for (unsigned int  i = 1; i < tamanio+1; i++) {
    agregar_links(i,i);
  }
}

float matriz::dame_elem_por_fila(Fila& F,unsigned int c){
  std::map<Columna ,Valor>::iterator it;
   it = F.find(c);
   if (it != F.end()) {
     return it->second;
   }
  else{
       return 0;
  }
}

void matriz::resta_filas(Fila& A ,Fila B,float consante) {

   for (unsigned int i = 0; i < A.size(); i++) {
     float elem_inferior = dame_elem_por_fila(A,i);
     float elem_superior = dame_elem_por_fila(B,i);
     elem_inferior = elem_inferior - (consante*elem_superior);
     if (elem_inferior == 0) {
       pair<Columna, Valor> entry = make_pair(i,elem_inferior);
       A.insert(entry);
     }
     else{
       A.at(i) = elem_inferior;
     }
   }
}


void matriz::eliminacion_gausiana(matriz &L) {

  for (unsigned int  j = 1; j < tamanio-1; j++) {
    for (unsigned int  i = j+1; i < tamanio; i++) {
      // como la matriz es estrictamente diagonal dominante
      // nuestro a_j_j nunca va a ser cero
      float a_i_j = dame_elem_matriz(i,j);
      float a_j_j = dame_elem_matriz(j,j);
      float cociente = (a_i_j/a_j_j);
      L.agregar_elemento(i,j,cociente);
      //resta de diccionarios
      resta_filas(filas[j],filas[i],cociente);
    }
  }



}

void matriz::rankear(unsigned int p) {
}

void matriz::mostrar() {
  std::cout << '\n';
    for (unsigned int  i = 0; i < tamanio; i++) {
      if (filas[i].empty() == true) {
        for (unsigned int  k = 0; k < tamanio; k++) {
          std::cout << "0 ";
        }
      std::cout << '\n';
      }
      else{
        for (unsigned int j = 0; j < tamanio; j++) {
        cout << dame_elem_matriz(i,j) << " ";
        }
        std::cout << '\n';
    }
  }
}




    float matriz::dame_elem_matriz(unsigned int f, unsigned int c){
      std::map<Columna ,Valor>::iterator it;
       it = filas[f].find(c);
       if (it != filas[f].end()) {
         return it->second;
       }
      else{
           return 0;
      }
    }


void matriz::agregar_links(unsigned int fila, unsigned int col) {
    pair<Columna, Valor> entry = make_pair(col - 1, 1);
    filas[fila - 1].insert(entry);
}


void matriz::agregar_elemento(unsigned int fila, unsigned int col,float valor) {
    pair<Columna, Valor> entry = make_pair(col - 1,valor);
    filas[fila - 1].insert(entry);
}

void matriz::multiplicacion(vector<float> &matriz_D) {

  for (unsigned int  i = 0; i < tamanio; i++) {
      for (unsigned int  j = 0; j < tamanio; j++) {
         std::map<Columna,Valor>::iterator it = filas[j].find(i);
         if (it != filas[j].end()){
           //la clave está en la matriz
           if (matriz_D[i] != 0) {
             // El elemento de la diagonal es =! a cero
             it->second = it->second*matriz_D[i];
           }
           else{
             filas[j].erase(it);
           }
         }
      }
  }
}

vector<Fila> matriz::restar_identidad(vector<Fila> &matriz_B) {
    vector<Fila> A(tamanio);
    return A;
}

vector<Fila> matriz::multiplicacion_escalar(vector<Fila> &matriz_B) {
    vector<Fila> A(tamanio);
    return A;
}

vector<float> matriz::buscar_solucion(vector<Fila> &matriz_B) {
    vector<float> A(tamanio);
    return A;
}
