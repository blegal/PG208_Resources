#include <iostream>
#include <strings.h>
#include <assert.h>
#include "Matrix.hpp"


int main(int argc, char* argv[]) {

    // TEST DES FONCTIONNALITES DE BASE

    Matrix* m1 = new Matrix(3, 2);

    for(int x=0; x<m1->width(); x++){
        for(int y=0; y<m1->height(); y++){
            m1->set(x, y, rand()%10);
        }
    }

    cout << *m1 << endl;

    m1->show( );

    m1->add( 2 );
    
    m1->show( );

    m1->add( -2 );
    
    m1->show( );

    m1->mult( -1 );
    
    m1->show( );

    // TEST DE L'ADDITION DE Matrix DE MEME RANG

    Matrix* m2 = new Matrix(3, 2);

    for(int x=0; x<m2->width(); x++){
        for(int y=0; y<m2->height(); y++){
            m2->set(x, y, rand()%10);
        }
    }

    m2->show( );

    Matrix* m3 = m1->add( m2 );

    m3->show( );

    delete m2;
    delete m3;

    // TEST DE LA MULTPLICATION DE Matrix

    Matrix* m4 = new Matrix(2, 3);

    for(int x=0; x<m4->width(); x++){
        for(int y=0; y<m4->height(); y++){
            m4->set(x, y, rand()%10);
        }
    }

    m1->show( );
    m4->show( );

    Matrix* m5 = m1->mult( m4 );

    m5->show( );

    delete m1;
    delete m4;
    delete m5;

    return 0;
}
