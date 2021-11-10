#include <iostream>
#include <set>
#include <string>
using namespace std;

// set：关联式容器
// 底层是二叉树
// set:不可以有重复；multiset:可以有重复

// 仿函数用于给set容器指定排序规则
class MyCompare38 {
public:
	// 在VS2019中，这的函数一定要是const，否则编译不过。
	// set容器里用const引用来获取这个仿函数对象并调用compare方法，因此必须是const
	bool operator()(int a, int b) const {
		return a > b;
	}
};

class Teacher38 {
public:
	Teacher38(string name) {
		m_Name = name;
	}
	string m_Name;
};

class MyCompare381 {
public:
	bool operator()(const Teacher38& t1, const Teacher38& t2) const {
		return (t1.m_Name.compare(t2.m_Name) == 1) ? true : false;
	}
};

void printSet(set<Teacher38, MyCompare381>& s) {
	for (set<Teacher38, MyCompare381>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << it->m_Name << " ";
	}
	cout << endl;
}

int main38() {
	// 构造
	set<int> s1;
	set<int> s2(s1);

	// 插入数据只有insert方式，插入后会自动排序。返回值是pair
	s1.insert(10);
	s1.insert(5);
	// p1.insert返回插入位置，p1.second表示是否插入成功
	pair<set<int>::iterator, bool> p1 = s1.insert(5);
	s2.insert(15);

	// 大小和交换
	s1.size();
	s1.empty();
	s1.swap(s2);

	// 删除，多了可以根据数值来删除元素
	s2.erase(s2.begin(), s2.end());
	s2.erase(10);
	s2.clear();

	// 查找和统计
	// 返回迭代器，没有则返回s2.end()
	s2.find(15);
	// 对于set，结果只可能是0或1
	s2.count(10);

	// multiset
	multiset<int> s3;
	s3.insert(10);
	s3.insert(5);
	s3.insert(20);
	// 只返回迭代器，没有bool，可以重复插入
	multiset<int>::iterator it3 = s3.insert(10);

	// pair：对组
	pair<string, int> p3("yy", 20);
	pair<string, int> p4 = make_pair("ww", 30);
	cout << p4.first << p4.second << endl;

	// set容器排序：没插数据之前就要修改排序规则。用仿函数来指定。
	set<int, MyCompare38> s4;
	s4.insert(10);
	s4.insert(20);

	// 如果存的是自定义数据类型，所以必须指定仿函数
	set<Teacher38, MyCompare381> s50;
	s50.insert(Teacher38("yy")); 
	s50.insert(Teacher38("zz"));

	printSet(s50);


	return 0;
}