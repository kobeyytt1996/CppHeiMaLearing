#include <iostream>
#include <string>
using namespace std;

// string���������Ǹ��࣬�ڲ���װ��char*����������ַ���

int main33() {
	// ��ʼ����ʽ��1.
	string s1;
	cout << s1 << endl;
	// 2.
	const char* chs = "aaa";
	string s2(chs);
	cout << s2 << endl;
	// 3.
	string s3(s2);
	// 4. s4��10��y���ַ���
	string s4(10, 'y');
	cout << s4 << endl;

	// ��ֵ��1.
	s4 = "hello";
	s4 = s3;
	s4 = 'a';
	s4.assign("c++");
	// ǰ�����ַ�
	s4.assign("abcde", 2);
	s4.assign(s3);
	s4.assign(10, 'w');

	// ƴ��
	s4 += "������";
	s4 += s3;
	s4 += 'a';
	s4.append("love");
	// ƴ��ǰ3��
	s4.append("game", 3);
	s4.append(s3);
	// �ӵ�1��λ��ȡ2��
	s4.append(s3, 1, 2);

	// ���Һ��滻
	// û�з���-1�����򷵻ص�һ���ҵ����ַ�����һ���ַ����±�
	s4.find("gam");
	// ���ұ߿�ʼ��
	s4.rfind("gam");
	// ��1��λ����3���ַ��滻Ϊ"1111"
	s4.replace(1, 3, "1111");

	// �Ƚϣ����ַ���ASCII��ֵ�Աȣ�����-1, 0, 1����Ҫ�������Ƿ���ȡ�
	if (s4.compare("aaa") == 0) {
		cout << "���" << endl;
	}

	// �ַ���ȡ�����ֶ��ɶ���д
	s4[0] = 98;
	s4.at(0) = 97;

	// �����ɾ��
	s4.insert(0, "yyy");
	// 0��λ����ɾ3���ַ�
	s4.erase(0, 3);

	// �Ӵ� substr: ��1�ſ�ʼȡ����
	s4.substr(1, 3);


	cout << s4 << endl;
	cout << s4.substr(1, 3) << endl;
	return 0;
}