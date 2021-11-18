#include <iostream>
#include <string>
using namespace std;
#include <cctype>
#include <vector>


int main() {
	string s1, s2;
	
	auto i = s1.size();
	decltype(s1.size()) i1;
	s1 = s2 + "hello" + '\n' + "\"";

	for (auto &c : s1) {
		if (ispunct(c)) {
			cout << c << endl;
		}
		c = toupper(c);
	}
	s1[0] = tolower(s1[0]);

	for (auto& c : s1) {
		c = 'X';
	}

	const string s3("http");
	for (auto& c : s3) {

	}

	vector<string> v1{"a", "b"};
	vector<string> svec(20);

	cout << s1 << endl;

	vector<int> vi1;
	int i2 = 0;
	for (auto& i4 : vi1) {
		i4 *= i4;
	}

	vector<string> vs2;
	string word;
	while (cin >> i2) {
		cout << i2 << endl;
	}

	auto b1 = vs2.begin(), b2 = vs2.end();

	for (auto it = vs2.cbegin(); it != vs2.cend(); ++it) {

	}

	return 0;
}