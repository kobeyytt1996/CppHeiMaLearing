#include "Person1.h"
#include "RealPerson.h"
using std::make_shared;

shared_ptr<Person1> Person1::create(const Date& date) {
	return make_shared<RealPerson>(date);
}