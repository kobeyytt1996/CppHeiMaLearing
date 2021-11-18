#include <iostream>
#include <string>
using namespace std;
#include <cctype>

int main() {
	string s1, s2;
	
	auto i = s1.size();
	decltype(s1.size()) i1;
	s1 = s2 + "hello" + '\n' + "\"";

	for (auto c : s1) {
		if (ispunct(c)) {
			cout << c << endl;
		}
	}

	return 0;
}