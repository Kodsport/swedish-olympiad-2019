#include "validator.h"

void run() {
	int m = 0, n = 0;
	set<int> occ;
	for (;;) {
		char c = Char();
		if (c == '\n') break;
		assert('A' <= c && c <= 'Z');
		occ.insert(c - 'A');
		m = max(m, c - 'A' + 1);
		n++;
	}

	int k = Int(1, 2);
	Endl();

	int nlim = Arg("nlim", 30);
	assert(1 <= n && n <= nlim);

	if (!Arg("sample", 0)) {
		assert(m == (int)Arg("m"));
		assert(k == (int)Arg("k"));
	}

	assert((int)occ.size() == m);
}
