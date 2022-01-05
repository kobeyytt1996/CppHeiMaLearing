#include <iostream>
#include <vector>
#include <ccomplex>
using std::string;
using std::vector;
using std::cout;
using std::endl;
#include "FileSystem.h"
#include "Directory.h"

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

class AWOV {
public:
	virtual ~AWOV() = 0;
};

AWOV::~AWOV() {

}

class AWOVD : public AWOV {
public:

};

class Transaction {
public:
	virtual void logTransaction() = 0;

	Transaction();

private:
	void init() {
		logTransaction();
	}
};

Transaction::Transaction() {
	init();
}

class CashTran : public Transaction {
	virtual void logTransaction() override {
		std::cout << "Cash" << endl;
	}
};

template<typename... Args>
void printYuan(const Args&... args) {
	cout << "no more" << endl;
}

template<typename T, typename... Args>
void printYuan(const T& t, const Args&... args) {
	cout << t << endl;
	printYuan(args...);
}

int main01() {
	const string s1("aaaac");
	const char* const pc = "baac";

	vector<int> tv1{ 1, 2, 3 };
	const vector<int>::iterator ci = tv1.begin();
	*ci = 20;
	const vector<int> tv2{ 1 };
	tv2[0];

	mul(Rational()) = Rational();
	
	AWOVD aw;

	cout << __cplusplus << endl;

	std::complex<double> c1{ 1.0, 2.0 };
	printYuan(1);

	return 1;
}