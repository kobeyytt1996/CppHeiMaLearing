#include "Person.h"

istream& read(istream& is, Person& p) {
	is >> p.name >> p.address;
	return is;
}

ostream& print(ostream& os, const Person& p) {
	os << p.name << p.address << "aa";
	return os;
}

Person::Person(istream& is) {
	read(is, *this);
}