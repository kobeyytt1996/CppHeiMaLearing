#include <iostream>
#include <ctime>
using namespace std;

int main4() {
	int a, b, c;
	
	a = 20;
	b = 30;
	// ��Ŀ����������Լ������㡣
	(a > b) ? a : b = 100;
	cout << b << endl;

	int score = 1;
	// ע���break������֧��case��break֮���ж������Ҫ��{}��
	switch (score) {
		case true: 
			cout << "1" << endl;
			cout << "true" << endl;
			break;
		case false:
			cout << "false" << endl;
			break;
		default:
			cout << "nothing" << endl;
			break;
	}
	
	int record;

	// �����������ӣ����ݵ�ǰϵͳʱ�������������
	srand((unsigned int)time(NULL));
	// rand�����������ȡ��ɿ�����ȡֵ��Χ
	int num = rand() % 100 + 1;

	while (true) {
		cin >> record;
		if (record == num) {
			cout << "��" << endl;
			break;
		}
		else if (record > num)
		{
			cout << "��" << endl;
		}
		else
		{
			cout << "С" << endl;
		}
	}

	int yuan = 100;
	int a1, a2, a3;
	do {
		a1 = yuan / 100;
		a2 = yuan % 100 / 10;
		a3 = yuan % 10;
		if (yuan == a1 * a1 * a1 + a2 * a2 * a2 + a3 * a3 * a3) {
			cout << yuan << endl;
		}
		yuan++;
	} while (yuan < 1000);

	return 0;
}