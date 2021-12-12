#pragma once
#include <vector>
#include <memory>
using namespace std;

template<typename> class BlobPtr;
template<typename> class Blob;
template<typename T> bool operator==(const Blob<T>, const Blob<T>);

template<typename T>
class Blob {
	friend class Blob<T>;
	friend bool operator==<T>(const Blob<T>, const Blob<T>);
	template<typename T> friend class Fake;
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type_b;

	Blob() : data(make_shared<vector<T>>()) {}

	Blob(initializer_list<T> il) : data(make_shared<vector<T>>(vector<T>(il))) {}

	template<typename It>
	Blob(It s, It e);

	void push_back(const T& t) {
		data->push_back(t);
	}

	void push_back(T&& t) {
		data->push_back(std::move(t));
	}

	size_type_b size() const;
private:
	void check(size_type_b i, const string& msg) const;
	shared_ptr<vector<T>> data;
};


template<typename T>
void Blob<T>::check(size_type_b i, const string& msg) const {
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}

template<typename T>
template<typename It>
Blob<T>::Blob(It s, It e) : data(make_shared<vector<T>>(s, e)) {}