#pragma once
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;


template <class T>
class Node
{
private:
	T value;
	Node * next;

	friend class BigInteger;
	friend std::ostream & operator <<(std::ostream& os, BigInteger &lst);
};

class BigInteger
{

	friend std::ostream & operator <<(std::ostream& os, BigInteger &lst);


public:
	BigInteger(int num)
	{
		start = NULL;
		setNumber(num);
	}
	BigInteger(string num)
	{
		start = NULL;
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
		for (int i = 0; i < n; i++)
		{
			add(num[i] - '0');
		}
	}

private:
	Node<int> * start;
	Node<int> * last;
	void reset()
	{
		delete[] start;
		start = NULL;
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


std::ostream & operator <<(std::ostream& os, BigInteger & lst)
{
	Node<int> * link = lst.start;
	if (lst.isEmpty())
		os << "No Number";
	while (link != NULL)
	{
		os << link->value;
		link = link->next;
	}
	return os;
}