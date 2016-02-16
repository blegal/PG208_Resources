#include <iostream>
#include <strings.h>
#include <assert.h>

#include "Matrix.hpp"
#include "SquareMatrix.hpp"
#include "IdMatrix.hpp"


int main(int argc, char* argv[]) {

    // TEST DES FONCTIONNALITES DE BASE

    SquareMatrix* m1 = new SquareMatrix( 3 );

    m1->show( );

    delete m1;

    // TEST DE L'ADDITION DE Matrix DE MEME RANG

    IdMatrix* m2 = new IdMatrix( 9 );

    m2->show( );

    delete m2;

    return 0;
}
