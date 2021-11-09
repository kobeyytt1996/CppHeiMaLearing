#include <iostream>
#include <string>
using namespace std;

// string：本质上是个类，内部封装了char*，管理这个字符串

int main33() {
	// 初始化方式：1.
	string s1;
	cout << s1 << endl;
	// 2.
	const char* chs = "aaa";
	string s2(chs);
	cout << s2 << endl;
	// 3.
	string s3(s2);
	// 4. s4是10个y的字符串
	string s4(10, 'y');
	cout << s4 << endl;

	// 赋值：1.
	s4 = "hello";
	s4 = s3;
	s4 = 'a';
	s4.assign("c++");
	// 前两个字符
	s4.assign("abcde", 2);
	s4.assign(s3);
	s4.assign(10, 'w');

	// 拼接
	s4 += "哈哈哈";
	s4 += s3;
	s4 += 'a';
	s4.append("love");
	// 拼接前3个
	s4.append("game", 3);
	s4.append(s3);
	// 从第1个位置取2个
	s4.append(s3, 1, 2);

	// 查找和替换
	// 没有返回-1，否则返回第一个找到的字符串第一个字符的下标
	s4.find("gam");
	// 从右边开始找
	s4.rfind("gam");
	// 从1号位置起，3个字符替换为"1111"
	s4.replace(1, 3, "1111");

	// 比较：按字符的ASCII码值对比，返回-1, 0, 1。主要用来比是否相等。
	if (s4.compare("aaa") == 0) {
		cout << "相等" << endl;
	}

	// 字符获取：两种都可读可写
	s4[0] = 98;
	s4.at(0) = 97;

	// 插入和删除
	s4.insert(0, "yyy");
	// 0个位置起删3个字符
	s4.erase(0, 3);

	// 子串 substr: 从1号开始取三个
	s4.substr(1, 3);


	cout << s4 << endl;
	cout << s4.substr(1, 3) << endl;
	return 0;
}