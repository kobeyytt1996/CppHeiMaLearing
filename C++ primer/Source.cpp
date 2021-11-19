#include <iostream>
using namespace std;
#include <vector>

int main() {
	int i = 0;
	cout << ++i << " " << ++i << endl;

	int i1 = 3.14;
	
	vector<int> vi1 = { 1, 2 };
	for (auto& i : vi1) {
		i = (i % 2 == 1) ? 2 * i : i;
 	}

	for (auto i : vi1) {
		cout << i << endl;
	}

	unsigned long ul1 = 0UL;
	ul1 |= 1UL << 27;
	ul1 = ~((~ul1) | (1UL << 27));

	return 0;
}