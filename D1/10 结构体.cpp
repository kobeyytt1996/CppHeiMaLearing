#include <iostream>
#include <string>
using namespace std;

// 结构体，一些类型的集合

struct Student {
	string name;

	int age;

	int score;
} s3;

struct Teacher {
	string name;
	Student stu;
};



// 必须在Student定义的后面声明，顺序很重要。
void printStu(const Student* stu);

int main10() {
	// 三种创建方式。不建议第三种。创建时struct可以省略。
	struct Student s1;
	struct Student s2 = { "张三", 20, 100 };
	s3.age = 20;
	// 结构体数组
	struct Student stus[] = { {"张三", 50, 100}, {"李四", 20, 80 } };
	stus[1].age = 50;
	cout << sizeof(stus) << endl;

	// 结构体指针，使用->来访问属性
	Student stu = { "张三", 50, 100 };
	Student* stuP = &stu;
	stuP->age;

	Teacher tea[5];

	// 结构体作函数参数
	printStu(&stu);

	// 请按任意键继续
	system("pause");
	// 清屏
	system("cls");

	return 0;
}

// 值传递会增加内存开销，而地址传递不会。为了防止原来数据被修改，可以加入const。
void printStu(const Student* stu) {
	cout << stu->name << endl;
	return;
}