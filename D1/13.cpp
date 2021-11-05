#include <iostream>
using namespace std;

// 有默认值的参数必须在最靠右的几个
// 如果函数的多次声明和定义里只能有一个写默认参数，防止歧义
int func13(int a, int b, int c);
int func13(int a, int b, int c = 20);

// 占位参数也可以有默认值
void func133(int num, int, int = 10);

int main13() {
	// 1. 函数默认参数
	cout << func13(10, 100) << endl;

	// 2. 函数占位参数。传进去的参数完全用不到
	func133(50, 20);

	return 0;
}

int func13(int a, int b, int c) {
	return a + b + c;
}

// 占位参数
void func133(int num, int, int) {
	cout << num << endl;
}
