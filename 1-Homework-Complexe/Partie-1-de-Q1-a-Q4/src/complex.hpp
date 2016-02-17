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
  Complex(double _a, double _b);

  double Re();
  double Im();

  void show( );

  void add ( double v );
  void sub ( double v );
  void mult( double v );

  void add ( Complex* c );
  void sub ( Complex* c );
  void mult( Complex* c );
};

#endif