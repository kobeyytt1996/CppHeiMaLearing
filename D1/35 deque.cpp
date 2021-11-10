#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

// deque ：双端数组。相比vector，头部插入删除更高效率，但查找修改要慢

void printDeque(const deque<int>& d) {
	// 传入的d为常量，则获取其迭代器必须用const_iterator
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main35() {

	// 构造：
	deque<int> d1;
	deque<int> d2(d1.begin(), d1.end());
	deque<int> d3(10, 50);
	deque<int> d4(d3);

	// 赋值：
	d1 = d3;
	d1.assign(10, 30);
	d1.assign(d3.begin(), --d3.end());

	// 大小操作：和vector相比没有capacity()，因为没有容量大小限制
	d1.empty();
	d1.size();
	d1.resize(5);
	d1.resize(10, 300);

	// 插入和删除
	d1.push_back(80);
	d1.push_front(70);
	d1.pop_back();
	d1.pop_front();
	d1.insert(d1.begin(), 20);
	d1.insert(d1.begin(), 5, 30);
	d1.insert(d1.begin(), d3.begin(), d3.end());
	d1.erase(d1.begin());
	d1.erase(d1.begin(), --d1.end());
	d1.clear();

	d1.assign(6, 60);

	// 数据存取
	d1[0] = 20;
	d1.at(1) = 10;

	// deque排序: sort默认升序。对于支持随机访问的迭代器的容器，都可以用sort，如vector、deque等
	sort(d1.begin(), d1.end());

	printDeque(d1);


	return 0;
}