#ifndef ID_MATRIX_HPP
#define ID_MATRIX_HPP

#include "SquareMatrix.hpp"

class IdMatrix : public SquareMatrix{

public:
    IdMatrix(const int d);
    IdMatrix(const IdMatrix* m);

    ~IdMatrix();
};

#endif