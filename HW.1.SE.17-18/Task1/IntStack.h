struct Node
{
	int data;
	Node * prev;
};
class IntStack
{
	Node* top;
	void empty(); /* Empties the stack */
	void copy(const IntStack & St); /* Copies the items of one stack into the current one appending them at the end */
	void copyRecursion(Node*); /* ONLY TO BE USED FROM INSIDE copy() => Used to copy the items from one stack into another recursively */
public:
	IntStack(); /* Constructor */	
	IntStack(const IntStack& s); /* Copy constructor */
	IntStack& operator=(const IntStack& s); /* operator= */

	const bool isEmpty(); /* Returns whether the stack has elements or not */
	const int peek(); /* Views the last element */
	void push(int data); /* Adds an element */
	int pop(); /* Gets the last element and remove it from the stack */
	
	~IntStack(); /* Destructor */
};
