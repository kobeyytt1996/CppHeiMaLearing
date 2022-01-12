#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Base {
public:
	virtual void mf1() = 0;

	virtual void mf1(int) {

	}

	void mf3() {

	}

	void mf3(double) {

	}
};

class Derived : public Base {
public:
	using Base::mf1;
	using Base::mf3;
	virtual void mf1() override {

	}

	void mf3() {

	}
};

class PriDe : Base {
public:
	virtual void mf1() override {
		Base::mf1();
	}
};
namespace test {
	void testFunc() {


	}
}
using test::testFunc;

class Timer {
public:
	explicit Timer(int tickFreq);
	virtual void onTick() const;
};



class Widget : private Timer {
private:
	virtual void onTick() const override;
};

class Widget1 {
private:
	class WidgetTimer : public Timer {
	public:
		virtual void onTick() const override;
	};
	WidgetTimer timer;
};

class BI {
public:
	void check() const {}
};

class EG {
private:
	void check(int) {}
};

class MP3 : public BI, public EG {};

class File {};

class InputFile : virtual public File {};

class OutputFile : virtual public File {};

class IOFile : public InputFile, public OutputFile {};

class IPerson {
public:
	virtual ~IPerson() = 0;
	virtual string name() const = 0;
};

IPerson::~IPerson() {}

class DataBaseID {};

class PersonInfo {
public:
	explicit PersonInfo(DataBaseID pid) {}
	virtual ~PersonInfo() {}
	virtual const char* theName() const {
		return "aa";
	}
private:
	virtual const char* vDO() const {
		return "[";
	}
};

class CPerson : public IPerson, private PersonInfo {
public:
	explicit CPerson(DataBaseID pid) : IPerson(), PersonInfo(pid) {}
	virtual string name() const override {
		return PersonInfo::theName();
	}
private:
	virtual const char* vDO() const override {
		return "";
	}
};


int main06() {
	Derived d;
	d.mf3(10.0);
	testFunc();

	MP3 mp3;
	mp3.BI::check();

	DataBaseID pid = DataBaseID();
	CPerson cp(pid);
	cout << cp.name() << endl;

	return 1;
}
