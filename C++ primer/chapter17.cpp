#include <iostream>
#include <tuple>
#include <string>
#include <vector>

#include <algorithm>
#include <bitset>
#include <regex>
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

	
	return EXIT_SUCCESS;
}