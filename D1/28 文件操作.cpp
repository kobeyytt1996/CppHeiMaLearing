#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// �ļ�������ͨ���ļ����Խ����ݳ־û�
// Ҫ����ͷ�ļ�<fstream>

// �ļ��������֣�
// 1. �ı��ļ������ı���ASCII����ʽ�洢�ڼ������
// 2. �������ļ������ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�������

// �����ļ��������ࣺ1. ofstream д 2. ifstream �� 3. fstream ��д

class Person {
public:
	// �漰��д�����ַ���ʱ��������c������ʽ���ַ���
	char m_Name[64];
};

int main28() {
	// 1. ����ͷ�ļ�
	// 2. ����������
	ofstream ofs;
	// 3. ���ļ����м����򿪷�ʽ������������ʽ��ϣ�����|
	// ���·��������ں�Դ�ļ�ͬһ��Ŀ¼��
	// ios::outΪд�ļ�
	// ios::truncΪ��ԭ���ļ�ɾ�����������ļ�
	ofs.open("test.txt", ios::out);
	// 4. д����
	ofs << "�Ա�" << endl;
	ofs << "����" << endl;
	// 5. �ر��ļ�
	ofs.close();

	// ���ļ�
	ifstream ifs;
	// ע��򿪷�ʽ
	ifs.open("test.txt", ios::in);
	// ��Ϊû�и��ļ���ԭ�򣬿��ܴ�ʧ��
	if (ifs.is_open()) {
		// �������ж��ַ�ʽ��1.
		// �������m_NameΪstring���ͣ����ܰ�m_Name cout��ʱ���������룬Ӧ�ô�txt�ļ������Ϊ�������ʽѡANSI��֮��ͺ���
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

		// 4. �����ַ�ʽ������ȷ������ģ�ԭ�򻹲���
		char c;
		while ((c = ifs.get()) != EOF) // EOF: End of File
		{
			cout << c;
		}

		ifs.close();
	}
	else {
		// ���۴��ĸ��������ã����൱����main�����return 0
		exit(0);
	}

	// �������ļ��������ڰѶ���������д���ٶ���ɶ���
	// 1. д�ļ��������Ʒ�ʽд��󣬴��ļ����ܴ������롣
	// ���·�ʽ�ȼ����ȴ���������open���򿪷�ʽΪд�Ӷ����ơ�
	ofstream ofs1("person.txt", ios::out | ios::binary);
	
	Person p = { "ԱԶ" };
	// �״���һ������ָ���ڴ���һ�δ洢�ռ䣬ע��ǿת
	ofs1.write((const char*)&p, sizeof(Person));
	ofs1.close();

	// 2. ���ļ���
	ifstream ifs1("person.txt", ios::in | ios::binary);
	if (ifs1.is_open()) {
		Person p;
		// ����ͬwrite
		ifs1.read((char*)&p, sizeof(Person));

		cout << p.m_Name << endl;
		ifs1.close();
	}
	
	// �ж��ļ��Ƿ�Ϊ��
	char ch;
	ifstream ifs2("person.txt", ios::in);
	ifs2 >> ch;
	if (ifs2.is_open()) {
		// ���Ϊtrue��˵�����ļ�Ϊ��
		if (ifs2.eof()) {

		}
		else
		{
			// ��ȡ�ĵ����ַ��Ż�ȥ
			ifs2.putback(ch);
		}
		ifs2.close();
	}

	return 0;
}