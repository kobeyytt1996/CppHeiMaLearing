#pragma once
#include <iostream>
#include <string>
using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(const string &s, double d) : price(d), bookNo(s) {}
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const {
		return n * price;
	}
	virtual ~Quote() = default;
protected:
	double price = 0.0;
private:
	string bookNo;
};

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double p, size_t qty, double disc) : Quote(book, p), quantity(qty), discount(disc) {}
	virtual double net_price(size_t n) const override = 0;
private:
protected:
	size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}
	virtual double net_price(size_t n) const override;
private:
	size_t min_qty = 0;
	double discount = 0.0;
};

class NoDerived final {

};


double Bulk_quote::net_price(size_t n) const {
	return 0.0;
}

double print_total(ostream& os, const Quote& item, size_t n) {
	auto ret = item.net_price(n);
	os << item.isbn() << " " << ret << endl;
	return ret;
}