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

	int j = 2;
	double d1 = static_cast<double>(i1) / j;

	void* p = &d1;
	double* dp = static_cast<double*>(p);

	const char* cc = nullptr;
	int c3 = static_cast<bool>(cc);

	cout << d1 << endl;

	int* ip;
	char cp = reinterpret_cast<char>(ip);

	int i3 = 10;
	double d3 = 20.0;

	i3 *= static_cast<int>(d3);

	const string* ps;
	void* pv;

	pv = static_cast<void*>(const_cast<string*>(ps));
	char* pc;

	i3 = static_cast<int>(*pc);
	pv = static_cast<void*>(&d3);
	return 0;
}