
#include "mini_test.h"
#include <iostream>
#include <stdlib.h>
#include "entradaSalida.cpp"
#include "matriz.cpp"
#include <vector>
#include <string>

void print_vector(vector<float> vector);

void test_insertar() {
    /*matriz B(3);
    B.agregar_links(1, 1);
    B.agregar_links(2, 1);
    B.agregar_links(3, 1);
    B.agregar_links(1, 2);
    B.agregar_links(2, 2);
    B.agregar_links(3, 2);
    B.agregar_links(1, 3);
    B.agregar_links(2, 3);
    B.agregar_links(3, 3);

    vector<float> D;

    D.push_back(1);
    D.push_back(2);
    D.push_back(0);

    B.multiplicacion(D);

    B.mostrar();*/




    matriz L(3);
    matriz U(3);
    /*U.agregar_elemento(1, 1,4);
    U.agregar_elemento(2, 1,2);
    U.agregar_elemento(3, 1,1);
    U.agregar_elemento(1, 2,1);
    U.agregar_elemento(2, 2,3);
    U.agregar_elemento(3, 2,1);
    U.agregar_elemento(1, 3,1);
    U.agregar_elemento(2, 3,1);
    U.agregar_elemento(3, 3,3);*/

    U.agregar_elemento(1, 1,0);
    U.agregar_elemento(2, 1,1);
    U.agregar_elemento(3, 1,1);
    U.agregar_elemento(1, 2,1);
    U.agregar_elemento(2, 2,0);
    U.agregar_elemento(3, 2,1);
    U.agregar_elemento(1, 3,1);
    U.agregar_elemento(2, 3,1);
    U.agregar_elemento(3, 3,0);

    // U.mostrar();
    //
    // L.crear_identidad();
    //
    // L.mostrar();
    //
    // U.eliminacion_gausiana(L);
    //
    // U.mostrar();
    //
    // L.mostrar();
    //
    // std::cout << "lower" << '\n';
    // vector<float> solucion_lower = L.solucion_lower();
    // print_vector(solucion_lower);
    //
    //
    //
    // std::cout << "upper" << '\n';
    // vector<float> solucion_upper = U.solucion_upper(solucion_lower);
    // print_vector(solucion_upper);


    // U.multiplicacion_escalar(3);
    // U.restar_identidad();
    // U.mostrar();

    vector<float> Sumatoria = U.rankear(0.25);
    print_vector(Sumatoria);


}

























void print_vector(vector<float> vector) {
    for (float i : vector) {
        cout << i << ' ';
    }
    cout << "\n";
}

void test_cardinal() {

}

void test_remover() {


}

void test_maximo() {
    //Conjunto<int> c;
    // c.insertar(42);
    // ASSERT((c.cardinal() == 1));
    // ASSERT( c.pertenece(42) );
    // ASSERT( c.maximo() == 42)
    // c.insertar(39);
    // ASSERT(c.cardinal() == 2);
    // ASSERT( c.pertenece(39) );
    // ASSERT( c.maximo() == 42);
    // c.insertar(50);
    // ASSERT(c.cardinal() == 3);
    // ASSERT( c.pertenece(50) );
    // ASSERT( c.maximo() == 50);
}

void test_minimo() {
    // Conjunto<int> c;
    // c.insertar(42);
    // ASSERT((c.cardinal() == 1));
    // ASSERT( c.pertenece(42) );
    // ASSERT( c.minimo() == 42)
    // c.insertar(39);
    // ASSERT(c.cardinal() == 2);
    // ASSERT( c.pertenece(39) );
    // ASSERT( c.minimo() == 39);
    // c.insertar(50);
    // ASSERT(c.cardinal() == 3);
    // ASSERT( c.pertenece(50) );
    // ASSERT( c.minimo() == 39);

}

int main(int argc, char const *argv[]) {

    RUN_TEST(test_insertar);
    // RUN_TEST(test_cardinal);
    //RUN_TEST(test_remover);
    //RUN_TEST(test_maximo);
    //RUN_TEST(test_minimo);
    return 0;
}
