#include <initializer_list>
#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <set>
#include "Widget.h"
using std::complex;
using std::initializer_list;
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::swap;
using widgetEnv::Widget;

class TestIL {
public:
	explicit TestIL(int i1, int i2) {
		cout << "i1 i2" << endl;
	}

	TestIL(initializer_list<int> il) {
		cout << "initializer" << endl;
	}
};

class Rational {
public:
private:
	int n, d;
};

const Rational operator*(const Rational& r1, const Rational& r2) {
	return r1;
}


int main04() {
	int i1{ 10 };
	complex<double> cd = { 1.2, 2.2 };
	std::max({ 1, 2, 3 });
	vector<double> vd1{ 1.0, 2.0 };
	vector<double> vd2{ 1.0, 2.0 };
	vd1.insert(vd1.begin(), { 3.0, 5.0 });
	TestIL til = { 1, 2 };
	set<int> si{ 1, 2, 3 };
	for (auto& i : si) {
		//i = 20;
	} 
	swap(vd1, vd2);
	using std::swap;
	Widget<int> w1, w2;
	swap(w1, w2);
	return EXIT_SUCCESS;
}