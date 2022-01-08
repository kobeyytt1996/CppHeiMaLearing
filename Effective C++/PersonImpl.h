#pragma once
#include <string>
#include "Date.h"
using std::string;

class PersonImpl {
public:
	PersonImpl(const string& name, const Date& birthday) : pName(name), pBirth(birthday) {
		
	}

	Date birthDay() const {
		return pBirth;
	}
private:
	string pName;
	Date pBirth;
};