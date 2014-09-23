#pragma once

template <class T>
class Node
{
private:
	T value;
	Node * next;
};

class BigInteger
{
private:
	Node<int> * start;

};