#include "IntStack.h"
void Stack::push(int value)
{
	if (isEmpty()) top = new node(value, nullptr);
	else
	{
		node* newNode = new node(value, top);
		top = newNode;
	}
}
void Stack::pop()
{
	if (!isEmpty())
	{
		node* temp = top->prev;
		delete top;
		top = temp;
	}
}
const int Stack::peek() const
{
	if (!isEmpty())
	{
		return top->value;
	}
	return 1;
}
void Stack::print() const
{
	if (!isEmpty())
	{
		node* temp = top;
		while (temp != nullptr)
		{
			cout << temp->value << ' ';
			temp = temp->prev;
		}
	}
	else cout << "Stack is empty!";
	cout << "\n\n";
}
bool Stack::isEmpty() const
{
	if (top == nullptr) return true;
	else return false;
}
Stack::Stack()
{
	top = nullptr;
}
Stack::Stack(const Stack & s)
{
	Stack temp;
	node* n = s.top;
	while (n)
	{
		temp.push(n->value);
		n = n->prev;
	}
	while (!temp.isEmpty())
	{
		push(temp.peek());
		temp.pop();
	}
}
Stack::~Stack()
{
	while (!isEmpty()) pop();
}
Stack sortStack(const Stack &in_stack)
{
	Stack stack(in_stack);

	if (stack.isEmpty())
	{
		std::cout << "enter" << std::endl;
		return stack;
	}
	else
	{
		bool swap = true;
		while (swap)
		{
			swap = false;
			Stack currentStack;

			int prev = stack.peek();
			stack.pop();
			while (!stack.isEmpty())
			{
				int cur = stack.peek();
				stack.pop();
				if (prev < cur)
				{
					currentStack.push(cur);
					swap = true;
				}
				else
				{
					currentStack.push(prev);
					prev = cur;
				}
			}
			currentStack.push(prev);
			while (!currentStack.isEmpty())
			{
				stack.push(currentStack.peek());
				currentStack.pop();
			}
		}
		return stack;
	}
}
