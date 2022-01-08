#pragma once
#include "datefwd.h"
#include <memory>
using std::shared_ptr;

class Person1 {
public:
	virtual ~Person1() {}
	virtual Date birthday() const = 0;
	
	static shared_ptr<Person1> create(const Date& date);
};