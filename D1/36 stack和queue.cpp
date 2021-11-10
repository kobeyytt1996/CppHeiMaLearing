#include <iostream>
using namespace std;
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stack>
#include <queue>

// stack
// ջ�������б�����Ϊ��ֻ�������ջ��Ԫ��

// queue
// �������б�����Ϊ��ֻ������ʶ�ͷ�Ͷ�βԪ��

int main36() {
	// stack
	stack<int> s1;
	stack<int> s2(s1);

	s1.push(10);
	s1.push(20);

	while (!s1.empty()) {
		// ���Ϊ�գ�����top���׳��쳣
		cout << s1.top() << endl;
		s1.pop();
	}

	cout << s1.size() << endl;

	// queue
	queue<int> q1;
	queue<int> q2(q1);

	q1.push(30);
	q1.push(50);

	while (!q1.empty()) {
		cout << q1.front() << " " << q1.back() << " " << endl;
		q1.pop();
	}

	cout << q1.size() << endl;

	return 0;
}