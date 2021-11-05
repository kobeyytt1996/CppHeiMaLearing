#include <iostream>
#include <string>
using namespace std;

// 函数重载
	// 满足条件：1. 同一作用域 2. 名称相同 3. 参数个数，或类型不同
	// 返回值不作为调用条件

// 目前都是全局作用域
void func14() {

}

void func14(int a) {

}


// 注意事项：1. 引用作为重载条件，引用是否加const也可以重载

void func14(double& d) {
	cout << "yuan" << endl;
}

void func14(const double& d) {
	cout << "const double" << endl;
}

// 2. 函数重载碰到默认参数，出现二义性。不要这样写。

void func14(string str) {

}

void func14(string str, int b = 10) {

}

int main14() {

	const double d = 3.14;

	func14(d);


	return 0;
}