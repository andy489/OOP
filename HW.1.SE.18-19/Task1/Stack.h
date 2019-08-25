#pragma once
#include <iostream>
using namespace std;
struct node
{
	int value;
	node* prev = nullptr;

	node(int value, node* prev)
	{
		this->value = value;
		this->prev = prev;
	}
};
class IntStack
{
private:
	node* top = nullptr;
public:
	IntStack();
	IntStack(const IntStack& s);

	void push(int value);

	void pop();
	const int peek() const;
	void print() const;
	bool isEmpty() const;
	~IntStack();
};
IntStack sortStack(const IntStack &in_stack);
