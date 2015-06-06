#pragma once
#define MULTIPLY_THRESHOLD 4
#include <ostream>
#include <string>
#include <sstream>
using namespace std;

class BigInteger;//prototype to add friend class in node

class Node
{
private:
	int value;
	Node * next;
	Node * previous;

	friend class BigInteger;
	friend std::ostream & operator <<(std::ostream& os, BigInteger lst);
};

class BigInteger
{
	friend std::ostream & operator <<(std::ostream& os, BigInteger lst);

private:
	Node * first;
	Node * last;

	BigInteger()
	{
		first = NULL;
		last = NULL;
	}

	void reset()
	{
		delete[] first;
		first = NULL;
		last = NULL;
	}

	void add(int value)
	{
		if (isEmpty())
		{
			first = new Node;
			first->value = value;
			first->next = NULL;
			first->previous = NULL;
			last = first;
		}
		else
		{
			Node * temp = first;
			while (temp->next != NULL)
				temp = temp->next;

			temp->next = new Node;
			temp->next->next = NULL;
			temp->next->previous = temp;
			temp->next->value = value;
			last = temp->next;
		}
		return;
	}

	void addToFirst(int value)
	{
		if (isEmpty())
		{
			first = new Node;
			first->value = value;
			first->next = NULL;
			first->previous = NULL;
			last = first;
		}
		else
		{
			Node * temp = new Node;
			temp->value = value;
			temp->next = first;
			temp->previous = NULL;
			first = temp;
		}
		return;
	}


public:

	BigInteger(int num)
	{
		first = NULL;
		last = NULL;
		setNumber(num);
	}
	BigInteger(string num)
	{
		first = NULL;
		last = NULL;
		setNumber(num);
	}

	bool isEmpty()
	{
		if (first == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int getLenght()
	{
		if (isEmpty())
			return 0;

		int count = 0;
		Node * temp = first;
		count++;
		while (temp->next != NULL)
		{
			temp = temp->next;
			count++;
		}
		return count;
	}

	bool isZero()
	{
		if (isEmpty())
			return false;

		Node * temp = first;
		while (temp != NULL)
		{
			if (temp->value != 0)
				return false;
			temp = temp->next;
		}
		return true;
	}

	int toInteger()
	{
		if (isEmpty() || getLenght() > 9)
			return 0;

		int result = 0;
		Node * temp = first;
		while (temp != NULL)
		{
			result = result * 10 + temp->value;
			temp = temp->next;
		}
		return result;
	}

	void setNumber(int num)
	{
		ostringstream convert;
		convert << num;
		return setNumber(convert.str());
	}

	void setNumber(string num)
	{
		reset();
		int n = num.length();
		for (int i = 0; i < n; i++)
		{
			add(num[i] - '0');
		}

	}

	void operator=(BigInteger &b)
	{
		first = NULL;
		last = NULL;
		if (!b.isEmpty())
		{
			Node * temp = b.first;
			while (temp != NULL)
			{
				add(temp->value);
				temp = temp->next;
			}
		}// if
	}

	BigInteger operator+(BigInteger num2)
	{
		Node * a = last;
		Node * b = num2.last;
		BigInteger result;
		int carry = 0;
		int temp;

		while (a != NULL && b != NULL)
		{
			temp = a->value + b->value + carry;
			carry = temp / 10;
			result.addToFirst(temp % 10);
			a = a->previous;
			b = b->previous;
		}//while

		while (a != NULL)
		{
			temp = a->value + carry;
			carry = temp / 10;
			result.addToFirst(temp % 10);
			a = a->previous;
		}//while

		while (b != NULL)
		{
			temp = b->value + carry;
			carry = temp / 10;
			result.addToFirst(temp % 10);
			b = b->previous;
		}//while

		if (carry == 1)
		{
			result.addToFirst(1);
		}
		return result;
	}

	BigInteger divideByTen(int pow)
	{
		//age tool n bashe va az aval n-pow ta khoone ro bardarim daghighan mishe number/10^pow
		int n = getLenght();

		if (n <= pow)
		{
			BigInteger result(0);
			return result;
		}

		Node * temp = first;
		BigInteger result;
		for (int i = 0; i < n - pow; i++)
		{
			result.add(temp->value);
			temp = temp->next;
		}
		return result;
	}

	BigInteger multiplyPerTen(int pow)
	{
		BigInteger result;
		result = *this;
		for (int i = 0; i < pow; i++)
		{
			result.add(0);
		}
		return result;
	}

	BigInteger remToTen(int pow)
	{
		if (isEmpty())
			return 0;
		int i = 0;
		int n = getLenght();
		BigInteger result;
		Node * temp = last;
		while (i++ < pow && temp != NULL)
		{
			result.addToFirst(temp->value);
			temp = temp->previous;
		}
		return result;
	}


	BigInteger operator*(BigInteger num2)
	{
		if (isEmpty() || num2.isEmpty() || isZero() || num2.isZero())
		{
			BigInteger result(0);
			return result;
		}

		int len1 = getLenght(), len2 = num2.getLenght();
		int n;

		if (len1 > len2)
			n = len1;
		else
			n = len2;

		if (n <= MULTIPLY_THRESHOLD)
		{
			int u = toInteger();
			int v = num2.toInteger();
			BigInteger result(u*v);
			return result;
		}

		int m = n / 2;
		BigInteger x = divideByTen(m);
		BigInteger y = remToTen(m);
		BigInteger w = num2.divideByTen(m);
		BigInteger z = num2.remToTen(m);
		cout << "\nx=" << x << "\ty=" << y << "\tw=" << w << "\tz=" << z;


		BigInteger result;
		BigInteger temp1 = (x*w).multiplyPerTen(2 * m);
		BigInteger temp2 = ((x*z) + (w*y)).multiplyPerTen(m);
		BigInteger temp3 = (y*z);
		cout << "\ntemp1 = " << temp1 << endl;
		cout << "\ntemp2 = " << temp2 << endl;
		cout << "\ntemp3 = " << temp3 << endl;
		result = temp1 + temp2;
		result = result + temp3;

		return result;

	}


};

std::ostream & operator <<(std::ostream& os, BigInteger lst)
{
	Node * link = lst.first;
	if (lst.isEmpty())
	{
		os << "No Number";
		return os;
	}

	stringstream ss;
	while (link != NULL)
	{
		ss << link->value;
		link = link->next;
	}
	os << ss.str();

	return os;
}