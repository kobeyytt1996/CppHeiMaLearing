#include <iostream>
using namespace std;

// ����
// �����ʱ��a��b���β�
int sum(int a, int b) {
	return a + b;
}

void swap(int num1, int num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
	cout << num1 << "\t" << num2 << endl;
}

int main07() {
	int a = 10, b = 20;
	// �����a��b��ʵ�Ρ�ʵ�ε�ֵ���ݸ��βΡ�
	// ��ֵ����ʱ���������βη����ı䣬ʵ�β������ı䡣��swap��ʱ�򣬻��ٸ�num1��num2�����µ��ڴ�ռ䡣
	swap(a, b);
	return 0;
}