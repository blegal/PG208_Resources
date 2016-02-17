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

	Complex c2 = c1 + 1;
	cout << "After addition       = ";
	c2.show();
	cout << endl;

	Complex c3 = c2 - 1;
	cout << "After substraction   = ";
	c3.show();
	cout << endl;

	Complex c4 = c3 * 2;
	cout << "After multiplication = ";
	c4.show();
	cout << endl;


	// (3 – 1.i)

	Complex c5( 3, -1 );

	cout << "Initial complex      = ";
	c5.show();
	cout << endl;

	Complex c6 = c1 + c2;
	cout << "After addition       = ";
	c6.show();
	cout << endl;

	Complex c7 = c6 - c2;
	cout << "After substraction   = ";
	c7.show();
	cout << endl;

	Complex c8 = c1 * c2;
	cout << "After multiplication = ";
	c8.show();
	cout << endl;


	return 0;
}
