#include <iostream>
#include <vector>
using namespace std;

void printNum(unsigned int ui) {
	string s(ui, '0');
	while (s.size() < ui) {

	}
}

int main05() {
	double d = 0.0, d1 = 0.1;
	vector<int> vi1;
	for (decltype(vi1.size()) i = 0, j = vi1.size(); i != j; ++i) {

	}
	/*char ch = '\0';
	while (!(cin >> ch).eof()) {
		cout << 1 << endl;
	}*/

	int i1 = 0, i2 = 0;
	while (cin >> i1 >> i2)
	{
		try {
			if (i2 == 0) {
				throw runtime_error("³ýÊýÎª0");
			}
			cout << i1 / i2 << endl;
		}
		catch (runtime_error re) {
			cout << re.what() << endl;
		}
	}

	return 0;
}