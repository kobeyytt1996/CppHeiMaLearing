#include <iostream>
#include <string>
#include <vector>
using namespace std;

// vector：称为单端数组
// 数组是静态空间，vector可以动态扩展：找更大内存空间，拷贝，释放原来的
// vector的迭代器是支持随机访问的迭代器，最强大


void printVector(vector<int> v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main34() {

	// 构造:
	vector<int> v1;
	// 区间方式
	vector<int> v2(v1.begin(), v1.end());
	vector<int> v3(10, 1000);
	vector<int> v4(v3);

	// 赋值
	v1 = v3;
	v1.assign(v3.begin(), v3.end());
	v1.assign(10, 50);

	// 容量和大小
	v1.empty();
	v1.capacity();
	v1.size();
	// resize 变长用默认值填充，变短则删除末尾的
	v1.resize(15);
	// 指定填充值为100
	v1.resize(20, 100);

	// 插入和删除
	v1.push_back(1000);
	v1.pop_back();
	// 位置只能用迭代器
	v1.insert(v1.begin(), 5);
	v1.insert(v1.begin(), 3, 5);
	v1.erase(v1.begin());
	v1.erase(v1.begin(), --v1.end());
	v1.clear();

	v1.assign(v3.begin(), --v3.end());

	// 数据存取
	v1[0] = 20;
	v1.at(1) = 30;
	v1.front() = 2000;
	v1.back() = 10;

	// 互换容器：swap, 即v1和v3指向内存空间互换
	v1.swap(v3);
	// 实际用途：可以收缩内存空间。假如v1的capacity很大，但resize(3)后只有前三个数据有用，capacity却仍然很大
	v1.resize(3);
	// 使用匿名对象使得大量空间当前行执行后被回收
	vector<int>(v1).swap(v1);

	// vector预留空间 reserve：减少vector动态扩展容量的次数
	// 注意预留位置没有初始化，不可访问
	vector<int> v5;
	v2.reserve(100000);

	printVector(v1);
	printVector(v3);
	cout << v1.capacity() << endl;


	return 0;
}