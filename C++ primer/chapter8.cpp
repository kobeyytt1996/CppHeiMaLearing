#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

istream& read(istream& is) {
	string s;
	while (!is.eof()) {
		is >> s;
	}
	is.clear(is.rdstate() & ~is.eofbit);
	cout << "end read" << endl;
	return is;
}

int stringToInt(const string& s) {
	bool isNeg = false;
	int index = 0;
	int result = 0;
	if (s[index] == '-') {
		++index;
		isNeg = true;
	}

	while (index < s.size()) {
		result = result * 10 + (s[index] - '0');
		++index;
	}
	return isNeg ? -result : result;
}

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main08(int argc, char **argv) {
	int i = 20;
	//auto oldState = cin.rdstate();
	//while (cin >> i) {
	//	cout << i << endl;
	//}
	////cin.clear();
	//cin.clear(oldState & ~cin.badbit & ~cin.failbit);
	//cin.setstate(cin.goodbit);
	//cin >> i;
	//cout << "new" << i << endl;
	/*read(cin);
	cin >> i;*/

	cout << "hi" << flush << endl;
	cout << nounitbuf;
	
	cin.tie(&cout);
	auto oldTie = cin.tie(nullptr);
	cin.tie(&cerr);
	cin.tie(oldTie);

	ofstream ofs;
	ifstream ifs("a.txt");
	if (ofs) {
		cout << "ofs" << endl;
	}
	if (ifs) {
		cout << "ifs" << endl;
		vector<string> vs;
		string s1;
		char* cS;
		while (getline(ifs, s1)) {
			vs.push_back(s1);
		}
		for (const auto& s : vs) {
			cout << s << endl;
		}
		ifs.close();
	}

	for (auto p = argv + 1; p != argv + argc; ++p) {
		ifstream ifs(*p);
		if (ifs) {

		}
	}
	
	ofstream out("a.txt", ofstream::app | ofstream::out);

	vector<PersonInfo> vp;
	string line;
	istringstream iss;
	while (getline(cin, line)) {
		PersonInfo pi;
		iss.str(line);
		string name, number;
		iss >> name;
		pi.name = name;
		while (iss >> number) {
			pi.phones.push_back(number);
		}
		vp.push_back(pi);
	}
	

	return EXIT_SUCCESS;
}