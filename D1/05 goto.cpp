#include <iostream>
using namespace std;

int main5() {
	// 以下三个内容都可以不写
	int i;
	for (i = 0; i < 10; ++i) {
		cout << i << endl;
	}
	// break 和 continue

	// goto，尽量不用

	cout << "1l," << endl;
	goto FLAG;

FLAG:
	cout << "very good";

	return 0;
}