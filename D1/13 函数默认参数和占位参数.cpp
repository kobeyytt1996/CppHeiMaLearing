#include <iostream>
using namespace std;

// ��Ĭ��ֵ�Ĳ�����������ҵļ���
// ��������Ķ�������Ͷ�����ֻ����һ��дĬ�ϲ�������ֹ����
int func13(int a, int b, int c);
int func13(int a, int b, int c = 20);

// ռλ����Ҳ������Ĭ��ֵ
void func133(int num, int, int = 10);

int main13() {
	// 1. ����Ĭ�ϲ���
	cout << func13(10, 100) << endl;

	// 2. ����ռλ����������ȥ�Ĳ�����ȫ�ò���
	func133(50, 20);

	return 0;
}

int func13(int a, int b, int c) {
	return a + b + c;
}

// ռλ����
void func133(int num, int, int) {
	cout << num << endl;
}
