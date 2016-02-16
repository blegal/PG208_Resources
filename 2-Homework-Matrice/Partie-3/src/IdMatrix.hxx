#include "IdMatrix.hpp"


template<class T>
IdMatrix<T>::IdMatrix(const int d)
	: SquareMatrix<T>( d )
{
	for(int p = 0; p < this->width(); p++){
		this->set(p, p, 1);
	}            
}


template<class T>
IdMatrix<T>::IdMatrix(const IdMatrix* m)
	: SquareMatrix<T>( m )
{

}


template<class T>
IdMatrix<T>::~IdMatrix()
{

}
