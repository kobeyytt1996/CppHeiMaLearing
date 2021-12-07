#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using namespace std::placeholders;

class PrintString {
public:
	PrintString(ostream &ostream1 = cout, char c = ' ') : os(ostream1), seperator(c) {}

	void operator()(string& s) const {
		os << s << seperator;
	}
private:
	ostream& os;
	char seperator;
};

class SmallInt {
public:
	SmallInt(int i = 0) : val(i) {
		if (i < 0 || i > 255) {
			throw out_of_range("wrong value");
		}
	}

	explicit operator int() const {
		return val;
	}

	explicit operator bool() const {
		return val;
	}
private:
	size_t val;
};

int add14(int i, int j) { return i + j; }

int main14() {
	auto a1 = [](int i) {return i > 0; };
	plus<int> intAdd;
	negate<int> intNegate;

	cout << intAdd(10, 20) << " " << intNegate(15) << endl;

	vector<string*> vs1;
	sort(vs1.begin(), vs1.end(), greater<string*>());

	vector<int> vi1{ 1, 3, 5, 7 };
	cout << count_if(vi1.cbegin(), vi1.cend(), bind(greater<int>(), _1, 3)) << endl;

	transform(vi1.begin(), vi1.end(), vi1.begin(), bind(multiplies<int>(), _1, 2));
	for_each(vi1.cbegin(), vi1.cend(), [](int i) {cout << i << endl; });

	auto mod = [](int i, int j) {return i % j; };

	function<int(int, int)> f1 = add14;
	function<int(int, int)> f2 = mod;

	map<string, function<int(int, int)>> binops = { {"+", add14}, {"%", mod} };
	cout << binops["+"](100, 500) << endl;

	SmallInt si(200);
	
	static_cast<int> (si);

	while (si)
	{
		si = 0;
	}
	si.operator bool();

	return EXIT_SUCCESS;
}