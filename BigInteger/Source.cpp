#include <iostream>
#include "BigInteger.h"
using namespace std;


int main()
{
	BigInteger a(12345);
	BigInteger b(5234);
	cout << "a= " << a << endl
		<< "b= " << b << endl
		<< "a+b = " << a + b << endl
		<< "a*b = " << a*b << endl;

	cin.ignore();
	cin.get();
	return 0;
}