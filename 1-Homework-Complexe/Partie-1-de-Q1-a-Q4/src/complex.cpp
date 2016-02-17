#include "complex.hpp"


Complex::Complex()
{
	a = 0.0f;
	b = 0.0f;
}


Complex::Complex(double _a, double _b)
{
	a = _a;
	b = _b;
}


double Complex::Re()
{
	return a;
}


double Complex::Im()
{
	return b;
}


void Complex::show( )
{
	std::cout << a << " + " << b << ".i";// << std::endl;
}


void Complex::add ( double v )
{
	a += v;
}


void Complex::sub ( double v )
{
	add( -v );
}


void Complex::mult( double v )
{
	a *= v;
}


void Complex::add ( Complex* c )
{
	a += c->Re();
	b += c->Im();
}


void Complex::sub ( Complex* c )
{
	a -= c->Re();
	b -= c->Im();
}


void Complex::mult( Complex* c )
{
	double v1 = a * c->Re() - b * c->Im();
	double v2 = a * c->Im() + b * c->Re();
	a = v1;
	b = v2;
}
