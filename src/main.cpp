#include <iostream>
#include "mini_test.h"

#include "matriz.h"

void test_insertar() {
    matriz B(3);
    B.agregar_links(1, 1);
    B.mostrar(1, 1);
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
