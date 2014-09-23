#include <iostream>
#include "BigInteger.h"
using namespace std;


int main()
{
	BigInteger a(1234567890);
	BigInteger b(8899999);
	cout << a+b;

	cin.ignore();
	cin.get();
	return 0;
}