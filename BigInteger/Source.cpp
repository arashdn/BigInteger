#include <iostream>
#include "BigInteger.h"
using namespace std;


int main()
{
	BigInteger a("123456");
	BigInteger b(52386);

	cout << "a= " << a << endl
		<< "b= " << b << endl
		<< "a+b = " << a + b << endl
		<< "a/10^4 = " << a.divideByTen(4) << endl
		<< "a*10^4 = " << a.multiplyPerTen(4) << endl
		<< "a%10^4 = " << a.remToTen(4) << endl
		<< "(int) a = " << a.toInteger() << endl
		<< "a*b = " << a*b << endl;
	cin.ignore();
	cin.get();
	return 0;
}