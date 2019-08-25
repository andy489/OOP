#include "IntStack.h"

IntStack::IntStack() : top(nullptr) {}

IntStack::~IntStack()
{
	empty();
}

IntStack::IntStack(const IntStack& s) 
{
	copy(s);
}

IntStack& IntStack::operator=(const IntStack& s) 
{
	if (this != &s) 
	{
		empty();
		copy(s);
	}
	return *this;
}

void IntStack::empty()
{
	Node *toDelete;
	while (top != nullptr)
	{
		toDelete = top;
		top = top->prev;
		delete toDelete;
	}
}

void IntStack::copy(const IntStack& s)
{ 
	copyRecursion(s.top);
}

void IntStack::copyRecursion(Node* item)
{
	if (item != nullptr)
	{
		copyRecursion(item->prev);
		push(item->data);
	}
}

const bool IntStack::isEmpty()
{
	return top == nullptr;
}

const int IntStack::peek()
{
	if (isEmpty()) 
	{
		return 0;
	}
	else 
	{
		return top->data;
	}
}

void IntStack::push(int data)
{
	Node* newItem = new Node;
	newItem->data = data;
	newItem->prev = top;
	top = newItem;
}

int IntStack::pop()
{
	if (isEmpty())
	{
		return 0;
	}
	Node *toDelete = top;
	int intToReturn = top->data;
	top = top->prev;
	delete toDelete;
	return intToReturn;
}
