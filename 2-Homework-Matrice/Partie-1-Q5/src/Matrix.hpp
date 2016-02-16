#ifndef MATRIX_HPP
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
    Matrix(const int x, const int y);
    Matrix(const Matrix* m);

    ~Matrix();

    int width() const;

    int height() const;

    Matrix* clone() const;

    int get(const int x, const int y) const;

    void set(const int x, const int y, const int value);

    void show( ) const;

    void add(const int value);

    void sub(const int value);

    void mult(const int value);

    Matrix* add(const Matrix *m);

    Matrix* mult(const Matrix *m);

    void rotate90( );

    int min( ) const ;

    int max( ) const ;

    int sum( );

    int avg( );
};


// DEFINITION DES OPERATEURS SURCHARGES

std::ostream& operator<<(std::ostream& out, const Matrix& lhs);

bool operator==(const Matrix& lhs, const Matrix& rhs);
bool operator!=(const Matrix& lhs, const Matrix& rhs);

Matrix operator*(Matrix lhs, const Matrix& rhs);
Matrix operator+(Matrix lhs, const Matrix& rhs);
Matrix operator+(Matrix lhs, const int rhs);

#endif