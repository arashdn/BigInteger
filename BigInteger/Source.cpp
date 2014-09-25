#include <iostream>
#include "BigInteger.h"
using namespace std;


int main()
{
	BigInteger a(123456);
	BigInteger b(5238);
	cout << "a= " << a << endl
		<< "b= " << b << endl
		<< "a+b = " << a + b << endl
		<< "a*b = " << a*b << endl;

	cin.ignore();
	cin.get();
	return 0;
}