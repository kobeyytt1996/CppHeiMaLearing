#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

// map������Ԫ�ض���pair
// ����Ԫ�ظ���keyֵ��������
// ��multimap����Ϊ�ܷ�����ظ���key

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
	// []���������ڲ��룬��������ȷ�����ڸ�keyʱ��ȡvalue��
	m1[5] = "ff";

	// ��С�ͽ���
	m1.size();
	m1.empty();
	m1.swap(m2);

	// ɾ�������˴���λ�ã����������������Դ���keyֵ
	m2.erase(m2.begin());
	m2.erase(15);
	m2.erase(m2.begin(), m2.end());

	// ���Һ�ͳ��
	// ���ص�����������������end()
	m1.find(10);
	m1.count(20);

	map<int, int, MyCompare39> m3;
	m3.insert(make_pair(10, 30));

	printMap(m2);

	return 0;
}