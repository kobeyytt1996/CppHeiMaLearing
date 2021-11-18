#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int reused = 0;

int getYuan() {
	return 1;
}

struct Sales_data {
	string bookNo;
};

int main1() {
	bool b = 42;
	int i = b;
	i = 3.14;
	double pi = i;
	unsigned char ch = -1;
	cout << sizeof(char) << endl;
	cout << (int)ch << endl;
	cout << (-1 % 256) << endl;
	unsigned int u = 256;
	std::cout << "good " "for" << endl;

	unsigned long ul = 345UL;
	int i1 = 1;
	i1 = { 1 };
	int i2 = 3.14;

	//extern int i4;
	int i4 = 5;

	cout << ::reused << endl;

	int &reused1 = reused;
	int& reused2 = reused;
	int& i5 = i4, & i6 = i2;
	//unsigned int& i7 = 20;
	int* i8 = &i4;

	int* i9 = nullptr;
	int* i10 = 0, *i11 = NULL;

	void* v1 = &i9;
	void** vv1 = &v1;

	int*& i12 = i11;

	const int bufSize = getYuan();
	const int& buf2 = bufSize;

	const double d3 = 2.9;
	const double* d4 = &d3;
	const double *const d5 = d4;

	constexpr int ce1 = 20;
	constexpr int ce2 = ce1 + 1;

	constexpr int* ce3 = nullptr;

	constexpr int null = 0;

	typedef double wages;
	wages w1 = 2.0;

	typedef wages wages2, * p;

	using db = double;

	using db2 = double*;
	const db2 db22 = &pi;

	auto at1 = 15 + 30.0;
	cout << sizeof(at1) << endl;

	const auto at2 = 120, * at3 = &at2;

	const int& cr = at2;
	auto at4 = &cr;
	const int ci10 = 100;
	auto& at5 = ci10;
	auto& at6 = at5;

	decltype(30) i13 = 20;
	decltype(*d4) dt1 = d3;

	const char* ch1 = "hello";

	string s1 = string(10, 'c');

	return 0;
}
