#pragma once
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

class BigInteger;//prototype to add friend class in node

template <class T>
class Node
{
private:
	T value;
	Node * next;

	friend class BigInteger;
	friend std::ostream & operator <<(std::ostream& os, BigInteger lst);
};

class BigInteger
{

	friend std::ostream & operator <<(std::ostream& os, BigInteger lst);


public:
	BigInteger()
	{
		start = NULL;
		last = NULL;
	}
	BigInteger(int num)
	{
		start = NULL;
		last = NULL;
		setNumber(num);
	}
	BigInteger(string num)
	{
		start = NULL;
		last = NULL;
		setNumber(num);
	}

	bool isEmpty()
	{
		if (start == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
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
		//chon list 2peyvandi nist , lazeme ke addad ro az akhar b aval dar list negah darim ta moshkeli dar jam va zarb pish nayad
		for (int i = n-1; i >= 0; i--)
		{
			add(num[i] - '0');
		}
	}

	BigInteger operator+(BigInteger num2)
	{
		Node<int> * a = start;
		Node<int> * b = num2.start;
		BigInteger result;
		int carry = 0;
		int temp;

		while (a != NULL && b != NULL)
		{
			temp = a->value + b->value +carry;
			carry = temp / 10;
			result.add(temp%10);
			a = a->next;
			b = b->next;
		}//while

		while (a != NULL)
		{
			temp = a->value + carry;
			carry = temp/10;
			result.add(temp%10);
			a = a->next;
		}//while

		while (b != NULL)
		{
			temp = b->value + carry;
			carry = temp/10;
			result.add(temp%10);
			b = b->next;
		}//while

		if (carry == 1)
		{
			result.add(1);
		}
		return result;
	}


	BigInteger operator* (BigInteger num2)
	{
		Node<int> * a = start;
		Node<int> *b ;

		BigInteger result(0);
		BigInteger temp(0);
		int level = 0;
		int carry = 0;
		int tempProduct;
		while (a != NULL)
		{
			temp.reset();
			b = num2.start;
			for (int i = 0; i < level; i++)
			{
				temp.add(0);
			}

			while (b != NULL)
			{
				tempProduct = ((a->value)*(b->value))+carry;
				temp.add(tempProduct % 10);
				carry = tempProduct / 10;
				b = b->next;
			}
			if (carry != 0)
			{
				temp.add(carry);
				carry = 0;
			}
			level++;
			result = result + temp; //Do we need copy cunstructor???
			a = a->next;

		}//while a

		
		return result;
	}//opertator *

private:
	Node<int> * start;
	Node<int> * last;
	void reset()
	{
		delete[] start;
		start = NULL;
		last = NULL;
	}
	void add(int value)
	{
		if (isEmpty())
		{
			addToFirst(value);
			return;
		}
		else
		{
			last->next = new Node<int>;
			last = last->next;
			last->value = value;
			last->next = NULL;
			return;
		}
	}
	void addToFirst(int value)
	{
		start = new Node<int>;
		start->value = value;
		start->next = NULL;
		last = start;
		return;
	}
};


std::ostream & operator <<(std::ostream& os, BigInteger lst)
{
	Node<int> * link = lst.start;
	if (lst.isEmpty())
		os << "No Number";
	stringstream ss;
	while (link != NULL)
	{
		ss << link->value;
		link = link->next;
	}
	string result = ss.str();
	int n = result.length();
	for (int i = n - 1; i >= 0; i--)
	{
		os << result[i];
	}
	
	return os;
}