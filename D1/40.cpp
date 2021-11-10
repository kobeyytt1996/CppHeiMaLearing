#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

 // �����������غ������ò��������࣬������Ϊ��������

class MyAdd {
public:
	MyAdd() {
		m_Count = 0;
	}
	// ���Դ洢�Լ���״̬����º����������˶��ٴ�
	mutable int m_Count;
	int operator()(int i1, int i2) const {
		++m_Count;
		return i1 + i2;
	}
};

// �������������Ϊ��������
int add(const MyAdd& ma, int i1, int i2) {
	return ma(i1, i2);
}

// ν�ʣ�����ֵΪbool�ķº�����һ������ΪһԪν�ʣ���������Ϊ��Ԫν��

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

// �ڽ���������STL�ڽ��ģ������º�������ϵ�º������߼��º���
// ��Ҫ���� #include <functional>��ע�ⶼ����ģ��

// �����º�������negate��ȡ��,��ֵ����plusΪ��
// ��ϵ�º�����equal, greater, less��
// �߼��º�����֪���м���)��logical_and��logical_or��logical_not 
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
	// find_if��������ѯ��һ�����������ģ������˵�����
	// �򿪲�������ʱ������predͨ��ָ����ν��.
	cout << *find_if(v1.begin(), v1.end(), GreaterFour()) << endl;

	v1.push_back(2);
	v1.push_back(10);
	// ��Ԫν��
	sort(v1.begin(), v1.end(), MyCompare40());

	test01(v1);

	return 0;
}