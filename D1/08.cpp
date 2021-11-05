#include <iostream>
#include "swap.h"
using namespace std;

// 函数的声明和定义
// 声明：提前告诉编译器函数的存在。
// 声明可以有多次，定义只能有一次
int max(int a, int b);

// 函数的多文件编写：1. 头文件声明 2. 源文件定义，源文件#include "swap.h"，告诉编译器和头文件的关系 3. 使用处也包含头文件

int main08() {
	swap02(10, 20);
	return 0;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}