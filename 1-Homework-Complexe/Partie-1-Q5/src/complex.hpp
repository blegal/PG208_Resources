#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
using namespace std;

class Complex{
private:
	double a;
	double b;

public:
  Complex();
  Complex(const Complex* c);
  Complex(const double _a, const double _b);

  double Re() const;
  double Im() const;

  void show( ) const;

  void add ( const double v );
  void sub ( const double v );
  void mult( const double v );

  void add ( const Complex* c );
  void sub ( const Complex* c );
  void mult( const Complex* c );

  Complex* clone() const;
};


// DEFINITION DES OPERATEURS SURCHARGES
std::ostream& operator<<(std::ostream& out, const Complex& c);

bool operator==(const Complex& a, const Complex& b);
bool operator!=(const Complex& a, const Complex& b);

Complex operator+(Complex a, const double b);
Complex operator-(Complex a, const double b);
Complex operator*(Complex a, const double b);

Complex operator+(Complex a, const Complex& b);
Complex operator-(Complex a, const Complex& b);
Complex operator*(Complex a, const Complex& b);

/*
*/
#endif