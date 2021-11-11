#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 文件操作：通过文件可以将数据持久化
// 要包含头文件<fstream>

// 文件类型两种：
// 1. 文本文件：以文本的ASCII码形式存储在计算机中
// 2. 二进制文件：以文本的二进制形式存储在计算机中，用户一般读不懂

// 操作文件的三大类：1. ofstream 写 2. ifstream 读 3. fstream 读写

class Person {
public:
	// 涉及到写操作字符串时，尽量用c语言形式的字符串
	char m_Name[64];
};

int main28() {
	// 1. 包含头文件
	// 2. 创建流对象
	ofstream ofs;
	// 3. 打开文件：有几个打开方式。几个操作方式配合，利用|
	// 相对路径则存在于和源文件同一级目录下
	// ios::out为写文件
	// ios::trunc为把原来文件删除并创建新文件
	ofs.open("test.txt", ios::out);
	// 4. 写数据
	ofs << "性别" << endl;
	ofs << "年龄" << endl;
	// 5. 关闭文件
	ofs.close();

	// 读文件
	ifstream ifs;
	// 注意打开方式
	ifs.open("test.txt", ios::in);
	// 因为没有该文件等原因，可能打开失败
	if (ifs.is_open()) {
		// 读数据有多种方式：1.
		// 如果这里m_Name为string类型，可能把m_Name cout的时候会出现乱码，应该打开txt文件，另存为，编码格式选ANSI，之后就好了
		/*char buf[1024] = { 0 };
		while (ifs >> buf)
		{
			cout << buf << endl;
		}*/

		// 2.
		/*char buf[1024] = { 0 };
		while (ifs.getline(buf, sizeof(buf))) {
			cout << buf << endl;
		}*/

		// 3.
		/*string buf;
		while (getline(ifs, buf)) {
			cout << buf << endl;
		}*/

		// 4. 这四种方式均能正确输出中文，原因还不明
		char c;
		while ((c = ifs.get()) != EOF) // EOF: End of File
		{
			cout << c;
		}

		ifs.close();
	}
	else {
		// 无论从哪个函数调用，都相当于在main里调用return 0
		exit(0);
	}

	// 二进制文件：可用于把对象变二进制写出再读入成对象
	// 1. 写文件。二进制方式写完后，打开文件可能存在乱码。
	// 以下方式等价于先创建对象再open。打开方式为写加二进制。
	ofstream ofs1("person.txt", ios::out | ios::binary);
	
	Person p = { "员远" };
	// 易错，第一个参数指向内存中一段存储空间，注意强转
	ofs1.write((const char*)&p, sizeof(Person));
	ofs1.close();

	// 2. 读文件。
	ifstream ifs1("person.txt", ios::in | ios::binary);
	if (ifs1.is_open()) {
		Person p;
		// 参数同write
		ifs1.read((char*)&p, sizeof(Person));

		cout << p.m_Name << endl;
		ifs1.close();
	}
	
	// 判断文件是否为空
	char ch;
	ifstream ifs2("person.txt", ios::in);
	ifs2 >> ch;
	if (ifs2.is_open()) {
		// 如果为true，说明该文件为空
		if (ifs2.eof()) {

		}
		else
		{
			// 读取的单个字符放回去
			ifs2.putback(ch);
		}
		ifs2.close();
	}

	return 0;
}