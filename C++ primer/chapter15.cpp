#include <iostream>
using namespace std;
#include "Quote.h"

struct B {
	virtual void f1(int) const;

	virtual void f1() const;

	virtual ~B() = default;
};

struct D2 : public B {
public:
	D2(const D2 &d2) : B(d2) {}
	D2(D2 &&d2) : B(std::move(d2)) {}

	D2& operator=(const D2 &d2) {
		B::operator=(d2);
		return *this;
	}

	D2& operator=(D2&& d2) {
		B::operator=(std::move(d2));
		return *this;
	}
	using B::f1;
	void f1(int) const override final;
};

struct D3 : D2 {
	//void f1(int) const override;
};

class Base {
public:
	size_t size() const {}
};

class Derived : private Base {
public:
	using Base::size;
};

int main() {
	Bulk_quote bq;
	Quote& qr = bq;
	Quote* qp = &bq;
	Quote q1;
	q1 = bq;

	shared_ptr<Quote> spq = make_shared<Bulk_quote>();

	Bulk_quote* bqp = static_cast<Bulk_quote*>(qp);
	bqp->Quote::net_price(5);
	
	

	return EXIT_SUCCESS;
}