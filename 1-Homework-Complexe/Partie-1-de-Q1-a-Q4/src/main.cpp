#include <iostream>

using namespace std;

#include "complex.hpp"

int main(int argc, char** argv)
{
	// (2 + 3.i)

	Complex c1( 2,  3 );

	cout << "Initial complex      = ";
	c1.show();
	cout << endl;

	c1.add ( 1 );
	cout << "After addition       = ";
	c1.show();
	cout << endl;

	c1.sub ( 1 );
	cout << "After substraction   = ";
	c1.show();
	cout << endl;

	c1.mult( 2 );
	cout << "After multiplication = ";
	c1.show();
	cout << endl;


	// (3 – 1.i)

	Complex c2( 3, -1 );

	cout << "Initial complex      = ";
	c1.show();
	cout << endl;

	c1.add ( &c2 );
	cout << "After addition       = ";
	c1.show();
	cout << endl;

	c1.sub ( &c2 );
	cout << "After substraction   = ";
	c1.show();
	cout << endl;

	c1.mult( &c2 );
	cout << "After multiplication = ";
	c1.show();
	cout << endl;


	return 0;
}
