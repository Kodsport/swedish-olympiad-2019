#include <bits/stdc++.h>
using namespace std;

string T;
vector<pair<char, string>> sta;
const string repls[] = {
	"A", "B", "C",
	"AA", "AB", "AC",
	"BA", "BB", "BC",
	"CA", "CB", "CC",
	"AAA", "AAB", "AAC",
	"ABA", "ABB", "ABC",
	"ACA", "ACB", "ACC",
	"BAA", "BAB", "BAC",
	"BBA", "BBB", "BBC",
	"BCA", "BCB", "BCC",
	"CAA", "CAB", "CAC",
	"CBA", "CBB", "CBC",
	"CCA", "CCB", "CCC",
};
bool foundAny = false;

bool rec(int at, int lim, const string& s) {
	if (at == lim) {
		if (s == T) {
			if (foundAny) {
				cout << endl << "Additional solution:" << endl;
			}
			for (auto pa : sta) {
				cout << pa.first << ' ' << pa.second << endl;
			}
			foundAny = true;
			return true;
		}
		return false;
	} else {
		bool ret = false;
		for (char c : "ABC") if (c) {
			for (const string& repl : repls) {
				string s2;
				for (char d : s) {
					if (d == c) s2 += repl;
					else s2 += d;
				}
				sta.emplace_back(c, repl);
				ret |= rec(at + 1, lim, s2);
				sta.pop_back();
			}
		}
		return ret;
	}
}

int main() {
	string S;
	cin >> S >> T;
	for (int limit = 0; ; limit++) {
		assert(limit <= 3);
		if (rec(0, limit, S)) break;
	}
}
