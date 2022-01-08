#pragma once
#include "Person1.h"
#include "Date.h"

class RealPerson : public Person1 {
public:
	RealPerson(const Date &date) : birth(date) {}

	virtual Date birthday() const override {
		return birth;
	}
private:
	Date birth;
};