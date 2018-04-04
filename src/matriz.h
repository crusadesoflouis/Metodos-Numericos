#ifndef _matriz_h__
#define __matriz_h__

#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;
typedef unsigned int columna;
typedef float valor;
typedef float constante;
typedef map<columna,valor> link;

class matriz {
  public:
    matriz();
    matriz(int n);
    void agregar_links(int fila, int col);
    void rankear(int p);
    void multiplicacion(vector<link> &matriz_D);
    vector<link> restar(vector<link> matriz_B);
    vector<link> multiplicacion_escalar(vector<link> matriz_B);
    vector<link> eliminasion_gausiana();
    vector<float> buscar_solucion(vector<link> matriz_B);
    void mostrar(int,int);
    private:
      vector<link> links;
      int tamanio;
};

#endif
