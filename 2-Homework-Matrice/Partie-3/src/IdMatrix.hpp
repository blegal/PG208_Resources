#ifndef ID_MATRIX_HPP
#define ID_MATRIX_HPP

#include "SquareMatrix.hpp"

template<class T>
class IdMatrix : public SquareMatrix<T>{

public:
    IdMatrix(const int d);
    IdMatrix(const IdMatrix* m);

    ~IdMatrix();
};

#include "IdMatrix.hxx"

#endif