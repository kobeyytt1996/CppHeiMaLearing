#include <iostream>
using namespace std;

int main02() {

	int a1 = 10;
	int b1 = 20;

	cout << a1 / b1 << endl;

	// ����С��������ȡģ
	int d1 = 0.5;
	double d2 = 0.22;
	cout << d1 / d2 << endl;

	// �����Լ�
	int a3 = 3;
	int b3 = a3++;
	cout << b3 << endl;

	int a4 = 10;
	int b4 = ++a4 * 11;

	a4 += 10;
	b4 /= 11;

	b4 *= 10;
	cout << b4 << endl;

	a4 >= b4;
	a4 <= b4;
	
	// ע������������ȼ�
	cout << (a4 >= b4) << endl;

	// �߼��������bool��
	int i1 = 10;
	cout << !!i1 << endl;

	cout << (i1 && a4) << endl;

	cout << (i1 && 0) << endl;
	return 0;
}