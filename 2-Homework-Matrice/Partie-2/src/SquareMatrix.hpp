#ifndef SQUARE_MATRIX_HPP
#define SQUARE_MATRIX_HPP

#include "Matrix.hpp"

class SquareMatrix : public Matrix{
public:
    SquareMatrix(const int d);
    SquareMatrix(const SquareMatrix* m);

    ~SquareMatrix();
};

#endif