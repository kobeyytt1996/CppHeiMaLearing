#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
	friend istream& read(istream& is, Person& p);
	friend ostream& print(ostream& os, const Person& p);
private:
	string name;
	string address;

public:
	typedef std::string::size_type pos;

	Person() = default;

	Person(const string& s1, const string& s2) : name(s1), address(s2) {}

	Person(istream& is);

	string getName() const;
};

istream& read(istream& is, Person& p);

ostream& print(ostream& os, const Person& p);