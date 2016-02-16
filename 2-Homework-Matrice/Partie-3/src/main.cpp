#include <iostream>
#include <strings.h>
#include <assert.h>

#include "Matrix.hpp"
#include "SquareMatrix.hpp"
#include "IdMatrix.hpp"


int main(int argc, char* argv[]) {

    // TEST DES FONCTIONNALITES DE BASE

    SquareMatrix<float>* m1 = new SquareMatrix<float>( 3 );
    for(int x=0; x<m1->width(); x++){
        for(int y=0; y<m1->height(); y++){
        	float v = ((float)(rand()%100)) / (rand()%100);
            m1->set(x, y, v);
        }
    }

    m1->show( );

    delete m1;

    // TEST DE L'ADDITION DE Matrix DE MEME RANG

    IdMatrix<float>* m2 = new IdMatrix<float>( 9 );

    m2->show( );

    delete m2;

    return 0;
}
