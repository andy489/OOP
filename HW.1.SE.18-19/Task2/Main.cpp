#include "DNSCache.h"

int main()
{
	DNSRecord r1, r2, r3;

	r1.setDomainName("https://www.google.com/");
	r1.setIpAddress("234.12.75.214.89");

	r2.setDomainName("https://github.com/");
	r2.setIpAddress("213.86.33.351.90");

	r3.setDomainName("https://www.fmi.uni-sofia.bg/");
	r3.setIpAddress("189.25.64.223.19");

	DNSCache cache1;

	cache1.add(r1);
	cache1.add(r2);
	cache1.add(r3);
	//cache1.flush();
	cache1.print();

	DNSRecord r11, r22, r33;

	r11 = r3;
	r22 = r2;
	r33 = r1; 

	DNSCache cache2;

	cache2.add(r11);
	cache2.add(r22);
	cache2.add(r33);

	cache2.print();
	cache2.del(2);
	//cache2.flush();
	cache2.print();

	cout << "https://www.abv.bg/ searching in cache 2...\n";
	cache2.lookup("https://www.abv.bg/");
	cout << "https://www.google.com/ searching in cache 1...\n";
	cache1.lookup("https://www.google.com/");

	return 0;
}
