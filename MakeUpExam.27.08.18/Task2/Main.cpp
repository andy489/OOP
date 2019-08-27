#include "Set.h"

int main()
{
	Set<size_t> set1, set2;

	for (size_t i = 0; i < 5; i++) set1.insert(i);
	for (size_t i = 3; i < 8; i++) set2.insert(i);

	std::cout << "Set 1:\n";
	set1.display();
	std::cout << "Set 2:\n";
	set2.display();

	std::cout << "Set 3 = united set1 & set2:\n";
	Set<size_t> set3 = set1.unite(set2);
	set3.display();

	std::cout << "Set 4 = Intersected set1 & set2:\n";
	Set<size_t> set4 = set1.intersect(set2);
	set4.display();

	Set<size_t> set5(set3);
	std::cout << "Set 5 = Set 3 (copy constructor)\n";
	set5.display();

	Set<size_t> set6=set4;
	std::cout << "Set 6 = Set 4 (operator=)\n";
	set5.display();

	return 0;
}
