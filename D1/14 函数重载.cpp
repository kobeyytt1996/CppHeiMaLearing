#include <iostream>
#include <string>
using namespace std;

// ��������
	// ����������1. ͬһ������ 2. ������ͬ 3. ���������������Ͳ�ͬ
	// ����ֵ����Ϊ��������

// Ŀǰ����ȫ��������
void func14() {

}

void func14(int a) {

}


// ע�����1. ������Ϊ���������������Ƿ��constҲ��������

void func14(double& d) {
	cout << "yuan" << endl;
}

void func14(const double& d) {
	cout << "const double" << endl;
}

// 2. ������������Ĭ�ϲ��������ֶ����ԡ���Ҫ����д��

void func14(string str) {

}

void func14(string str, int b = 10) {

}

int main14() {

	const double d = 3.14;

	func14(d);


	return 0;
}