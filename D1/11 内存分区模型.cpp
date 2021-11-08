#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// 全局变量
int g_a = 10;
// 全局常量
const int c_g_a = 10;


int main11() {
	// 内存分区模型：
	// 代码区：函数的二进制代码
	// 全局区：全局变量、静态变量和常量
	// 栈区：编译器自动分配释放
	// 堆区：由程序员分配和释放。程序员不释放，则程序结束时操作系统回收
	// 不同区域存放的数据，有不同的生命周期，便于管理


	/*程序编译后，生成exe可执行程序。未运行前就存在以下两个区域：
	1. 代码区：
		是CPU执行的机器指令。
		共享，只读。*/
	/*2. 全局区：
		全局变量和静态变量，还包含常量区：字符串常量和全局常量（const）
		该区域数据在程序结束后由操作系统释放*/

	// 普通局部变量
	int a = 10;
	int b = 10;

	cout << "a地址 " << (int)&a << endl;
	cout << "g_a地址 " << (int)&g_a << endl;

	// 静态变量，static
	static int s_a = 10;
	cout << "s_a地址 " << (int)&s_a << endl;

	// 字符串常量
	cout << "string地址 " << (int)&"yuan" << endl;
	// const修饰的：全局和局部
	const int c_l_a = 10;

	// 3. 栈区：形参、局部变量、局部常量
	// 注意：不要返回局部变量的地址，因会被释放。非法操作。
	
	
	// 4. 堆区：利用new在堆区开辟内存，返回地址。
	// a5指针本质上也是局部变量，是栈区；但指向的是堆区的内存
	int* a5 = new int(10);

	// 释放利用delete,释放后无权访问
	double* d5 = new double(20.0);
	delete d5;

	// 堆区开辟数组，返回首地址.delete后也加[]
	int* arr = new int[10];
	arr[0] = 10;
	delete[] arr;
	


	return 0;
}