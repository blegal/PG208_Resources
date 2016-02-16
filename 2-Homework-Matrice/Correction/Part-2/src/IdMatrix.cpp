#include "IdMatrix.hpp"


IdMatrix::IdMatrix(const int d)
	: SquareMatrix( d )
{
	for(int p = 0; p < width(); p++){
		set(p, p, 1);
	}            
}


IdMatrix::IdMatrix(const IdMatrix* m)
	: SquareMatrix( m )
{

}


IdMatrix::~IdMatrix()
{

}
