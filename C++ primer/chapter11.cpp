#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool compString(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}

size_t myHash(const string& s) {
	return hash<string>()(s);
}

bool myEqual(const string& s1, const string& s2) {
	return s1.size() == s2.size();
}

int main11() {
	/*map<string, size_t> word_count;
	set<string> exclude{ "aa" };
	string word;
	while (cin >> word) {
		if (exclude.find(word) == exclude.end()) {
			++word_count[word];
		}
	}
	for (const auto& s : word_count) {
		cout << s.first << " " << s.second << endl;
	}*/

	map<string, string> authors = { {"aa", "bb"} };

	vector<int> ivec = { 1, 3, 5 };
	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());

	using functype = bool (*)(const string&, const string&);
	multiset<string, functype> sms(compString);

	pair<int, string> pis1 = { 1, "a" };
	pis1 = make_pair(5, "aa");
	pair<int, string> pis2(8, "bb");

	map<string, int>::key_type mk1;
	map<string, int>::value_type mv1{ "bb", 2 };

	auto map_it = authors.cbegin();
	while (map_it != authors.cend()) {
		++map_it;
	}

	multiset<string, functype>::const_iterator msiter2 = sms.begin();
	
	set<int> set2;
	set2.insert(ivec.cbegin(), ivec.cend());
	set2.insert({ 1, 3, 5 });
	set2.insert(4);

	authors.insert({ "aa", "dd" });
	authors.insert(make_pair("bb", "ff"));
	authors.emplace("cc", "gg");

	pair<map<string, string>::iterator, bool> insertRes = authors.insert({ "aa", "cc" });
	cout << insertRes.second << endl;

	map<string, string> authors1;
	copy(authors.cbegin(), authors.cend(), inserter(authors1, authors1.begin()));
	for_each(authors1.cbegin(), authors1.cend(), [](map<string, string>::value_type pss) {
		cout << pss.first << " " << pss.second << endl; });

	multimap<string, string> authors2{ {"aa", "bb"}, {"aa", "cc"} };
	authors2.insert(make_pair("aa", "dd"));

	map<string, vector<int>> msv;
	pair<map<string, vector<int>>::iterator, bool> pmsv = msv.insert(make_pair("aa", vector<int>{ 1, 2 }));

	auto cnt = msv.erase("cc");

	set<int> iset1{ 1, 2, 3 };
	iset1.find(1);
	multiset<int> miset1{ 1, 1 };
	miset1.count(1);

	auto cnt1 = authors2.count("aa");
	auto itera = authors2.find("aa");
	while (cnt1 > 0) {
		--cnt1;
		++itera;
	}

	for (auto range = authors2.equal_range("aa"); range.first != range.second; ++range.first) {
		cout << range.first->second << endl;
	}

	ifstream ifs("wt.txt", ifstream::in);
	map<string, string> transMap;
	string wordKey, wordMeaning;
	string word5;
	if (ifs.is_open()) {
		while (getline(ifs, word5)) {
			int index = word5.find(' ');
			wordKey = word5.substr(0, index);
			wordMeaning = word5.substr(index + 1, word5.size() - index - 1);
			transMap.insert(make_pair(wordKey, wordMeaning));
		}
	}
	ifs.close();
	ifs.clear();

	ifs.open("text.txt");
	string res, sentence, word;
	if (ifs.is_open()) {
		while (getline(ifs, sentence)) {
			istringstream iss(sentence);
			while (iss >> word) {
				if (transMap.find(word) != transMap.end()) {
					res.append(transMap[word]).append(" ");
				}
				else {
					res.append(word).append(" ");
				}
			}
			res.append("\n");
		}
	}
	ifs.close();
	ifs.clear();

	unordered_map<string, string> uomap;
	unordered_map<string, string, decltype(myHash)*, decltype(myEqual)*> uomap1(30, myHash, myEqual);

	cout << res << endl;
	
	return EXIT_SUCCESS;
}