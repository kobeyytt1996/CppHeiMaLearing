#pragma once
#include "Blob.h"
using namespace std;

template<typename T>
class BlobPtr {
public:
	BlobPtr() : curr(0) {}
	BlobPtr(const Blob& b, size_t index = 0) : wptr(b.data), curr(index) {}

	BlobPtr& operator++(int);
private:
	weak_ptr<vector<T>> wptr;
	size_t curr;
};

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int) {
	BlobPtr res = this;
	++curr;
	return res;
}