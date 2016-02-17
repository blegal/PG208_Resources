#include "complex.hpp"


Complex::Complex()
{
	a = 0.0f;
	b = 0.0f;
}


Complex::Complex(const Complex* c)
{
	a = c->Re();
	b = c->Im();
}


Complex::Complex(const double _a, const double _b)
{
	a = _a;
	b = _b;
}


Complex* Complex::clone() const
{
	return new Complex( this );
}


double Complex::Re() const
{
	return a;
}


double Complex::Im() const
{
	return b;
}


void Complex::show( ) const
{
	std::cout << a << " + " << b << ".i";// << std::endl;
}


void Complex::add ( const double v )
{
	a += v;
}


void Complex::sub ( const double v )
{
	add( -v );
}


void Complex::mult( const double v )
{
	a *= v;
}


void Complex::add ( const Complex* c )
{
	a += c->Re();
	b += c->Im();
}


void Complex::sub ( const Complex* c )
{
	a -= c->Re();
	b -= c->Im();
}


void Complex::mult( const Complex* c )
{
	double v1 = a * c->Re() - b * c->Im();
	double v2 = a * c->Im() + b * c->Re();
	a = v1;
	b = v2;
}

std::ostream& operator<<(std::ostream& out, const Complex& c)
{
	out << c.Re() << " + " << c.Im() << ".i";
	return out;
}

bool operator==(const Complex& a, const Complex& b)
{
	return (a.Re() == b.Re()) && (a.Im() == b.Im());
}

bool operator!=(const Complex& a, const Complex& b)
{
	return !(a == b);
}

Complex operator*(Complex a, const Complex& b)
{
	Complex r( &a );
	r.mult( &b );
	return r;
}

Complex operator*(Complex a, const double b)
{
	Complex r( &a );
	r.mult( b );
	return r;
}

Complex operator+(Complex a, const Complex& b)
{
	Complex r( &a );
	r.add( &b );
	return r;
}

Complex operator+(Complex a, const double b)
{
	Complex r( &a );
	r.add( b );
	return r;
}


Complex operator-(Complex a, const Complex& b)
{
	Complex r( &a );
	r.sub( &b );
	return r;
}

Complex operator-(Complex a, const double b)
{
	Complex r( &a );
	r.sub( b );
	return r;
}

