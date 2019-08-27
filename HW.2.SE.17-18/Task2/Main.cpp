#include "Settings.h"

int main()
{
	Settings<string> s1;
	s1.set("test_key_1", "test_value_1");
	s1.set("test_key_2", "test_value_2");
	s1.set("test_key_3", "test_value_3");
	s1.print();

	Settings<string> s2(s1);
	s2.print();

	Settings<string> s3 = s2;
	s3.print();

	s3.set("test_key_2", "new_value");

	string str = "";
	s3.get("test_key_2", str);
	cout << str << endl; //съхраняваме value на Pair с key "test_key_2" в str

	cout << "Count of Pairs is: " << s3.count();
		
	return 0;
}
