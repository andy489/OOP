#include "PersonWithAccount.h"

void Test()
{
	Person p1("Ivan Ivanov", "9810211944", 21, 1998);
	std::cout << "~PRINTING PERSON:\n";
	p1.print();
	std::cout << "~PRINTING ACCOUNT:\n";
	BankAccount acc1(1234, 321);
	acc1.displayAccount();

	PersonWithAccount per_with_acc(p1, acc1, "1234567890");
	std::cout << "~PRINTING PERSON WITH ACCOUNT:\n";
	per_with_acc.print();


	per_with_acc.spotify(); // плащане на spotify регистрация
	per_with_acc.print(); // проверка дали сумата е намаляла с 10 лв

	per_with_acc.withdraw(1324); // неуспешен опит за теглене на по-голяма сума
	per_with_acc.payment(1324); // успешно плащане на по-голяма сума от наличния баланс
	per_with_acc.print(); // проверка дали баланса е станал отрицателен

	per_with_acc.payment(300); // неуспешен опит за плащане

	per_with_acc.incaso(2000); // захранване на сметка
	per_with_acc.print();
}

int main()
{
	Test();
	return 0;
}
