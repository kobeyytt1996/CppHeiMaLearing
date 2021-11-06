#include <iostream>
using namespace std;

class AbstractCal {
public:
	int m_A;
	int m_B;

	virtual int calculate() {
		return 0;
	}
};

class AddCal : public AbstractCal {
public:
	int m_A;
	int calculate() {
		return m_A + m_B;
	}
};

int main() {
	AddCal aCal = AddCal();
	AbstractCal ac = aCal;

	AbstractCal* ac2 = new AddCal();
	ac2->m_A = 10;
	ac2->m_B = 20;
	// 用完后记得销毁
	delete ac2;
	ac2 = NULL;
	cout << ac2->calculate() << endl;
}