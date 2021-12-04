#include "StrBlob.h"
#include <stdexcept>
using namespace std;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type st, const string& msg) const {
	if (st >= data->size()) {
		throw out_of_range(msg);
	}
}

void StrBlob::pop_back() {
	check(0, "pop_back");
	data->pop_back();
}

string& StrBlob::front() {
	check(0, "front");
	return data->front();
}

string& StrBlob::back() {
	check(0, "back");
	return data->back();
}