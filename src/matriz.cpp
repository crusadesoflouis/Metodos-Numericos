#include "matriz.h"

matriz::matriz(){
}

matriz::matriz(int n){
	// links.resize(n);

for (uint i = 0; i < n; i++) {
	link A;
	links.push_back(A);
	}
}

vector<link> matriz::eliminasion_gausiana(){
	vector<link> A(tamanio);
	return A;
}

void matriz::rankear(int p){

}

void matriz::mostrar(int fila,int columna){
	// std::cout <<  links[fila-1].find(columna-1) << '\n';
}


void matriz::agregar_links(int fila, int col){
	links[fila-1].insert(col-1,1);
}

void matriz::multiplicacion(vector<link> &matriz_D){

}
vector<link> matriz::restar(vector<link> matriz_B){
	vector<link> A(tamanio);
	return A;
}
vector<link> matriz::multiplicacion_escalar(vector<link> matriz_B){
	vector<link> A(tamanio);
	return A;
}

vector<float> matriz::buscar_solucion(vector<link> matriz_B){

}
