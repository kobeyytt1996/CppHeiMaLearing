#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <stack>
#include <queue>

class NoDefault {
public:
	NoDefault(int i) {}

	NoDefault(NoDefault &nd) {
		cout << "copy" << endl;
	}
};

void replaceString(string& s, string& oldVal, string& newVal) {

}

int main09() {
	vector<int> vi = { 1, 3, 5 };
	for (auto it = vi.begin(); it != vi.end(); ++it) {
		if (*it == 3) {
			cout << "true" << endl;
		}
	}

	vector<int>::size_type st;

	const vector<int> cv;

	list<const char*> authors{ "yuan", "zhang" };
	list<string> authors1(authors.begin(), authors.end());
	
	NoDefault no1(5);
	NoDefault no2 = 5;

	array<int, 20> arr1{};
	array<int, 20> arr2 = arr1;

	vector<string> vs2;
	list<const char*> lcc;
	vs2.assign(lcc.cbegin(), lcc.cend());

	char c[3] = "aa";

	list<int> li1;
	li1.push_front(20);

	li1.insert(li1.cbegin(), 30);

	list<int> li2{ 15, 25 };
	auto it = li1.insert(li1.begin(), li2.begin(), li2.end());
	li1.insert(it, 5);
	li1.emplace_front(3);
	li1.front() = 20;
	auto& li1End = li1.back();
	li1End = 100;

	auto it3 = li1.begin();
	while (it3 != li1.end()) {
		if ((*it3 & 0x1) == 0) {
			it3 = li1.erase(it3);
		}
		else {
			++it3;
		}
		
	}

	for (auto i : li1) {
		cout << i << endl;
	}

	int ia[] = { 0, 1, 2 };
	vector<int> vi5(begin(ia), end(ia));

	for (auto it = vi5.begin(); it != vi5.end();) {
		if (*it & 0x1) {
			it = vi5.erase(it);
		}
		else {
			++it;
		}
	}

	for (auto& i : vi5) {
		cout << i << endl;
	}

	forward_list<int> fl = { 101, 102, 103 };
	auto pre = fl.before_begin(), curr = fl.begin();
	while (curr != fl.end()) {
		if (*curr & 0x1) {
			curr = fl.erase_after(pre);
		}
		else {
			++curr;
			++pre;
		}
	}

	for (auto& i : fl) {
		cout << i << endl;
	}

	vector<int> vi6 = { 0, 1, 2, 3 };
	for (auto iter = vi6.begin(); iter != vi6.end();) {
		if (*iter & 0x1) {
			iter = vi6.emplace(iter, *iter);
			iter += 2;
		}
		else {
			iter = vi6.erase(iter);
		}
	}
	for (auto& i : vi6) {
		cout << i << endl;
	}

	const char* cp = "Hello";
	char noNull[] = { 'H', 'i' };
	string s1(cp);
	string s2(noNull, 2);
	string s3(cp + 1, 2);
	string s4(s1, 2, 3);
	string s5 = s1.substr(0, 2);
	vector<char> vc2 = { 'h', 'y' };
	string s6(vc2.data(), vc2.size());

	cout << s6 << endl;

	string s7;
	const char* cp2 = "Hello";
	s7.assign(cp2, 2);
	s7.insert(s7.size(), cp2 + 2);
	string s8;
	s8.insert(0, s7, 0, 1);
	s8.append(s7);

	cout << s8 << endl;

	auto pos = s8.find(s6);
	if (pos == string::npos) {

	}

	s8.find_first_of(s6);

	string::size_type pos1 = 0;
	while ((pos1 = s8.find_first_not_of(s6, pos1)) != string::npos) {
		cout << pos1 << endl;
		++pos1;
	}

	s8.find_last_of(s6);

	int i = 42;
	string s9 = to_string(i);
	double d3 = stoi(s9);

	vector<int> vi8;
	stack<int, vector<int>> si(vi8);

	priority_queue<int> pq;
	pq.push(10);
	pq.push(15);
	pq.push(20);

	
	return EXIT_SUCCESS;
}