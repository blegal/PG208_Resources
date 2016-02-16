#include "Matrix.hpp"


Matrix::Matrix(int x, int y)
{
	assert( x != 0 );
	assert( y != 0 );

	_array  = new int[x * y];
	bzero(_array, x * y * sizeof(int));
	_width  = x;
	_height = y;
}


Matrix::~Matrix()
{
	delete[] _array;
}


int Matrix::width()
{
	return _width;
}


int Matrix::height()
{
	return _height;
}


int Matrix::get(int x, int y)
{
	assert( x < width () );
	assert( y < height() );
	return _array[y * width() + x];
}


void Matrix::set(int x, int y, int value)
{
	assert( x < width () );
	assert( y < height() );
	_array[y * width() + x] = value;
}


void Matrix::show( )
{
	cout << "Matrix " << width() << " x " << height() << endl;
	for(int y = 0; y < height(); y++){
		cout << y << " [";
			for(int x = 0; x < width(); x++){
				cout << get(x, y) << ((x!=width()-1)?" ":"");
			}            
			cout << "]" << endl;
}
cout << endl;
}


void Matrix::add(int value)
{
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			set(x, y, get(x, y) + value);
		}            
	}
}


void Matrix::sub(int value)
{
	add( -value );
}


void Matrix::mult(int value)
{
	for(int y = 0; y < height(); y++){
		for(int x = 0; x < width(); x++){
			set(x, y, get(x, y) * value);
		}            
	}
}


Matrix* Matrix::add(Matrix *m)
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


Matrix* Matrix::mult(Matrix *m)
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

