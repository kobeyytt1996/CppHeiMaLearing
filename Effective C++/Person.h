#pragma once
#include <string>
#include <memory>
#include "datefwd.h"
using std::string;
using std::shared_ptr;

class PersonImpl;

class Person {
public:
	Person(const string& name, const Date& birthday);

	Date birthDay() const;
	void setBirth(Date day);
private:
	shared_ptr<PersonImpl> pImpl;
};