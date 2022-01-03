#include <iostream>
#include <vector>
using std::string;
using std::vector;

struct GP {
	enum {NT = 5};
	int score[NT];
	
};

int mul(const int i1, int i2) {
	return i1 * i2;
}

class Rational {

};

Rational mul(Rational&& r) {
	return r;
}

int main() {
	const string s1("aaaac");
	const char* const pc = "baac";

	vector<int> tv1{ 1, 2, 3 };
	const vector<int>::iterator ci = tv1.begin();
	*ci = 20;
	const vector<int> tv2{ 1 };
	tv2[0];

	mul(Rational()) = Rational();

	return 1;
}