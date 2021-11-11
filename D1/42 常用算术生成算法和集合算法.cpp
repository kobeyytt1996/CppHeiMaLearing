#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
using namespace std;

// 常用算术生成算法：属于小型算法，包含在 #include <numeric>, e.g. accumulate、fill

void printInt(const int& i) {
	cout << i << endl;
}

int main42() {
	vector<int> l1(10, 50);
	vector<int> l2(10, 10);

	// 第三个参数为起始值
	cout << accumulate(l1.begin(), l1.end(), 10) << endl;
	fill(l2.begin(), l2.end(), 50);

	// 常用集合算法
	// 求两个容器的交集、并集、差集。两个容器必须是有序序列。必须提前开辟空间。返回最后一个交集、并集、差集元素的后一个位置
	vector<int> l3;
	l3.resize(min(l1.size(), l2.size()));
	set_intersection(l1.begin(), l1.end(), l2.begin(), l2.end(), l3.begin());
	vector<int> l4(l1.size() + l2.size(), 0);
	vector<int>::iterator it = set_union(l1.begin(), l1.end(), l2.begin(), l2.end(), l4.begin());
	// 差集结果和顺序有关，返回的是第一个容器中有且第二个容器中没有的
	vector<int> l5;
	l5.resize(l1.size());
	set_difference(l1.begin(), l1.end(), l2.begin(), l2.end(), l5.begin());

	for_each(l5.begin(), l5.end(), printInt);

	return 0;
}