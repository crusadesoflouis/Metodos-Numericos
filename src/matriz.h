#ifndef _matriz_h__
#define __matriz_h__

#include <iostream>
#include <list>
#include <tuple>
#include <vector>

using namespace std;

typedef int columna;
typedef float valor;
typedef tuple<columna,valor> info;
typedef list<info> link;

class matriz {
  public:
    matriz();
    matriz(int n);
    void agregar_links(int fila, int col);
    void rankear(int p);
    vector<link> multiplicacion(vector<link> matriz_B);
    vector<link> restar(vector<link> matriz_B);
    vector<link> multiplicacion_escalar(vector<link> matriz_B);
    vector<link> eliminasion_gausiana();
    vector<float> buscar_solucion(vector<link> matriz_B);
  private:
    vector<link> links;
    int tamanio;
};

#endif
