#include <iostream>
#include <vector>
#include <ostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& stream, const vector<T>& v)
{
	for (T item : v)
	{
		stream << item << ' ';
	}
	stream << '\n';
	return stream;
}

bool isNegative(int number) {
	return number < 0;
}

bool isEven(int number) {
	return (number + 1) & 1;
}

bool isBiggerThanThree(int number) {
	return number > 3;
}

vector<int> filter(const vector<int>& vec,
	bool (*shouldFilter)(int number)) {
	vector<int> filtered;
	for (const int elem : vec) {
		if (shouldFilter(elem)) {
			filtered.push_back(elem);
		}
	}
	return filtered;
}

//is negative
//is even
//is bigger than 3

int main()
{
	const vector<int> vec = { 1,2,3,-4,5,-6,7,8 };

	cout << filter(vec, isNegative);
	cout << filter(vec, isEven);
	cout << filter(vec, isBiggerThanThree);

	//another approach with lambda function

	// local anonymous function
	return 0;
}
