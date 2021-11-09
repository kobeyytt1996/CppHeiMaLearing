#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

// stl：为了建立数据结构和算法的一套标准
// standard template library:标准模板库
// 分为三部分：容器、算法和迭代器
// 六大组件：容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器

// vector

class Person {
public:
	int m_Age;
	string m_Name;
	Person(int age, string name) {
		m_Age = age;
		m_Name = name;
	}
};

void myPrint(int val) {
	cout << val << endl;
}

int main32() {

	vector<int> v;
	v.push_back(10);
	v.push_back(20);

	// 起始迭代器和结束迭代器（最后一个元素的下一个位置)
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	// 第一种遍历方式
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	// 第二种
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
	// 第三种 注意第三个参数直接传入函数名
	for_each(v.begin(), v.end(), myPrint);

	vector<Person> vP;
	vP.push_back(Person(10, "aa"));
	vP.push_back(Person(20, "bb"));
	for (vector<Person>::iterator it = vP.begin(); it != vP.end(); ++it) {
		cout << it->m_Age << it->m_Name << endl;
	}

	vector<Person*> vpp;
	vpp.push_back(new Person(10, "aa"));
	vpp.push_back(new Person(20, "bb"));
	
	// 容器嵌套容器
	vector<vector<int>> vvi;
	vector<int> v11;
	v11.push_back(111);
	vector<int> v22;
	v22.push_back(222);

	vvi.push_back(v11);
	vvi.push_back(v22);

	for (vector<vector<int>>::iterator it = vvi.begin(); it != vvi.end(); ++it) {
		for (vector<int>::iterator itt = it->begin(); itt != it->end(); ++itt) {
			cout << *itt << endl;
		}
	}

	return 0;
}