#pragma once
#include <vector>
#include <string>
#include <memory>

using namespace std;

class StrBlob {
public:
	friend class StrBlobPtr;
	using size_type = vector<string>::size_type;
	StrBlob();
	StrBlob(initializer_list<string> il_str);

	StrBlob(const StrBlob &sb) : data(make_shared<vector<string>>(*(sb.data))) {}

	StrBlob& operator=(const StrBlob& sb) {
		data = make_shared<vector<string>>(*sb.data);
		return *this;
	}

	bool empty() { return data->empty(); }
	bool size() { return data->size(); }

	void push_back(const string& s) { data->push_back(s); }

	void push_back(string&& s) { data->push_back(std::move(s)); }
	void pop_back();

	string& front();
	string& back();

private:
	shared_ptr<vector<string>> data;
	void check(size_type st, const string &msg) const;
};