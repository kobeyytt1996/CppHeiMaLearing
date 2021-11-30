#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iterator>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, string::size_type sz) {
	return s.size() >= sz;
}

int main() {
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

	return EXIT_SUCCESS;
}