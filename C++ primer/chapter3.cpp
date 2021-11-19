#include <iostream>
#include <string>
using namespace std;
#include <cctype>
#include <vector>


int main3() {
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

	auto b1 = vs2.begin(), b2 = vs2.end();

	for (auto it = vs2.cbegin(); it != vs2.cend(); ++it) {

	}

	vector<int> vi3(10, 50);
	for (auto it = vi3.begin(); it != vi3.end(); ++it) {
		*it *= *it;
	}

	constexpr unsigned int ui4 = 20;

	int a1[ui4] = { 1 };
	cout << a1[1] << endl;
	char a2[] = { 'h', 'h' };
	char a3[] = "hh";
	cout << sizeof(a3) << endl;
	const char ch[4] = "hhh";

	int* ptrs[10];
	int *(&parr)[10] = ptrs;

	unsigned int uia[10] = {};

	int ia2[2] = {};
	auto ia3(ia2);
	decltype(ia2) ia5 = {};
	cout << ia5[1] << endl;
	*ia3 = 10;
	int* prr = nullptr;
	++prr;
	ia2[3];

	begin(ia2);

	int ia6[4] = {};
	cout << *(ia6 + 3) << endl;

	string s5("hello");
	const char *cc = s5.c_str();

	int int_arr[] = { 6, 4, 11 };
	vector<int> v33(begin(int_arr), end(int_arr));

	int iia[3][4] = { {1,0}, {2,2} };
	int(&row)[4] = iia[0];

	for (auto& row : iia) {
		for (auto& num : row) {

		}
	}

	return 0;
}