#include <iostream>
#include <string>
#include <vector>
using namespace std;

// vector����Ϊ��������
// �����Ǿ�̬�ռ䣬vector���Զ�̬��չ���Ҹ����ڴ�ռ䣬�������ͷ�ԭ����
// vector�ĵ�������֧��������ʵĵ���������ǿ��


void printVector(vector<int> v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main34() {

	// ����:
	vector<int> v1;
	// ���䷽ʽ
	vector<int> v2(v1.begin(), v1.end());
	vector<int> v3(10, 1000);
	vector<int> v4(v3);

	// ��ֵ
	v1 = v3;
	v1.assign(v3.begin(), v3.end());
	v1.assign(10, 50);

	// �����ʹ�С
	v1.empty();
	v1.capacity();
	v1.size();
	// resize �䳤��Ĭ��ֵ��䣬�����ɾ��ĩβ��
	v1.resize(15);
	// ָ�����ֵΪ100
	v1.resize(20, 100);

	// �����ɾ��
	v1.push_back(1000);
	v1.pop_back();
	// λ��ֻ���õ�����
	v1.insert(v1.begin(), 5);
	v1.insert(v1.begin(), 3, 5);
	v1.erase(v1.begin());
	v1.erase(v1.begin(), --v1.end());
	v1.clear();

	v1.assign(v3.begin(), --v3.end());

	// ���ݴ�ȡ
	v1[0] = 20;
	v1.at(1) = 30;
	v1.front() = 2000;
	v1.back() = 10;

	// ����������swap, ��v1��v3ָ���ڴ�ռ以��
	v1.swap(v3);
	// ʵ����;�����������ڴ�ռ䡣����v1��capacity�ܴ󣬵�resize(3)��ֻ��ǰ�����������ã�capacityȴ��Ȼ�ܴ�
	v1.resize(3);
	// ʹ����������ʹ�ô����ռ䵱ǰ��ִ�к󱻻���
	vector<int>(v1).swap(v1);

	// vectorԤ���ռ� reserve������vector��̬��չ�����Ĵ���
	// ע��Ԥ��λ��û�г�ʼ�������ɷ���
	vector<int> v5;
	v2.reserve(100000);

	printVector(v1);
	printVector(v3);
	cout << v1.capacity() << endl;


	return 0;
}