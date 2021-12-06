#pragma once
#include <iostream>
using namespace std;

class Sales_data {
public:
	Sales_data(int unit = 0) : units_sold(unit) {}

	int units_sold;

	Sales_data& operator+=(const Sales_data& sd) {
		units_sold += sd.units_sold;
		return *this;
	}
};

ostream &operator<<(ostream& os, Sales_data& sd) {
	os << sd.units_sold;
	return os;
}

istream& operator>>(istream& is, Sales_data& sd) {
	is >> sd.units_sold;
	if (is) {

	}
	else {
		sd = Sales_data();
	}
	return is;
}

Sales_data
operator+(const Sales_data& lsd, const Sales_data& rsd) {
	Sales_data newData = lsd;
	newData += rsd;
	return newData;
}

bool operator==(const Sales_data& lhd, const Sales_data& rhd) {
	return lhd.units_sold == rhd.units_sold;
}

bool operator!=(const Sales_data& lhd, const Sales_data& rhd) {
	return !(lhd == rhd);
}
