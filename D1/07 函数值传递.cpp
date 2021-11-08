#include <iostream>
using namespace std;

// 函数
// 定义的时候a和b是形参
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
	// 这里的a和b是实参。实参的值传递给形参。
	// 做值传递时，函数的形参发生改变，实参不发生改变。调swap的时候，会再给num1和num2开辟新的内存空间。
	swap(a, b);
	return 0;
}