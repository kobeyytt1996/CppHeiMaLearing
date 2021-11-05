#include <iostream>
#include <string>
using namespace std;

// ��Ԫ��friend ��һ�������������˽������
// ����ʵ�֣�

// Ϊ�˵�14����ʹ��Building��������
class Building;

class FriendBuilding {
public:
	FriendBuilding();
	Building* building;

	void visit();
};

class Building {
	// 1. ȫ�ֺ�������Ԫ
	friend void goodGay(const Building& building);
	// 2. ������Ԫ
	/*friend class FriendBuilding;*/
	// 3. ��Ա��������Ԫ����Ϊ����Ҫдvisit������FriendBuilding����Ҫд��Buildingǰ��
	friend void FriendBuilding::visit();
public:
	Building();
public:
	string a;
private:
	string b;
};

// ���ⶨ���Ա����

Building::Building() {
	a = "a";
	b = "b";
}

void FriendBuilding::visit() {
	cout << building->b << endl;
}

FriendBuilding::FriendBuilding() {
	building = new Building();
	/*cout << building->b << endl;*/
}

void goodGay(const Building& building) {
	cout << building.b << endl;
}

int main() {
	Building b;
	goodGay(b);

	FriendBuilding fb;
	fb.visit();

	return 0;
}