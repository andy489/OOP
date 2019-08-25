#include "Admin.h"

int main()
{
	Guest guest1("11.111.11.111"); guest1.print();
	User user1("22.222.22.222", "andy489", "1234", "Andrey Stoev"); user1.print();

	user1.changePass("0000", "newPassword");
	//checking function changePass and the encrypting & decrypting also

	user1.changePass("1234", "new"); user1.print();

	PowerUser powUser1("33.333.33.333", "powUser_12", "abc", "Clint Eastwood"); powUser1.print();
	
	powUser1.incrementReputation(user1); /* checking giving reputation */ powUser1.print();

	powUser1.incrementReputation(powUser1);

	VIP vip1("444.44.444.44", "Mr_nullPtr", "123", "Svetlin Popivanov"); vip1.print();

	vip1.setTitle("Svetlin Popivanov"); vip1.setTitle("Patarenkov"); vip1.print();

	Admin admin1("55.555.55.55", "Kalata_123", "trivial", "Kaloyan Nikolov"); admin1.print();

	admin1.setUsername("Kalata_123"); admin1.setUsername("Kalata_new_username"); admin1.print();

	admin1.setUsernameOfUser(powUser1, "Clint_Eastwood_12");
	powUser1.print();

	return 0;
}
