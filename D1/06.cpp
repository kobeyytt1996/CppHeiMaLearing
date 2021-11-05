#include <iostream>
#include <string>
using namespace std;

int main06() {
	// 数组：存在一块连续的内存空间，每个元素都是相同数据类型。
	// 三种定义方式：
	int arr[] = { 1, 2, 3 };
	int arr1[5];
	int arr2[2] = { 1, 2 };

	// 一维数组名称用途：1. 统计整个数组在内存中的长度，sizeof；
	// 2. 获取数组在内存中的首地址,16进制表示，加int强转可以变成十进制显示；&是取址符号。
	bool barr[] = { true, 100 };
	cout << (int)&barr[1] << endl;
	// 数组名是个常量，不能重新赋值
	//barr = { false };

	// 二维数组：四种定义方式。第三种不好。可以省略行数，因为编译器可以根据列数来推测。
	int irr0[2][3];
	int irr1[2][3] = { {1, 2, 3}, {2, 3, 4} };
	int irr2[2][3] = { 1, 2, 3, 2, 3, 4 };
	int irr3[][4] = { 1, 2, 3, 4, 5 };

	int scores[3][3] = { {100, 100, 100}, {90, 50 ,100}, {60, 70, 80} };
	for (int i = 0; i < sizeof(scores) / sizeof((scores[0])); ++i) {
		int sum = 0;
		for (int j = 0; j < sizeof(scores[0]) / sizeof(scores[0][0]); ++j) {
			sum += scores[i][j];
		}
		cout << sum << endl;
	}

	return 0;
}