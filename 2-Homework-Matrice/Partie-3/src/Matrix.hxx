#include "Matrix.hpp"


template<class T>
Matrix<T>::Matrix(const int x, const int y)
{
	assert( x != 0 );
	assert( y != 0 );

	_array  = new T[x * y];
	bzero(_array, x * y * sizeof(T));
	_width  = x;
	_height = y;
}


template<class T>
Matrix<T>::Matrix(const Matrix* m)
{
	_array  = new T[m->width() * m->height()];
	_width  = m->width ();
	_height = m->height();

        // ON COPIE LES DONNEES
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			set(x, y, m->get(x, y));
		}            
	}
}


template<class T>
Matrix<T>::~Matrix()
{
	delete[] _array;
}


template<class T>
int Matrix<T>::width() const 
{
	return _width;
}


template<class T>
int Matrix<T>::height() const 
{
	return _height;
}


template<class T>
Matrix<T>* Matrix<T>::clone() const
{
	return new Matrix<T>(this);
}


template<class T>
T Matrix<T>::get(const int x, const int y) const 
{
	assert( x < width () );
	assert( y < height() );
	return _array[y * width() + x];
}


template<class T>
void Matrix<T>::set(const int x, const int y, const T value)
{
	assert( x < width () );
	assert( y < height() );
	_array[y * width() + x] = value;
}


template<class T>
void Matrix<T>::show( ) const 
{
	cout << "Matrix " << width() << " x " << height() << endl;
	for(int y = 0; y < height(); y++){
		cout << y << " [";
		for(int x = 0; x < width(); x++){
			cout.width (4);
			cout << get(x, y) << ((x!=width()-1)?" ":"");
		}            
		cout << "]" << endl;
	}
	cout << endl;
}


template<class T>
void Matrix<T>::add(const T value)
{
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			set(x, y, get(x, y) + value);
		}            
	}
}


template<class T>
void Matrix<T>::sub(const T value)
{
	add( -value );
}


template<class T>
void Matrix<T>::mult(const T value)
{
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			set(x, y, get(x, y) * value);
		}            
	}
}


template<class T>
Matrix<T>* Matrix<T>::add(const Matrix *m)
{
	assert( width()  == m->width()  );
	assert( height() == m->height() );

	Matrix<T>* r = new Matrix<T>(width(), height());

	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			r->set(x, y, get(x,y) + m->get(x,y));
		}            
	}

	return r;
}


template<class T>
Matrix<T>* Matrix<T>::mult(const Matrix *m)
{
	assert( height() == m->width() );

	Matrix<T>* r = new Matrix<T>(m->width(), height());

	for(int y = 0; y < r->height(); y++){
		for(int x = 0; x < r->width(); x++){
			int sum = 0;
			for(int z = 0; z < width(); z++){
				sum += get(z,y) * m->get(x,z);
			}
			r->set(x, y, sum);
		}
	}

	return r;
}


template<class T>
void Matrix<T>::rotate90( )
{
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width()/2; x++){
			int tmp = get(x, y);
			set(x,         y,   get(x, width()-y-1));
			set(x, width()-y-1, tmp);
		}            
	}
}


template<class T>
int Matrix<T>::min( ) const 
{
	int mini = +100000000;
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			mini = mini < get(x, y) ? mini : get(x, y);
		}            
	}
	return mini;
}


template<class T>
int Matrix<T>::max( ) const 
{
	int maxi = -100000000;
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			maxi = maxi > get(x, y) ? maxi : get(x, y);
		}            
	}
	return maxi;
}


template<class T>
int Matrix<T>::sum( )
{
	int sums = 0;
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			sums += get(x, y);
		}            
	}
	return sums;
}


template<class T>
int Matrix<T>::avg( )
{
	return sum( ) / (width() * height());
}


template<class T>
bool operator==(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
	if( lhs.width () == rhs.width () ) return false;
	if( lhs.height() == rhs.height() ) return false;
	for(int y = 0; y < lhs.height(); y++){
		for(int x = 0; x < lhs.width(); x++){
			if( lhs.get(x, y) == rhs.get(x, y) ){
				return false;
			}
		}
	}
	return true;
}


template<class T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& lhs)
{
	return out << lhs.width() << 'x' << lhs.height() ;
}


template<class T>
bool operator!=(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
	return !(lhs == rhs);
}


template<class T>
Matrix<T> operator*(Matrix<T> lhs, const Matrix<T>& rhs)
{
	return lhs.mult( &rhs );
}


template<class T>
Matrix<T> operator+(Matrix<T> lhs, const Matrix<T>& rhs)
{
	return lhs.add( &rhs );
}


template<class T>
Matrix<T> operator+(Matrix<T> lhs, const int rhs)
{
	lhs.mult( rhs );
	return lhs;
}
