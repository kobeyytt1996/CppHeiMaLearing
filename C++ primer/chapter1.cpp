#include <iostream>
using namespace std;

int main() {
	bool b = 42;
	int i = b;
	i = 3.14;
	double pi = i;
	unsigned char ch = -1;
	cout << sizeof(char) << endl;
	cout << (int)ch << endl;
	cout << (-1 % 256) << endl;
	unsigned int u = 256;
	std::cout << "good " "for" << endl;

	unsigned long ul = 345UL;
	int i1 = 1;
	i1 = { 1 };
	int i2 = 3.14;

	extern int i4;
	int i4 = 5;

	return 0;
}