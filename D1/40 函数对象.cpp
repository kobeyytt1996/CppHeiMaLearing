#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

 // 函数对象：重载函数调用操作符的类，其对象称为函数对象

class MyAdd {
public:
	MyAdd() {
		m_Count = 0;
	}
	// 可以存储自己的状态，如仿函数被调用了多少次
	mutable int m_Count;
	int operator()(int i1, int i2) const {
		++m_Count;
		return i1 + i2;
	}
};

// 函数对象可以作为参数传递
int add(const MyAdd& ma, int i1, int i2) {
	return ma(i1, i2);
}

// 谓词：返回值为bool的仿函数。一个参数为一元谓词，两个参数为二元谓词

class GreaterFour {
public:
	bool operator()(int i) {
		return i > 4;
	}
};

class MyCompare40 {
public:
	bool operator()(int i1, int i2) {
		return i1 > i2;
	}
};

// 内建函数对象：STL内建的：算术仿函数、关系仿函数、逻辑仿函数
// 需要引入 #include <functional>。注意都是类模板

// 算术仿函数：以negate（取反,负值）和plus为例
// 关系仿函数：equal, greater, less等
// 逻辑仿函数（知道有即可)：logical_and，logical_or，logical_not 
void test01(vector<int>& v) {
	negate<int> n;
	cout << n(50) << endl;
	plus<int> p;
	cout << p(10, 50) << endl;
	// sort
	sort(v.begin(), v.end(), greater<int>());
}

int main40() {
	MyAdd ma;
	cout << ma(10, 20) << endl;
	cout << ma.m_Count << endl;
	cout << add(ma, 5, 5) << endl;

	vector<int> v1(10, 5);
	// find_if按条件查询第一个满足条件的，返回了迭代器
	// 打开参数提醒时，看到pred通常指传入谓词.
	cout << *find_if(v1.begin(), v1.end(), GreaterFour()) << endl;

	v1.push_back(2);
	v1.push_back(10);
	// 二元谓词
	sort(v1.begin(), v1.end(), MyCompare40());

	test01(v1);

	return 0;
}