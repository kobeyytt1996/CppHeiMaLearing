#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
using namespace std;

// �������������㷨������С���㷨�������� #include <numeric>, e.g. accumulate��fill

void printInt(const int& i) {
	cout << i << endl;
}

int main42() {
	vector<int> l1(10, 50);
	vector<int> l2(10, 10);

	// ����������Ϊ��ʼֵ
	cout << accumulate(l1.begin(), l1.end(), 10) << endl;
	fill(l2.begin(), l2.end(), 50);

	// ���ü����㷨
	// �����������Ľ�����������������������������������С�������ǰ���ٿռ䡣�������һ���������������Ԫ�صĺ�һ��λ��
	vector<int> l3;
	l3.resize(min(l1.size(), l2.size()));
	set_intersection(l1.begin(), l1.end(), l2.begin(), l2.end(), l3.begin());
	vector<int> l4(l1.size() + l2.size(), 0);
	vector<int>::iterator it = set_union(l1.begin(), l1.end(), l2.begin(), l2.end(), l4.begin());
	// ������˳���йأ����ص��ǵ�һ�����������ҵڶ���������û�е�
	vector<int> l5;
	l5.resize(l1.size());
	set_difference(l1.begin(), l1.end(), l2.begin(), l2.end(), l5.begin());

	for_each(l5.begin(), l5.end(), printInt);

	return 0;
}