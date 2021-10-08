// Compact output so that it fits within Kattis's source code limit
// See submissions/accepted/best_contestants.cpp for a decoder.
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;

const char alphabet[] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const char* sols[11] = {
// SAMPLE
R"(
2 1
1 3
)",

// CASE 01
R"(
)",

// CASE 02
R"(
)",

// CASE 03
R"(
)",

// CASE 04
R"(
)",

// CASE 05
R"(
)",

// CASE 06
R"(
)",

// CASE 07
R"(
)",

// CASE 08
R"(
)",

// CASE 09
R"(
)",

// CASE 10
R"(
)",
};

int main() {
	cout << "const char alphabet[] = \"" << alphabet << "\";" << endl;
	cout << "const char* enc[11] = {" << endl;
	for (int i = 0; i <= 10; i++) {
		int maxx = 0, maxy = 0;
		{
			istringstream iss(sols[i]);
			int x, y;
			while (iss >> x >> y) {
				maxx = max(maxx, x);
				maxy = max(maxy, y);
			}
		}
		int n = maxx, m = maxy;
		vector<vector<int>> used(n, vector<int>(m));
		{
			istringstream iss(sols[i]);
			int x, y;
			while (iss >> x >> y) {
				assert(x > 0);
				assert(y > 0);
				used[x-1][y-1] = 1;
			}
		}
		cout << "// CASE " << i << endl;
		cout << "R\"(" << n << endl;
		// ofstream cout("grid" + to_string(i) + ".txt");
		for (int r = 0; r < n; r++) {
			int last = -1;
			for (int c = 0; c < m; c++) {
				if (used[r][c]) {
					int x = c - last;
					bool first = true;
					while (x) {
						cout << alphabet[(x & 31) | (first << 5)];
						x /= 32;
						first = false;
					}
					last = c;
				}
				// cout << (used[r][c] ? '#' : '.');
			}
			cout << endl;
		}
		cout << ")\"," << endl << endl;
	}
	cout << "};" << endl;
}
