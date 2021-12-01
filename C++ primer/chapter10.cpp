#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iterator>
#include <functional>
#include <list>
#include <fstream>
using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, string::size_type sz) {
	return s.size() >= sz;
}

bool check_numSize(int i, string::size_type sz) {
	return i >= sz;
}

ostream& myPrint(ostream& os, const string& s, char c) {
	os << s << c;
	return os;
}

int main10() {
	vector<int> vi{ 1, 3, 2 };
	auto res = find(vi.cbegin(), vi.cend(), 2);
	int ia[] = { 1, 3, 5 };
	auto res1 = find(begin(ia), end(ia), 3);
	auto num = count(vi.cbegin(), vi.cend(), 2);

	accumulate(vi.cbegin(), vi.cend(), 0);

	string s;
	"hello" == "h";

	fill(vi.begin(), vi.end(), 20);
	fill_n(vi.begin(), vi.size(), 10);

	fill_n(back_inserter(vi), 10, 20);
	cout << vi.size() << endl;

	int arr[] = { 1, 2 };
	int arr1[sizeof(arr) / sizeof(*arr)] = {};
	copy(begin(arr), end(arr), begin(arr1));

	replace_copy(begin(arr), end(arr), back_inserter(vi), 1, 5);

	for (auto i : vi) {
		cout << i << endl;
	}

	auto f = [] {return 42; };
	cout << f() << endl;

	vector<string> vs1{ "a", "aa", "b" };
	stable_sort(vs1.begin(), vs1.end(), [](const string& s1, const string& s2) {
		return s1.size() < s2.size();
		});
	system("cls");
	for (auto& s : vs1) {
		cout << s << endl;
	}

	int sz1 = 5;
	find_if(vs1.cbegin(), vs1.cend(), [sz1](const string& s) {
		return s.size() > sz1;
		});

	for_each(vs1.cbegin(), vs1.cend(), [](const string& s) { cout << s << endl; });
	auto f2 = [&sz1] {return sz1; };

	find_if(vs1.cbegin(), vs1.cend(), [sz1](const string& s) {
		return s.size() > sz1;
		});

	auto f3 = [&sz1]() mutable -> void {
		++sz1;
	};
	f3();
	cout << sz1 << endl;

	auto f4 = [&sz1]() -> bool {
		if (sz1 == 0) {
			return true;
		}
		else {
			while (sz1 != 0) {
				--sz1;
			}
			return false;
		}
	};
	cout << f4() << endl;
	cout << f4() << endl;

	auto f5 = bind(check_size, _1, 6);
	auto f6 = bind(check_size, _2, _1);

	auto f7 = bind(myPrint, ref(cout), _1, 'a');
	f7("ss");

	string s3 = "Yuan";
	find_if(vi.cbegin(), vi.cend(), bind(check_size, ref(s3), _1));

	inserter(vi, vi.begin());
	front_inserter(vi);

	list<int> li3;
	unique_copy(vi.begin(), vi.end(), back_inserter(li3));

	istream_iterator<int> eof_iter;
	//istream_iterator<int> iiiter(cin);
	ostream_iterator<int> oiiter(cout, " ");
	
	copy(vi.cbegin(), vi.cend(), oiiter);
	cout << endl;

	ifstream ifs("a.txt");
	istream_iterator<string> iter1(ifs);
	istream_iterator<string> eof_str;
	vector<string> vs3;
	copy(iter1, eof_str, back_inserter(vs3));
	ostream_iterator<string> oiiter1(cout, " ");
	copy(vs3.cbegin(), vs3.cend(), oiiter1);
	cout << endl;

	sort(vi.rbegin(), vi.rend());

	string s5 = "a,aa,abc";
	auto comma = find(s5.crbegin(), s5.crend(), ',');
	cout << string(comma.base(), s5.cend()) << endl;

	list<string> li{ "aa", "bb", "aa" };
	li.sort();
	li.unique();
	ostream_iterator<string> oiter3(cout, " ");
	copy(li.cbegin(), li.cend(), oiter3);
	cout << endl;

	return EXIT_SUCCESS;
}