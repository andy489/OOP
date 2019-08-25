#include "MagicBox.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(0));

	MagicBox<string> magicBox1;

	string items[] = { "Rubic Cube", "Magic Card", "Dice", "Book", "Coin", "Puzzle", "Yo-yo" };
	size_t count = sizeof(items) / sizeof(items[0]);

	for (size_t i = 0; i < count; i++) magicBox1.insert(items[rand() % count]);	

	magicBox1.list();

	cout << magicBox1.pop() << endl;
	cout << "---------------------------------------------" << endl;
	magicBox1.list();
	for (size_t i = 0; i < count; i++) cout << magicBox1.pop() << endl;	
	return 0;
}
