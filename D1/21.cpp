#include <iostream>
#include <string>
using namespace std;

// 友元：friend 让一个函数或类访问私有属性
// 三种实现：

// 为了第14行能使用Building，先声明
class Building;

class FriendBuilding {
public:
	FriendBuilding();
	Building* building;

	void visit();
};

class Building {
	// 1. 全局函数作友元
	friend void goodGay(const Building& building);
	// 2. 类作友元
	/*friend class FriendBuilding;*/
	// 3. 成员函数作友元。因为这里要写visit，所以FriendBuilding定义要写在Building前面
	friend void FriendBuilding::visit();
public:
	Building();
public:
	string a;
private:
	string b;
};

// 类外定义成员函数

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