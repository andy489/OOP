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
class Stack
{
private:
	node* top = nullptr;
public:
	Stack();
	Stack(const Stack& s);

void push(int value);

	void pop();
	int peek()const;
	void print()const;
	bool isEmpty()const;
	~Stack();
};
Stack sortStack(const Stack &in_stack);
