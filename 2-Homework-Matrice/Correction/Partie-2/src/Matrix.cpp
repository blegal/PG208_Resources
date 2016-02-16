#include "Matrix.hpp"


Matrix::Matrix(const int x, const int y)
{
	assert( x != 0 );
	assert( y != 0 );

	_array  = new int[x * y];
	bzero(_array, x * y * sizeof(int));
	_width  = x;
	_height = y;
}


Matrix::Matrix(const Matrix* m)
{
	_array  = new int[m->width() * m->height()];
	_width  = m->width ();
	_height = m->height();

        // ON COPIE LES DONNEES
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			set(x, y, m->get(x, y));
		}            
	}
}


Matrix::~Matrix()
{
	delete[] _array;
}


int Matrix::width() const 
{
	return _width;
}


int Matrix::height() const 
{
	return _height;
}


Matrix* Matrix::clone() const
{
	return new Matrix(this);
}


int Matrix::get(const int x, const int y) const 
{
	assert( x < width () );
	assert( y < height() );
	return _array[y * width() + x];
}


void Matrix::set(const int x, const int y, const int value)
{
	assert( x < width () );
	assert( y < height() );
	_array[y * width() + x] = value;
}


void Matrix::show( ) const 
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


void Matrix::add(const int value)
{
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			set(x, y, get(x, y) + value);
		}            
	}
}


void Matrix::sub(const int value)
{
	add( -value );
}


void Matrix::mult(const int value)
{
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			set(x, y, get(x, y) * value);
		}            
	}
}


Matrix* Matrix::add(const Matrix *m)
{
	assert( width()  == m->width()  );
	assert( height() == m->height() );

	Matrix* r = new Matrix(width(), height());

	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			r->set(x, y, get(x,y) + m->get(x,y));
		}            
	}

	return r;
}


Matrix* Matrix::mult(const Matrix *m)
{
	assert( height() == m->width() );

	Matrix* r = new Matrix(m->width(), height());

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


void Matrix::rotate90( )
{
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width()/2; x++){
			int tmp = get(x, y);
			set(x,         y,   get(x, width()-y-1));
			set(x, width()-y-1, tmp);
		}            
	}
}


int Matrix::min( ) const 
{
	int mini = +100000000;
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			mini = mini < get(x, y) ? mini : get(x, y);
		}            
	}
	return mini;
}


int Matrix::max( ) const 
{
	int maxi = -100000000;
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			maxi = maxi > get(x, y) ? maxi : get(x, y);
		}            
	}
	return maxi;
}


int Matrix::sum( )
{
	int sums = 0;
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			sums += get(x, y);
		}            
	}
	return sums;
}


int Matrix::avg( )
{
	return sum( ) / (width() * height());
}


bool operator==(const Matrix& lhs, const Matrix& rhs)
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


std::ostream& operator<<(std::ostream& out, const Matrix& lhs)
{
	return out << lhs.width() << 'x' << lhs.height() ;
}


bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
	return !(lhs == rhs);
}


Matrix operator*(Matrix lhs, const Matrix& rhs)
{
	return lhs.mult( &rhs );
}


Matrix operator+(Matrix lhs, const Matrix& rhs)
{
	return lhs.add( &rhs );
}


Matrix operator+(Matrix lhs, const int rhs)
{
	lhs.mult( rhs );
	return lhs;
}
