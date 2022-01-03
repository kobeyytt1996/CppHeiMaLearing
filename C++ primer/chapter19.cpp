#include <iostream>
#include <functional>
using std::string;
using std::cout;
using std::endl;
#include "example19.h"

namespace std{
	class A {

	};

	class C {
		int c;
	};
}

class Base19 {
public:
	int derived = 10;
	virtual ~Base19() = default;
};

class Derived19 : public Base19 {

};

void move(std::A a) {
	std::cout << "global move" << std::endl;
}

void* operator new (size_t st) {
	if (void* mp = malloc(st)) {
		return mp;
	}
	else {
		throw std::bad_alloc();
	}
}
void operator delete(void* mp) noexcept {
	free(mp);
}

namespace {
	class A {
	public:
		virtual ~A() = default;
	};

	class B : public A {

	};

	class C : public B {

	};
}

enum class open_modes {
	input, output
};

enum color {
	red, yellow
};

enum class pepper : unsigned long {
	red, yellow
};

enum Tokens {
	tk1 = 100, tk2
};

void ff19(Tokens t) {

}

enum {floatPrec = 6, doublePrec = 10};

union Cookie {
	char cval;
	int ival;
};

class Token2 {
public:
	Token2() : tok(INT), ival(0) {}
	~Token2() {
		if (tok == STRING) {
			sval.~string();
		}
	}

	Token2& operator=(const string& s) {
		if (tok == STRING) {
			new (&sval) string(s);
		}
		else {
			sval = s;
		}
		tok = STRING;
		return *this;
	}
	enum {INT, STRING} tok;
	union 
	{
		string sval;
		int ival;
	};

	void copyUnion(const Token2& t) {
		switch (t.tok) {
		case INT:
			ival = t.ival;
			break;
		case STRING:
			new (&sval) string(t.sval);
			break;
		}
	}

	Token2& operator=(const Token2& t) {
		if (tok == STRING && t.tok != STRING) {
			sval.~string();
		}
		if (tok != STRING && t.tok == STRING) {
			sval = t.sval;
		}
		else {
			copyUnion(t);
		}
		tok = t.tok;
		return *this;
	}
};

namespace {
	class Screen {
	public:
		typedef Screen& (Screen::* Action)();
		enum Dir : int {BACK};
		Screen& back() {
			cout << "back" << endl;
			return *this;
		}

		Screen& move(Dir dir) {
			return (this->*(funcs[0]))();
		}
		
		static constexpr Action funcs[1] = {&Screen::back};
		string s1 = "aa";

		static const double Screen::* getPtr() {
			return &Screen::d1;
		}

		char getCursor(size_t st) const& {
			cout << "getCur" << endl;
			return 'A';
		}
	private:
		double d1 = 5.0;
	};
}

using PtrToMF = char(Screen::*)(size_t) const&;

void action(PtrToMF ptmf = &Screen::getCursor) {

}

typedef unsigned Bit;
struct File {
	Bit mybit1 : 2;
	Bit mybit2 : 3;
	enum modes {READ = 01, WRITE = 02};
};

int main() {
	Cookie coo{ 20 };
	coo.cval = 'c';
	ff19(tk1);
	color cl1 = red;
	pepper pp1 = pepper::red;
	constexpr color cl2 = color::red;

	const string Screen::* s2;
	s2 = &Screen::s1;

	auto ptr = Screen::getPtr();
	cout << Screen().*ptr << endl;

	Screen myScreen, * screenP;
	myScreen.*s2;
	screenP->*s2;

	char(Screen:: * pmf)(size_t) const& = &Screen::getCursor;
	(myScreen.*pmf)(10);
	
	PtrToMF pmf1 = &Screen::getCursor;
	myScreen.move(Screen::BACK);
	
	std::function<bool(const string&)> fcn1 = &string::empty;
	auto fcn2 = std::mem_fn(&string::empty);
	auto fcn3 = std::bind(&string::empty, std::placeholders::_1);
	string s20 = "aaa";
	cout << fcn3(s20) << endl;

	string* arr = new string[20];
	int *i = new int;
	std::A a1;
	move(arr);
	delete[] arr;

	string* arr1 = new string;
	arr1->~string();
	new (arr1) string("impossible");
	std::cout << *arr1 << std::endl;

	cout << sizeof(Base19) << endl;

	Base19* bp = new Derived19;
	if (Derived19* dg = dynamic_cast<Derived19*>(bp)) {
		cout << "haha" << endl;
		dg->derived = 20;
		cout << bp->derived << endl;
	}

	Base19& br = *bp;
	try {
		Derived19& dr = dynamic_cast<Derived19&>(br);
	}
	catch (std::bad_cast) {

	}
	if (typeid(*bp) == typeid(Derived19)) {
		cout << "yy" << endl;
	}

	A* a19 = new C;
	A& a20 = *a19;
	if (B* b19 = dynamic_cast<B*>(a19)) {
		cout << "curry" << endl;
	}

	Derived d1;
	Base& b1 = d1, & b2 = d1;
	equal(b1, b2);

	int ii = 50;
	cout << typeid(ii).name() << typeid(50).name() << endl;
	cout << typeid(a20).name() << endl;
	cout << typeid(*a19).name() << endl;

	return EXIT_SUCCESS;
}

