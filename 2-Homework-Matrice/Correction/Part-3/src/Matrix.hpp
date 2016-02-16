#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <strings.h>
#include <assert.h>

using namespace std;

template<class T>
class Matrix{
private:
    T*   _array;
    int  _width;
    int  _height;

public:
    Matrix(const int x, const int y);
    Matrix(const Matrix* m);

    virtual ~Matrix();

    int width() const;

    int height() const;

    Matrix* clone() const;

    T get(const int x, const int y) const;

    void set(const int x, const int y, const T value);

    void show( ) const;

    void add(const T value);

    void sub(const T value);

    void mult(const T value);

    Matrix* add(const Matrix *m);

    Matrix* mult(const Matrix *m);

    void rotate90( );

    int min( ) const ;

    int max( ) const ;

    int sum( );

    int avg( );
};

#include "Matrix.hxx"

// DEFINITION DES OPERATEURS SURCHARGES

template<class T = int>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& lhs);

template<class T = int>
bool operator==(const Matrix<T>& lhs, const Matrix<T>& rhs);

template<class T = int>
bool operator!=(const Matrix<T>& lhs, const Matrix<T>& rhs);

template<class T = int>
Matrix<T> operator*(Matrix<T> lhs, const Matrix<T>& rhs);

template<class T = int>
Matrix<T> operator+(Matrix<T> lhs, const Matrix<T>& rhs);

template<class T = int>
Matrix<T> operator+(Matrix<T> lhs, const int rhs);

#endif