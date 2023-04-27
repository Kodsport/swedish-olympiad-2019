#include "validator.h"

void run() {
	int t = Int(0, 10);
	assert(t == (int)Arg("t"));
	Endl();
	int n = Int(1, 1000);
	Space();
	int m = Int(1, 1000);
	Space();
	Int(2, n*m);
	Endl();

	for (int i = 0; i < n; i++) {
		SpacedInts(m, 0, 100);
	}
}
