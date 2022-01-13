#include <iterator>
#include <string>
#include <boost/smart_ptr.hpp>
#include <tuple>
#include <iostream>
#include <iterator>
#include "Rational.hpp"
using std::ostream;
using std::tuple;
using std::string;
using std::iterator_traits;
using boost::scoped_array;
using std::cout;
using std::endl;
using std::make_tuple;
using std::get;
using std::random_access_iterator_tag;
using std::bidirectional_iterator_tag;

template<typename Iterator>
void workWithIter(Iterator it) {
	typename iterator_traits<Iterator>::value_type temp(*it);
	typedef typename iterator_traits<Iterator>::value_type value_type;
	value_type temp1(*it);
}

class CA {
public:
	void sC(const string& s) {}
	void sE(const string& c);
};

class MsgInfo {};

template<typename Company>
class MsgSender {
public:
	void sC(const MsgInfo& mi) {
		string s;
		Company c;
		c.sC(s);
	}

	void sE(const MsgInfo& mi) {
		string s;
		Company c;
		c.sE(s);
	}
};

class CB {
public:
	void sE(const string& c);
};

template<>
class MsgSender<CB> {
	void sE(const MsgInfo& mi) {
		string s;
		CB c;
		c.sE(s);
	}
};

template<typename Company>
class LogMsgSender : public MsgSender<Company> {
public:
	void lSC(const MsgInfo& mi) {
		MsgSender<Company>::sC(mi);
	}
};

template<typename T>
class SMB {
protected:
	SMB(size_t n, T* pT) : size(n), ptr(pT) {}

	void setPtr(T* pT) {
		ptr = pT;
	}

	void invert(size_t n);
private:
	size_t size;
	T* ptr;
};

template<typename T>
void SMB<T>::invert(size_t n) {}

template<typename T, size_t n>
class SM : private SMB<T> {
private:
	using SMB<T>::invert;
public:
	void invert() {
		invert(n);
	}

	SM() : SMB<T>(n, nullptr), data(new T[n * n]()) {
		this->setPtr(data.get());
	}

private:
	scoped_array<T> data;
};

template<size_t IDX, size_t SIZE, typename... Types>
struct Print_tuple {
	static void print(ostream &os, const tuple<Types...>& data) {
		os << get<IDX>(data) << (IDX + 1 == SIZE ? '\0' : ',');
		Print_tuple<IDX + 1, SIZE, Types...>::print(os, data);
	}
};

template<size_t SIZE, typename...Types>
struct Print_tuple<SIZE, SIZE, Types...> {
	static void print(ostream& os, const tuple<Types...>& data) {
		
	}
};

template<typename... Types>
ostream& operator<<(ostream& os, const tuple<Types...>& data) {
	os << '[';
	Print_tuple<0, sizeof...(Types), Types...>::print(os, data);
	return os << ']';
}

template<typename T>
class SmartPtr {
public:
	explicit SmartPtr(T* realPtr);

	template<typename U>
	SmartPtr(const SmartPtr<U>& other) : pT(other.get()) {}

	SmartPtr(const SmartPtr& other);

	template<typename U>
	SmartPtr& operator=(const SmartPtr<U>& other) {
		pT = other.get();
		return *this;
	}

	T* get() const { return pT; }
private:
	T* pT;
};

template<typename T>
struct My_trait {
	typedef typename T::ic ic;
};

template<typename T>
struct My_trait<T*> {
	typedef random_access_iterator_tag ic;
};

template<typename Iter, typename Dist>
void doAdvance(Iter& iter, Dist d, random_access_iterator_tag) {
	cout << "ran" << endl;
	iter += d;
}

template<typename Iter, typename Dist>
void doAdvance(Iter& iter, Dist d, bidirectional_iterator_tag) {
	cout << "bi" << endl;
	if (d >= 0) {
		while (d--) {
			++iter;
		}
	}
	else {
		while (d++) {
			--iter;
		}
	}
}

template<typename Iter, typename Dist>
void advance(Iter& iter, Dist d) {
	doAdvance(iter, d, typename My_trait<Iter>::ic());
}

template<unsigned n>
struct factorial {
	enum { value = n * factorial<n - 1>::value };
};

template<>
struct factorial<1> {
	enum {value = 1};
};

int main07() {
	CA ca;
	MsgInfo mi;

	MsgSender<CA> ms;
	ms.sC(MsgInfo());
	LogMsgSender<CA> lms;
	lms.lSC(mi);
	
	SM<int, 5> sm;
	sm.invert();

	cout << make_tuple(10, 20, 'a') << endl;
	Rational<int> r1, r2;
	Rational<int> r3 = 5;
	r1 * r2;
	5 * r3;

	int* pI = new int();
	advance(pI, 5);
	cout << factorial<5>::value << endl;

	return 1;
}