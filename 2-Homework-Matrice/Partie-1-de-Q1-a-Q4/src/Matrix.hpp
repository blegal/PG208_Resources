#ifndef  MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <strings.h>
#include <assert.h>

using namespace std;

class Matrix{
private:
    int* _array;
    int  _width;
    int _height;

public:
    Matrix(int x, int y);
    ~Matrix();

    int width ();
    int height();

    int  get(int x, int y);
    void set(int x, int y, int value);

    void show( );

    void add(int value);
    void sub(int value);
    void mult(int value);

    Matrix* add(Matrix *m);
    Matrix* mult(Matrix *m);
};

#endif