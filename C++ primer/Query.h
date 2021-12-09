#pragma once
#include <string>
#include "Query_base.h"
#include <memory>
#include "TextQuery.h"
#include <iostream>
using namespace std;

class Query {
	friend Query operator~(const Query& q);

public:
	Query(const string&);
	QueryResult eval(const TextQuery& tq) const {
		return q->eval(tq);
	}

	string rep() const { return q->rep(); }
private:
	Query(const shared_ptr<Query_base> &query) : q(query) {}
	shared_ptr<Query_base> q;
};

inline
Query::Query(const string& s) : q(make_shared<WordQuery>(s)) {}

inline
ostream& operator<<(ostream& os, const Query& q) {
	return os << (q.rep());
}

