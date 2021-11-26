#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

void func(void) {
	static int si;
	cout << si++ << endl;
}

vector<int>::iterator change_val(int a, vector<int>::iterator it);

void print(const int arr[], size_t size) {

}

void print01(int(&arr)[10]) {

}

void print02(int(*arrPtr)[10]) {

}

void print03(int mulArr[][10]) {

}

void swapIntPtr(int*& p1, int*& p2) {

}

void error_msg(initializer_list<string> il) {
	for (auto it = il.begin(); it != il.end(); ++it) {

	}

	for (auto& s : il) {

	}
}

void foo(...) {

}

inline const string& shorterString(const string& s1, const string& s2) {
	return s1;
}

char& get_val(string& s, decltype(s.size()) index) {
	return s[index];
}

vector<string> process() {
	return { 10, "ss"};
}

int(*func(int i))[10]{
	int arr[10] = {};
	return &arr;
}

auto func1(int i) -> int(&)[10]{
	int arr[10] = {};
	return arr;
}

string(&func2(int i))[10]{
	string arr[10];
	return arr;
}

auto func3(int i) -> int(&)[10]{
	int arr[10] = {};
	return arr;
}

typedef string::size_type sst;
string screen(sst height = 10, sst weight = 20) {
	return " ";
}

#define NDEBUG

sst wd = 20;
string screen1(sst = wd) {
#ifndef NDEBUG
	cerr << __func__ << endl;
#endif // !NDEBUG
	return " ";
}

constexpr int new_sz() {
	return 42;
}

constexpr size_t scale(size_t st) {

	return new_sz() * st;
}

constexpr int sz = new_sz();

int add(int i1, int i2) {
	return i1 + i2;
}

int main(int argc, char *argv[]) {
	func();
	func();

	extern int i;
	int arr[5] = {};
	int arr1[10] = {};
	print(arr, end(arr) - begin(arr));
	print01(arr1);
	int arr2[2][10] = {};
	print02(arr2);

	error_msg({ "yuan" });

	typedef int arrT[10];
	using arrT1 = int[10];

	assert(arr[0] >= 0);
	//scale(2);
	screen1();

	vector<string>(*pf)() = &process;
	vector<string> vs1 = pf();

	typedef int (*intFunc)(int, int);
	using intFunc1 = int(*)(int, int);
	intFunc1 func4();
	intFunc1 func5(int(int, int));
	intFunc1 func6(intFunc1);
	auto func7() -> int(*)(int, int);
	int(*func8())(int);
	decltype(func4) * func9();

	int (*test1)(int, int) = add;
	vector<int (*)(int, int)> vt1;
	vt1.push_back(test1);
	cout << vt1[0](10, 20) << endl;

	return EXIT_SUCCESS;
}