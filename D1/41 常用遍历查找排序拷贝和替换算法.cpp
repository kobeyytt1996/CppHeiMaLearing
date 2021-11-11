#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// STL�����㷨

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
	// Ϊ��binary_search�����ص�
	bool operator<(const Student41& s) const {
		return m_Age < s.m_Age;
	}
	// Ϊ��sort�������е�
	bool operator>(const Student41& s) const {
		return m_Age > s.m_Age;
	}
};

bool judgeAge(const Student41& s) {
	return s.m_Age == 5;
}

int main41() {
	vector<int> v1(10, 500);

	// 1. ���ñ�����for_each��transfor(���˵���һ�������У������л�����Щ����)
	for_each(v1.begin(), v1.end(), print01);
	for_each(v1.begin(), v1.end(), Print02());
	cout << endl;

	vector<int> v2;
	v2.resize(v1.size());
	// ע�⣺tranform����ǰ����ȷ��v2��size���ڵ���v1��������ǰresize��reserveҲ�ᱨ��
	transform(v1.begin(), v1.end(), v2.begin(), MyMulti(5));
	for_each(v2.begin(), v2.end(), print01);


	// 2. ���ò��ң�
	// ʹ��findʱ���Զ�����������Ҫ����==�����
	vector<int>::iterator it1 = find(v2.begin(), v2.end(), 2500);
	vector<Student41> v3(5, Student41(10));
	find_if(v3.begin(), v3.end(), judgeAge);
	// ���������ظ�Ԫ�أ�����У��򷵻��ظ�Ԫ�ص�һ����λ�á�����������Ĭ��ֵΪequal_to�ڽ��������������Զ����������ͱ���ʵ��==�������Լ�������������
	adjacent_find(v3.begin(), v3.end());
	// ���ֲ��ҡ����������������顣���ĸ�����Ĭ��Ϊless�ڽ������������Student41����������<������
	binary_search(v3.begin(), v3.end(), Student41(10));
	// �����count��find��һ��
	count(v3.begin(), v3.end(), Student41(10));
	count_if(v3.begin(), v3.end(), judgeAge);


	// 3. ��������
	sort(v3.begin(), v3.end(), greater<Student41>());
	// ϴ���㷨������˳��α�����ǰ�����ɿ��Ե���srand
	random_shuffle(v3.begin(), v3.end());
	// merge: ����ԭ��������������ģ��ϲ���������������������ġ���������Ļ�ֱ�ӱ���Ŀǰ����ȷ���Զ���
	vector<int> vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	// reverse
	reverse(v3.begin(), v3.end());


	// 4. �������滻��
	vector<Student41> v4;
	v4.resize(v3.size());
	copy(v3.begin(), v3.end(), v4.begin());
	replace(v4.begin(), v4.end(), Student41(10), Student41(20));
	replace_if(v4.begin(), v4.end(), judgeAge, Student41(20));
	// swap������ͬ�����͵�����.������ֱ�Ӵ���������� �㷨����Ϊ�ô��㷺�������int
	swap(v3, v4);

	return 0;
}