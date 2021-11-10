#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

// map：所有元素都是pair
// 所有元素根据key值进行排序
// 和multimap区别为能否插入重复的key

class MyCompare39 {
public:
	bool operator()(int a, int b) const {
		return a > b;
	}
};

void printMap(const map<int, string>& m) {
	for (map<int, string>::const_iterator it = m.begin(); it != m.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
}

int main39() {
	map<int, string> m1;
	map<int, string> m2(m1);

	m1.insert(pair<int, string>(10, "yy"));
	m1.insert(make_pair(20, "zz"));
	m1.insert(map<int, string>::value_type(15, "kk"));
	// []不建议用于插入，更多用于确定存在该key时，取value。
	m1[5] = "ff";

	// 大小和交换
	m1.size();
	m1.empty();
	m1.swap(m2);

	// 删除，除了传入位置（迭代器），还可以传入key值
	m2.erase(m2.begin());
	m2.erase(15);
	m2.erase(m2.begin(), m2.end());

	// 查找和统计
	// 返回迭代器，不存在则是end()
	m1.find(10);
	m1.count(20);

	map<int, int, MyCompare39> m3;
	m3.insert(make_pair(10, 30));

	printMap(m2);

	return 0;
}