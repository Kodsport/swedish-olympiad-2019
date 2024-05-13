#include "validator.h"

void run() {
	int lo = 2, hi = 20;
	int n_is = Arg("n_is", -1);
	if(n_is != -1) lo = hi = n_is;
	int n = Int(lo, hi);
	Space();
	int m = Int(2, 20);
	Endl();

	int k = 0;
	for (;;) {
		char c = Char();
		if (c == '\n') break;
		assert('A' <= c && c <= 'Z');
		k++;
	}
	assert(1 <= k && k <= 30);
	if(Arg("no_right_wall", 0)) assert(k <= m);
}
