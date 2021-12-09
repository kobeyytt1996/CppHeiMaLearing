#pragma once
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(const string &s, double d) : price(d), bookNo(s) {}
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const {
		return n * price;
	}

	virtual Quote* clone() const & {
		return new Quote(*this);
	}
	virtual Quote* clone() const&& {
		return new Quote(std::move(*this));
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
	using Disc_quote::Disc_quote;
	virtual double net_price(size_t n) const override;

	virtual Bulk_quote* clone() const& override{
		return new Bulk_quote(*this);
	}
	virtual Bulk_quote* clone() const&& override{
		return new Bulk_quote(std::move(*this));
	}
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

class Basket {
public:
	void add_item(const Quote& sale) {
		items.insert(shared_ptr<Quote>(sale.clone()));
	}

	void add_item(Quote&& sale) {
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}

	double total_receipt(ostream& os) const;
private:
	static bool compare(const shared_ptr<Quote>& l, const shared_ptr<Quote>& r) {
		return l->isbn() < r->isbn();
	}

	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

double Basket::total_receipt(ostream& os) const {
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}

	os << "sum is: " << sum << endl;
	return sum;
}