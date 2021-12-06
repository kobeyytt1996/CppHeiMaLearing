#pragma once
#include "StrBlob.h"
using namespace std;

class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	
	StrBlobPtr(StrBlob &sb, size_t sz = 0) : wptr(sb.data), curr(sz) {}

	string& deref();
	StrBlobPtr& incre();

	StrBlobPtr& operator++() {
		check(curr, "operator++");
		++curr;
		return *this;
	}

	StrBlobPtr operator++(int) {
		StrBlobPtr temp = *this;
		++(*this);
		return temp;
	}

	string &operator*() const {
		auto p = check(curr, "operator*");
		return (*p)[curr];
	}

	string* operator->() const {
		return &(*(*this));
	}
private:
	shared_ptr<vector<string>> check(size_t curr,const string &msg) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};