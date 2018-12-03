#include "validator.h"

void run() {
	int n = Int(1, Arg("nMax"));
	Space();
	int m = Int(1, Arg("mMax"));
	Space();
	int k = Int(1, n);
	Endl();

	vector<int> initial = SpacedInts(n, 1, m);
	vector<int> prices = SpacedInts(m, 1, 1000000000);

	if (Arg("allSame", 0)) {
		int x = initial[0];
		for (int y : initial) assert(x == y);
	}
	if (Arg("kEqualsN", 0)) {
		assert(n == k);
	}
	if (Arg("easyPrices", 0)) {
		for(int i = 0; i < m; i++)
			assert(prices[i] = i+1);
	}
}
