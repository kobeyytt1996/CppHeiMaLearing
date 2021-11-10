#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

// deque ��˫�����顣���vector��ͷ������ɾ������Ч�ʣ��������޸�Ҫ��

void printDeque(const deque<int>& d) {
	// �����dΪ���������ȡ�������������const_iterator
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main35() {

	// ���죺
	deque<int> d1;
	deque<int> d2(d1.begin(), d1.end());
	deque<int> d3(10, 50);
	deque<int> d4(d3);

	// ��ֵ��
	d1 = d3;
	d1.assign(10, 30);
	d1.assign(d3.begin(), --d3.end());

	// ��С��������vector���û��capacity()����Ϊû��������С����
	d1.empty();
	d1.size();
	d1.resize(5);
	d1.resize(10, 300);

	// �����ɾ��
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

	// ���ݴ�ȡ
	d1[0] = 20;
	d1.at(1) = 10;

	// deque����: sortĬ�����򡣶���֧��������ʵĵ���������������������sort����vector��deque��
	sort(d1.begin(), d1.end());

	printDeque(d1);


	return 0;
}