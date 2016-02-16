#ifndef SQUARE_MATRIX_HPP
#define SQUARE_MATRIX_HPP

#include "Matrix.hpp"

template<class T>
class SquareMatrix : public Matrix<T>{
public:
    SquareMatrix(const int d);
    SquareMatrix(const SquareMatrix* m);

    ~SquareMatrix();
};

#include "SquareMatrix.hxx"

#endif