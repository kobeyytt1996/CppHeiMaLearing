#include <iostream>
#include <string>
#include "StrBlob.h"
#include <vector>
#include <iterator>
using namespace std;

vector<int>* getPtr() {
	return new vector<int>;
}

void read(vector<int>* vi) {
	int i = 0;
	while (cin >> i) {
		vi->push_back(i);
	}
}

void deletePtr(string* s);

void print(vector<int>* vi) {
	ostream_iterator<int> oiter(cout, " ");
	copy(vi->begin(), vi->end(), oiter);
	cout << endl;
}

int main12() {
	shared_ptr<string> sp1;
	if (sp1 && sp1->empty()) {
		*sp1 = "Hello";
	}

	shared_ptr<string> sp2 = make_shared<string>(9, 'a');
	shared_ptr<int> sp3 = make_shared<int>();

	auto sp4(sp2);
	shared_ptr<int> sp5 = make_shared<int>(10);
	sp5 = sp3;

	StrBlob str{ "aa", "bb" };
	str.push_back("cc");

	int* pi = new int();
	vector<int>* pvi0 = new vector<int>{ 1, 3 };

	auto pa = new auto(42);
	const string* const cscp = new const string;

	int* pi1 = new (nothrow) int();
	delete pi1;
	delete cscp;

	int* p(new int(40));

	/*auto pvi = getPtr();
	read(pvi);
	print(pvi);
	delete pvi;
	pvi = nullptr;*/

	shared_ptr<int> spi3(new int(40));
	shared_ptr<int> spi4 = shared_ptr<int>(new int(50));
	cout << *spi4 << endl;

	if (!spi4.unique()) {
		spi4.reset(new int(5));
	}

	shared_ptr<string> sptest(new string("a"), [](string* s) { s->clear(); });
	unique_ptr<string> up(new string(" "));
	unique_ptr<string> up1;

	unique_ptr<string> up2(up.release());
	unique_ptr<string> up3;
	up3.reset(up3.release());
	up3.release();

	unique_ptr<string, decltype(deletePtr)*> up4(new string(""), deletePtr);

	auto spi5 = make_shared<int>(10);
	weak_ptr<int> wp1 = spi5;

	if (auto spi6 = wp1.lock()) {

	}

	typedef int arrT[20];
	auto arrP = new arrT();
	delete[] arrP;

	unique_ptr<int[]> upArr(new int[20]);
	for (int i = 0; i < 20; ++i) {
		upArr[i] = 20;
	}

	shared_ptr<int> spArr(new int[20], [](int* p) {delete[] p; });

	char chArr[] = "Hello";

	allocator<string> alloc;
	string* scptr = alloc.allocate(10);
	alloc.construct(scptr++, 10, 'c');
	alloc.destroy(scptr--);
	alloc.deallocate(scptr, 10);


	return EXIT_SUCCESS;
}

unique_ptr<int> clone(int i) {
	return unique_ptr<int>(new int(i));
}

void deletePtr(string* s) {
	s->clear();
	delete s;
}