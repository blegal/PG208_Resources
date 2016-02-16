#include "SquareMatrix.hpp"


SquareMatrix::SquareMatrix(const int d)
	: Matrix( d, d )
{

}


SquareMatrix::SquareMatrix(const SquareMatrix* m)
	: Matrix( m )
{

}


SquareMatrix::~SquareMatrix()
{

}

