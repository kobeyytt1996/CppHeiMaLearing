#include <iostream>
using namespace std;

int main5() {
	// �����������ݶ����Բ�д
	int i;
	for (i = 0; i < 10; ++i) {
		cout << i << endl;
	}
	// break �� continue

	// goto����������

	cout << "1l," << endl;
	goto FLAG;

FLAG:
	cout << "very good";

	return 0;
}