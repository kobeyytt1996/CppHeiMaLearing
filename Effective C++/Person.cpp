#include "Person.h"
#include "PersonImpl.h"
using std::make_shared;

Person::Person(const string& name, const Date& birthday) 
	: pImpl(new PersonImpl(name, birthday)) {}

Date Person::birthDay() const {
	return pImpl->birthDay();
}