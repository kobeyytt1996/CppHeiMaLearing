#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// STL常用算法

void print01(int val) {
	cout << val << " ";
}

class Print02 {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

class MyMulti {
public:
	int time;
	MyMulti(int time) {
		this->time = time;
	}
	int operator()(int val) {
		return val * time;
	}
};

class Student41 {
public:
	int m_Age;
	Student41() {
		m_Age = 0;

	}

	Student41(int age) {
		m_Age = age;
	}
	bool operator==(const Student41& s) {
		return m_Age == s.m_Age;
	}
	// 为了binary_search而重载的
	bool operator<(const Student41& s) const {
		return m_Age < s.m_Age;
	}
	// 为了sort降序排列的
	bool operator>(const Student41& s) const {
		return m_Age > s.m_Age;
	}
};

bool judgeAge(const Student41& s) {
	return s.m_Age == 5;
}

int main41() {
	vector<int> v1(10, 500);

	// 1. 常用遍历：for_each和transfor(搬运到另一个容器中，过程中还可做些计算)
	for_each(v1.begin(), v1.end(), print01);
	for_each(v1.begin(), v1.end(), Print02());
	cout << endl;

	vector<int> v2;
	v2.resize(v1.size());
	// 注意：tranform调用前必须确保v2的size大于等于v1，所以提前resize（reserve也会报错）
	transform(v1.begin(), v1.end(), v2.begin(), MyMulti(5));
	for_each(v2.begin(), v2.end(), print01);


	// 2. 常用查找：
	// 使用find时，自定义数据类型要重载==运算符
	vector<int>::iterator it1 = find(v2.begin(), v2.end(), 2500);
	vector<Student41> v3(5, Student41(10));
	find_if(v3.begin(), v3.end(), judgeAge);
	// 查找相邻重复元素，如果有，则返回重复元素第一个的位置。第三个参数默认值为equal_to内建函数对象，所以自定义数据类型必须实现==，或者自己传第三个参数
	adjacent_find(v3.begin(), v3.end());
	// 二分查找。必须用在有序数组。第四个参数默认为less内建函数对象，因此Student41还必须重载<操作符
	binary_search(v3.begin(), v3.end(), Student41(10));
	// 下面的count和find很一致
	count(v3.begin(), v3.end(), Student41(10));
	count_if(v3.begin(), v3.end(), judgeAge);


	// 3. 常用排序：
	sort(v3.begin(), v3.end(), greater<Student41>());
	// 洗牌算法，打乱顺序。伪随机。前面依旧可以调用srand
	random_shuffle(v3.begin(), v3.end());
	// merge: 两个原容器必须是有序的，合并的两个容器才能是有序的。不是有序的会直接报错。目前还不确定自定义
	vector<int> vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	// reverse
	reverse(v3.begin(), v3.end());


	// 4. 拷贝和替换；
	vector<Student41> v4;
	v4.resize(v3.size());
	copy(v3.begin(), v3.end(), v4.begin());
	replace(v4.begin(), v4.end(), Student41(10), Student41(20));
	replace_if(v4.begin(), v4.end(), judgeAge, Student41(20));
	// swap必须是同种类型的容器.少数的直接传容器对象的 算法，因为用处广泛，比如给int
	swap(v3, v4);

	return 0;
}