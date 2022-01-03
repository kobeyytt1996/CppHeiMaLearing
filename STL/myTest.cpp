#include <algorithm>
#include <forward_list>
#include <vector>
#include <list>
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <unordered_map>
#include <numeric>
using namespace std;

template<>
struct hash<string> {
	size_t operator()(const string& s) const {
		cout << "myHash" << endl;
		return 0;
	}
};
class Foo {
	int i1, i2;
public:
	virtual ~Foo() {

	}
};

namespace {
	template<typename T>
	void test(void(T::*f)(int)) {

	}
}

int mainTest() {
	::vector<int> vi1;
	forward_list<int> fl1;
	fl1.end();
	cout << sizeof(vi1) << endl;
	cout << sizeof(list<int>) << endl;
	cout << sizeof(fl1) << endl;
	iterator_traits<forward_list<int>::iterator>::difference_type diff;
	ptrdiff_t ptrDiff;
	cout << sizeof(deque<int>) << endl;
	cout << sizeof(deque<int>::iterator) << endl;
	stack<int> s1;
	queue<int> q1;
	priority_queue<int> pq1;
	stack<int, list<int>> s2;
	queue<int, vector<int>> q2;
	q2.push(20);
	enum EColor {GREEN, RED} myE;
	cout << sizeof(myE) << endl;
	unordered_map<string, int> umsi;
	umsi.insert({ string("hh"), 2 });

	string s3 = "aa";
	insert_iterator<string> isi = inserter(s3, s3.end());
	count_if(s3.begin(), s3.end(), not1(bind2nd(less<char>(), 'a')));
	istream_iterator<int> ii1;
	tuple<string, int, vector<int>> tp1;
	cout << sizeof(string) << endl;
	get<0>(tp1);
	auto tp2 = make_tuple(20, "aaa", 5.0F);
	get<2>(tp2) = 30;
	cout << get<2>(tp2) << endl;
	tuple<> t1;
	cout << is_trivial<string>::value << endl;
	cout << is_pod<Foo>::value << endl;
	cout << has_virtual_destructor<Foo>::value << endl;
	
	return EXIT_SUCCESS;
}