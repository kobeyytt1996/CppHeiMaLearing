#include <iostream>
using namespace std;

void swap12(int& a, int& b);
int& test01();

int main12() {
	// ���ã�ͬһ���ڴ���������֣���&
	int a = 10;
	int& b = a;
	b = 20;
	cout << a << endl;

	// ����ע�����1. �����ʼ�� 2. һ����ʼ���󣬲����Ը�����ָ����������
	double c = 10.0;
	double& d = c;
	double e = 20.0;
	// ֻ�ܶ��丳ֵ�����ܸ����ˣ�c��ֵҲ���޸�
	d = e;

	// �������������������Լ򻯵�ַ���ݣ��βλ�����ʵ��
	int aa = 10;
	int bb = 20;
	swap12(aa, bb);
	cout << aa << " " << bb << endl;

	// ��������������ֵ
	// 1. ��Ҫ���ؾֲ�����������,�Ƿ����� 2. �����ĵ��ÿ�����Ϊ��ֵ
	int& ref = test01();
	cout << ref << endl;
	// ��ֵ
	test01() = 1000;
	cout << ref << endl;

	// ���õı�����c++�ڲ�ʵ����һ��ָ�볣��.������ָ������ɱ���������������
	int& ref1 = aa;

	// ���ñ�������һ��Ϸ��ڴ�ռ䣬���� int& ref = 10;��Ϊ����ref�����޸�ֵ����10�ǳ���

	// ��������: ��Ϊֻ���������������ã���ֹ���޸�
	// ��һ�кϷ�ԭ�򣺱����������ǣ�int temp = 10; const int& ref = temp;
	const int& ref2 = 10;
	
	return 0;
}

void swap12(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int& test01() {
	// ��̬������ȫ����
	static int a = 100;
	return a;
}