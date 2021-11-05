#include <iostream>
#include <ctime>
using namespace std;

int main4() {
	int a, b, c;
	
	a = 20;
	b = 30;
	// 三目运算符。可以继续运算。
	(a > b) ? a : b = 100;
	cout << b << endl;

	int score = 1;
	// 注意加break跳出分支。case到break之间有多行语句要用{}。
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

	// 添加随机数种子，根据当前系统时间来生成随机数
	srand((unsigned int)time(NULL));
	// rand生成随机数再取余可控制其取值范围
	int num = rand() % 100 + 1;

	while (true) {
		cin >> record;
		if (record == num) {
			cout << "对" << endl;
			break;
		}
		else if (record > num)
		{
			cout << "大" << endl;
		}
		else
		{
			cout << "小" << endl;
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