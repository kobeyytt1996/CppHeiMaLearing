#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Money {};

class Customer {
public:
	Customer(const Customer& rhs) : name(rhs.name), money(new Money(*(rhs.money))) {

	}

	Customer& operator=(const Customer& rhs) {
		name = rhs.name;
		Money* temp = money;
		money = new Money(*rhs.money);
		delete temp;
	}

	virtual ~Customer() {
		delete money;
	}
private:
	string name;
	Money* money;
};

class RichCustomer : public Customer {
public:
	RichCustomer(const RichCustomer &rhs) : Customer(rhs), level(rhs.level) {}

	RichCustomer& operator=(const RichCustomer& rhs) {
		Customer::operator=(rhs);
		level = rhs.level;
	}
private:
	int level;
};

int main02() {


	return EXIT_SUCCESS;
}