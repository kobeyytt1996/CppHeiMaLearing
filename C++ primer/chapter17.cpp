#include <iostream>
#include <tuple>
#include <string>
#include <vector>
//#include "Sales_data.h"
#include <algorithm>
#include <bitset>
#include <regex>
#include <random>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

//typedef tuple<vector<Sales_data>::size_type,
//	vector<Sales_data>::const_iterator,
//	vector<Sales_data>::const_iterator> matches;
//
//vector<matches> findBook(const vector<vector<Sales_data>>& stores) {
//	vector<matches> ret;
//	return ret;
//}

int main() {
	tuple<string, string, int> tp1{ "a", "b", 12 };
	auto item = make_tuple("string", 1);

	cout << typeid(item).name() << endl;
	auto first = get<1>(item);
	cout << sizeof(first) << endl;

	size_t sz = tuple_size<decltype(item)>::value;
	tuple_element<1, decltype(item)>::type cnt = get<1>(item);

	tuple<int, int, int> tp2{ 10, 20, 30 };
	tuple<string, vector<int>, pair<string, int>> tp3{ "aa", {1, 2}, {"bb", 2} };

	bitset<64> bitvec(1U);
	bitvec.size();
	bitvec.count();
	bitvec.all();
	bitvec.flip(0);
	bitvec.set(bitvec.size() - 1, 0);
	bitvec.test(0);
	bitvec[0].flip();
	bitvec.to_ullong();
	cout << sizeof(bitvec) << endl;
	bitset<32> bitvec4("1100");
	string str("111000");
	bitset<16> bitvec5(str, 5);

	default_random_engine e;
	cout << e() << endl;
	uniform_int_distribution<unsigned> u(0, 9);
	cout << u(e) << endl;
	default_random_engine e2(323);
	e2.seed(333);
	e2.seed(time(nullptr));
	static default_random_engine e3;
	e3.seed(time(0));
	uniform_int_distribution<unsigned> u2(10, 90);
	cout << u2(e3) << endl;

	uniform_real_distribution<double> u3(0, 1);
	cout << u3(e3) << endl;
	uniform_int_distribution<> u4(10, 100);
	
	static normal_distribution<> u5(4, 1.5);
	cout << lround(u5(e3)) << endl;

	bernoulli_distribution bd(0.6);
	cout << bd(e3) << endl;

	cout << boolalpha << true << noboolalpha << endl;
	cout << false << endl;
	cout << showbase << uppercase;
	cout << hex << 20 << endl << nouppercase << noshowbase;

	cout << cout.precision() << " " << sqrt(2.0) << endl;
	cout << cout.precision(12) << " " << sqrt(2.0) << " ";
	cout << setprecision(3) << sqrt(2.0) << endl;
	cout << scientific << sqrt(2.0) << " " << fixed << sqrt(2.0) << endl;
	cout << showpoint << defaultfloat << 10.0 << endl;

	/*char c;
	cin >> noskipws;
	while (cin >> c) {
		cout << c;
	}
	while (cin.get(c)) {
		cout.put(c);
	}

	int ch;
	while ((ch = cin.get()) != EOF) {

	}*/
	fstream fs("copyout.txt", fstream::ate | fstream::in | fstream::out);
	if (!fs.is_open()) {
		cerr << "Wrong file" << endl;
		return EXIT_FAILURE;
	}
	auto end_mark = fs.tellg();
	string line;
	fs.seekg(0, fstream::beg);
	int num = 0;
	while (getline(fs, line)) {
		auto mark = fs.tellg();
		num += line.size() + 1;
		fs.seekp(0, fstream::end);
		fs << num << " ";
		if (mark != end_mark) {
			fs.seekg(mark);
		}
		else {
			break;
		}
	}
	fs.seekp(0, fstream::end);
	fs << '\n';
	fs.close();
	return EXIT_SUCCESS;
}

vector<unsigned> randVec() {
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0, 99);
	
	for (int i = 0; i < 100; ++i) {

	}
	
	return {};
}