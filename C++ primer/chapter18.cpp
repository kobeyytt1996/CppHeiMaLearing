#include <iostream>
using namespace std;


void recoup() noexcept {
	throw exception();
}

void alloc() noexcept(false) {

}

void recoup2() noexcept(noexcept(recoup())) {

}

class out_of_stack : public runtime_error {
public:
	explicit out_of_stack(const string &s) : runtime_error(s) {}
};

class isbn_mismatch : public logic_error {
public:
	explicit isbn_mismatch(const string& msg, const string& lhs) : logic_error(msg), left(lhs) {

	}
	const string left;
};

namespace yuan_primer {
	class Query_yuan {

	};
	Query_yuan operator+(Query_yuan);
	namespace ningyu_primer {
		class Query_ningyu;
	}
}

inline namespace FifthEd {

}

int i1 = 0;
namespace {
	int i2 = 0;
}

namespace yuan = yuan_primer;

yuan_primer::Query_yuan
yuan_primer::operator+(Query_yuan) {
	return Query_yuan();
}

namespace A {
	int iA = 0;
	int move;
	class C {
		friend void f2(const C& c);
	public:
		int cMem;
	};
	/*namespace A2 {
		void A::f2(const C& c) {
			cout << "f2" << endl;
		}
	}*/
}

class virtualBase : virtual public A::C {

};

class C2 : public A::C {

};

void A::f2(const A::C& c) {
	cout << "f2" << endl;
}

namespace std {
	int i1 = 2;
}

void f1() {
	using namespace A;
	cout << iA;
}

using std::move;


int main() {
	C2 c2;
	c2.cMem;
	using std::move;
	using namespace std;
	::i1 = 10;

	try
	{

	}
	catch (const std::exception& e)
	{
		throw;
	}
	catch (...) {
		throw;
	}

	try {

	}
	catch (const exception& e) {
		cerr << e.what() << endl;
		abort();
	}

	::alloc();

	void (*pf1)() noexcept = recoup;

	A::C c;
	f2(c);
	return EXIT_SUCCESS;
}