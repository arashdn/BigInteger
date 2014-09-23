#include <iostream>
#include "BigInteger.h"
using namespace std;


int main()
{
	BigInteger a(123);
	BigInteger b(900);
	cout << "a= " << a <<endl
		<< "b= " << b << endl
		<<"a+b = " << a+b;

	cin.ignore();
	cin.get();
	return 0;
}