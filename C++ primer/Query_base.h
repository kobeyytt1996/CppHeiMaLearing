#pragma once
#include "TextQuery.h"
#include <string>
#include "Query.h"
using namespace std;

class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;

	virtual string rep() const = 0;

};

class WordQuery : public Query_base {
	friend class Query;
	WordQuery(const string& s) : query_word(s) {}
	virtual QueryResult eval(const TextQuery& tq) const override {
		return tq.query(query_word);
	}
	virtual string rep() const override {
		return query_word;
	}
	string query_word;
};

class NotQuery : public Query_base {
	friend Query operator~(const Query&);
	NotQuery(const Query &q) : query(q) {}
	virtual QueryResult eval(const TextQuery& tq) const override;
	virtual string rep() const override {
		return "~(" + query.rep() + ")";
	}
	Query query;
};

inline
Query operator~(const Query& q) {
	return shared_ptr<Query_base>(new NotQuery(q));
}