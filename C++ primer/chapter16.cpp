#include <iostream>
#include <functional>
#include <vector>
#include "Blob.h"
#include <string>
#include <type_traits>
#include <sstream>
#include "Sales_data.h"
#include <unordered_set>
using namespace std;

template<typename T>
inline int compare(const T& t1, const T& t2) {
	less<T> myLess;
	if (myLess(t1, t2)) {
		return -1;
	}
	return 0;
}

template<unsigned N, unsigned M>
int compare(const char(&arr1)[N], const char(&arr2)[M]) {
	return 0;
}

class NoCompare {

};

template<typename T, typename N>
T myFind(const T& s, const T& e, N target) {
	T it = s;
	while (it != e) {
		if (*it == target) {
			return it;
		}
		++it;
	}

	return e;
}

template<typename T, unsigned N>
void printArr(T(&arr)[N]) {
	for (auto a : arr) {
		cout << a << endl;
	}
}

template<typename T, unsigned N>
constexpr unsigned sizeArr(T(&arr)[N]) {
	return N;
}

template<typename T, unsigned N>
T* myEnd(T(&arr)[N]) {
	return arr + N;
}

template<typename T = int>
class Numbers {

};

template<typename T> using twin = pair<T, T>;
template<typename T, typename U> class MyTest;

template<typename T>
typename T::value_type top(const T& t) {
	if (!t.empty()) {
		return t.back();
	}
	else {
		return typename T::value_type();
	}
}

template<typename T, typename F = less<T>>
bool compare(const T& t1, const T& t2, F f = F()) {
	return f(t1, t2);
}

template<typename T>
void printVec(const vector<T>& vt) {
	for (typename vector<T>::size_type sz = 0; sz < vt.size(); ++sz) {
		cout << vt[sz] << endl;
	}
}

class DebugDelete {
public:
	template<typename T>
	void operator()(T* p) {
		cout << "myDelete" << endl;
		delete p;
	}
};

extern template class Blob<bool>;

template<typename T>
void testFunc(const T& t1, const T& t2) {
	return;
}

template<typename It>
auto getVal(It& s) -> decltype(*s) {
	return *s;
}

template<typename It>
auto getVal1(It it) -> typename remove_reference<decltype(*it)>::type {
	return *it;
}

template<typename T>
typename remove_reference<T>::type&& move(T&& t) {
	return static_cast<typename remove_reference<T>::type&&>(t);
}

template<typename T1, typename T2, typename T3>
void flip(T1 f, T2&& t2, T3&& t3) {
	f(std::forward(t3), std::forward(t2));
}

template<typename T>
string debug_rep(const T& t) {
	ostringstream oss;
	oss << t;
	return oss.str();
}

template<typename T>
string debug_rep(T* t) {
	return "pointer";
}

string debug_rep(const string& s) {
	return "nontemplate";
}

string debug_rep(const char* cp) {
	return debug_rep(string(cp));
}

template<typename T, typename... Args>
void foo(const T& t, const Args& ... rest) {
	cout << sizeof...(rest) << endl;
	cout << sizeof...(Args) << endl;
}

template<typename T>
void print(const T& t) {
	cout << t << endl;
}

template<typename T, typename...Args>
void print(const T& t, const Args& ... rest) {
	cout << t << endl;
	print(rest...);
}

template<typename T, typename...Args>
void print(T& t, const Args & ... rest) {
	print(debug_rep(rest)...);
}

template<>
int compare(const char* const& p1, const char* const& p2) {
	return 0;
}

namespace std {
	template<>
	struct hash<Sales_data> {
		typedef size_t return_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data &arg) {
			return hash<unsigned>()(arg.units_sold);
		}
	};
}

template<typename T> struct Foo1 {
	void bar();
};

template<> void Foo1<int>::bar() {

}

template<typename T>
size_t myCount(const vector<T>& vt, const T target) {
	int count = 0;
	for (auto& t : vt) {
		if (t == target) {
			++count;
		}
	}
	return count;
}

int main16() {
	compare("hello", "yuan");
	//compare(NoCompare(), NoCompare());

	vector<int> vi{ 1, 3, 5 };
	cout << *myFind(vi.cbegin(), vi.cend(), 3) << endl;

	int arr[5] = { 1,2, 3, 4, 5 };
	printArr(arr);

	cout << myEnd(arr)[-1] << endl;

	double arrD[sizeArr(arr)] = {};
	Blob<int> blob{ 1, 3, 5 };

	twin<string> authors;
	Numbers<> num;

	int* pi = new int();
	DebugDelete()(pi);

	unique_ptr<string, DebugDelete> ups1(new string, DebugDelete());
	ups1.release();

	Blob<bool> bl{ true };
	bl.push_back(true);

	testFunc("yua", "zha");
	string s;
	cout << sizeof(s.c_str()) << endl;

	int(*pf)(int*) = getVal1;

	foo(43, "aa", 3.0);

	unordered_multiset<Sales_data> SDSet;

	vector<const char *> vs{ "aa", "cc", "aa", "aa"};
	cout << myCount(vs, "aa") << endl;
	return EXIT_SUCCESS;
}

template<typename T> class Foo {
public:
	static int sf;
};

template<typename T> int Foo<T>::sf = 0;

template<typename T, typename...Args>
shared_ptr<T> myMakeShared(Args&&... args) {
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}