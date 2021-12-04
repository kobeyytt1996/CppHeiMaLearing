#include "StrBlobPtr.h"
#include <stdexcept>
using namespace std;

shared_ptr<vector<string>> StrBlobPtr::check(size_t curr, const string& msg) const {
	auto p = wptr.lock();
	if (!p) {
		throw runtime_error(msg);
	}
	if (curr >= p->size()) {
		throw out_of_range(msg);
	}
	return p;
}

string& StrBlobPtr::deref() {
	auto p = check(curr, "deref");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incre() {
	check(curr, "incre");
	++curr;
	return *this;
}