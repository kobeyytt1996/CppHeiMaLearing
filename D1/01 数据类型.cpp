#include <iostream>
#include <string>
using namespace std;

#define name "yuan"
#define Day 7

int main0() {
	int a = 1;
	const int b = 2;
	
	short num1 = 32768;
	int num2 = 32767;
	long num3 = 10;
	long long num4 = 10;

	// short: -32768 ~32767

	// sizeof(�������ͻ����),ռ���ڴ�ռ�Ĵ�С���ֽڣ�
	cout << sizeof(long long) << endl;

	// float 7λ��Ч���֣� double 15λ
	// float���ĩβ�Ӹ�f��ֱ��д3.13�������漰double��float��ת��
	// ��ʾ(cout)һ��С��������ʾ6λ��Ч���֣����۵�˫���ȣ�
	float num5 = 3.13f;
	double num6 = 3.13113333;

	// ��ѧ��������Ĭ����double
	float f2 = 3e2;
	float f3 = 3e-2;

	cout << sizeof(f3) << endl;

	// �ַ��ͣ�1�ֽ� ֻ�ܵ����ţ���ֻ����һ���ַ�����Ӧ��ASCII������뵽�洢��Ԫ�� a - 97, A - 65��
	char ch = 'A';

	cout << (int)ch << endl;

	// ת���ַ�(ASCII���ܴ����)��\(�������������ţ� ����\n, \\, \t(ˮƽ�Ʊ���������������������ŵ�����)
	cout << "Hello\n" << "\\" << "aa\tbb\n";

	// �ַ�����c++���) Ҫ����һ��ͷ�ļ� #include<string>
	string str = "Hello";
	// (c���Է��)
	char str2[] = "Hello World";
	
	// bool��1���ֽڡ�trueΪ1��falseΪ0��ֻҪ�Ƿ�0��ֵ����true�������Ϊ1��
	bool flag = true;
	cout << sizeof(bool) << endl;

	// �Ӽ����������ݣ�cin
	int i1 = 0;
	cout << "��ֵ��" << endl;
	cin >> i1;
	cout << "i1 = " << i1 << endl;

	bool b6 = true;
	cout << b6 << endl;

	// �����
	int a10 = 10;
	int b10 = 18;
	cout << a10 - b10 << endl;

	return 0;
}