#include "SquareMatrix.hpp"


template<class T>
SquareMatrix<T>::SquareMatrix(const int d)
	: Matrix<T>( d, d )
{

}


template<class T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix* m)
	: Matrix<T>( m )
{

}


template<class T>
SquareMatrix<T>::~SquareMatrix()
{

}
