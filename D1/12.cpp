#include <iostream>
using namespace std;

void swap12(int& a, int& b);
int& test01();

int main12() {
	// 引用：同一块内存的两个名字，用&
	int a = 10;
	int& b = a;
	b = 20;
	cout << a << endl;

	// 引用注意事项：1. 必须初始化 2. 一旦初始化后，不可以更改来指向其他对象
	double c = 10.0;
	double& d = c;
	double e = 20.0;
	// 只能对其赋值，不能更改了，c的值也会修改
	d = e;

	// 引用作函数参数，可以简化地址传递，形参会修饰实参
	int aa = 10;
	int bb = 20;
	swap12(aa, bb);
	cout << aa << " " << bb << endl;

	// 引用作函数返回值
	// 1. 不要返回局部变量的引用,非法操作 2. 函数的调用可以作为左值
	int& ref = test01();
	cout << ref << endl;
	// 左值
	test01() = 1000;
	cout << ref << endl;

	// 引用的本质在c++内部实现是一个指针常量.但所有指针操作由编译器帮我们做。
	int& ref1 = aa;

	// 引用必须引用一块合法内存空间，不能 int& ref = 10;因为这里ref可以修改值，而10是常量

	// 常量引用: 变为只读。函数参数常用，防止误修改
	// 下一行合法原因：编译器帮我们：int temp = 10; const int& ref = temp;
	const int& ref2 = 10;
	
	return 0;
}

void swap12(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int& test01() {
	// 静态变量，全局区
	static int a = 100;
	return a;
}