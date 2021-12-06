#pragma once
#include <string>
#include <set>
using namespace std;

class Message;

class Folder {
public:
	void addMsg(Message &) {}
	void remMsg(Message&) {}
};

class Message {
	friend void swap(Message& m1, Message& m2);
public:
	explicit Message(const string &s = "") : contents(s) {}

	Message(const Message &m) : contents(m.contents), folders(m.folders) {
		add_to_folder();
	}

	Message& operator=(const Message& m) {
		remove_from_folder();
		contents = m.contents;
		folders = m.folders;
		add_to_folder();
		return *this;
	}

	void save(Folder& f) {
		f.addMsg(*this);
		folders.emplace(&f);
	}

	void remove(Folder& f) {
		f.remMsg(*this);
		folders.erase(&f);
	}

	~Message() {
		remove_from_folder();
	}
private:
	string contents;
	set<Folder*> folders;

	void add_to_folder() {
		for (auto& f : folders) {
			f->addMsg(*this);
		}
	}

	void remove_from_folder() {
		for (auto& f : folders) {
			f->remMsg(*this);
		}
	}
};

void swap(Message& m1, Message& m2) {
	m1.remove_from_folder();
	m2.remove_from_folder();

	swap(m1.contents, m2.contents);
	swap(m1.folders, m2.folders);

	m1.add_to_folder();
	m2.add_to_folder();
}