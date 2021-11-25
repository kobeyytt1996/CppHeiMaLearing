#include <iostream>
#include <vector>
#include <string>
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

sst wd = 20;
string screen1(sst = wd) {
	return " ";
}

constexpr int new_sz() {
	return 42;
}

constexpr int scale(size_t st) {
	return new_sz() * st;
}

constexpr int sz = new_sz();

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

	return EXIT_SUCCESS;
}