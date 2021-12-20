#include "example19.h"
#include <iostream>
using std::cout;
using std::endl;

bool Base::equal(const Base& b) const {
	cout << "base equal" << endl;
	return true;
}

bool Derived::equal(const Base& b) const {
	const Derived& d = dynamic_cast<const Derived&>(b);
	cout << "derived equal" << endl;
	return true;
}

bool equal(const Base& b1, const Base& b2) {
	return typeid(b1) == typeid(b2) && b1.equal(b2);
}