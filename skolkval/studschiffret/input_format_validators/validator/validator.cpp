#include "validator.h"

void run() {
	int n = Int(2, 20);
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
}
