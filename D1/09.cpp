#include <iostream>
using namespace std;

void swap09(int* a, int* b);
void sort(int arr[], int len);

int main09() {
	double a = 10;
	double b = 30;

	// 指针：保存一个地址
	double* p = &a;

	cout << p << endl;

	// 指针前加*为解引用。可以进行读写。
	*p = 1000.0;

	// 32位（这里指编译器设定的操作系统，不是电脑环境，可以在上面的x86处改为x64）下指针4字节，64位下8字节
	cout << sizeof(p) << endl;

	// 空指针：用于给指针变量进行初始化，指向内存中编号为0的空间
	// 空指针不可以进行访问:0~255之间的内存编号是系统占用的，因此不允许用户访问
	double* d = NULL;
	
	// 野指针:指向非法的内存空间。和空指针都不是我们申请的空间，无权访问。
	int* p1 = (int*)0x1100;
	//cout << *p1 << endl;

	// const修饰指针
	// 常量指针：指针指向可以改，指针指向的值不可以改
	const double* cp = &a;
	// 指针常量：指针指向不可以改，指针指向的值可以改
	double* const pc = &a;
	// 既指针常量又常量指针
	const double* const cpc = NULL;

	// 指针和数组
	int arr[10] = { 1, 2, 3 };
	// 拿到首地址
	int* arrp = arr;
	// 因为是int型指针，所以++就是向后偏移4个字节
	++arrp;
	cout << *arrp << endl;

	// 指针和函数
	int num1 = 10, num2 = 20;
	swap09(&num1, &num2);
	cout << arr[1] << arr[2] << endl;

	int aii[] = { 5, 4, 3, 2, 1 };
	sort(aii, 5);
	for (int i = 0; i < 5; ++i) {
		cout << aii[i] << endl;
	}

	return 0;
}

// 地址传递。能改变实参的值。
void swap09(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 第一个参数为数组首地址，也可以写成int arr[]，更好更清晰
void sort(int* arr, int len) {
	for (int i = len - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}