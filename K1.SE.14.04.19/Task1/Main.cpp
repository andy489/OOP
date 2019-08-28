#include "Browser.h"

int main()
{
	WebPage w1, w2; 
	std::cin >> w1;
	std::cin >> w2;		

	WebPage w3("https://github.com/", "123.23.123.23");

	Browser b;

	b.addPage(w1);
	b.addPage(w2);
	b.addPage(w3);
	
	b.displayPages();

	Browser b_copy = b; // with operator=
	//Or equivalently with copy constructor: Browser b_copy(b); 

	b_copy -= 1;

	b_copy.displayPages();	
	return 0;
}
