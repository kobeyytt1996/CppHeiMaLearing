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

	// sizeof(数据类型或变量),占用内存空间的大小（字节）
	cout << sizeof(long long) << endl;

	// float 7位有效数字， double 15位
	// float最好末尾加个f，直接写3.13，还会涉及double到float的转换
	// 显示(cout)一个小数，会显示6位有效数字（无论单双精度）
	float num5 = 3.13f;
	double num6 = 3.13113333;

	// 科学计数法，默认是double
	float f2 = 3e2;
	float f3 = 3e-2;

	cout << sizeof(f3) << endl;

	// 字符型，1字节 只能单引号，且只能有一个字符。对应的ASCII编码放入到存储单元。 a - 97, A - 65。
	char ch = 'A';

	cout << (int)ch << endl;

	// 转义字符(ASCII不能代表的)：\(代表输出特殊符号） 常用\n, \\, \t(水平制表符，可以整齐输出后面跟着的内容)
	cout << "Hello\n" << "\\" << "aa\tbb\n";

	// 字符串（c++风格) 要包含一个头文件 #include<string>
	string str = "Hello";
	// (c语言风格)
	char str2[] = "Hello World";
	
	// bool。1个字节。true为1，false为0，只要是非0的值都是true，都会变为1。
	bool flag = true;
	cout << sizeof(bool) << endl;

	// 从键盘输入数据：cin
	int i1 = 0;
	cout << "赋值：" << endl;
	cin >> i1;
	cout << "i1 = " << i1 << endl;

	bool b6 = true;
	cout << b6 << endl;

	// 运算符
	int a10 = 10;
	int b10 = 18;
	cout << a10 - b10 << endl;

	return 0;
}