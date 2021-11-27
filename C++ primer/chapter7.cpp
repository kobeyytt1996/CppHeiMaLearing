#include <iostream>
using namespace std;
#include "Person.h"
#include <vector>
#include <string>

struct Sales_data {
	string isbn() const {

	}

	double avg_price() const;

	Sales_data& combine() {
		return *this;
	}
};

double Sales_data::avg_price() const {
	return 0.0;
}

class Const_Ref {
public:
	Const_Ref(int ii);
	Const_Ref();
private:
	const int ci;
	const int& ri;
};

Const_Ref::Const_Ref(int ii) : ci(ii), ri(ci) {

}

Const_Ref::Const_Ref() : Const_Ref(10) {

}

class TypeCon {
public:
	explicit TypeCon(int i) {
		record = i;
	}

	int record;
};

struct Aggregate {
	string s;
	int i;
};

class Debug {
public:
	bool io;

	constexpr Debug(bool b) : io(b) {}

};

class Account {
public:
	static double rate() {
		return 0.0;
	}
private:
	static double interestRate;

	static constexpr double scd = 0.0;

	static Account acc;
};

double Account::interestRate = 0.0;
constexpr double Account::scd;

int main07() {
	Const_Ref cr = 5;
	
	/*TypeCon tc = 5;
	tc = 6;
	tc = static_cast<int>(7.5F);*/

	TypeCon tc = static_cast<TypeCon>(5);

	cout << tc.record << endl;

	string s = "aa";
	vector<int> vi = static_cast<vector<int>>(5);

	Aggregate a{ "aa", 2 };
	Aggregate a1 = { "aa", 2 };
	
	double d1 = Account::rate();
	return EXIT_SUCCESS;
}