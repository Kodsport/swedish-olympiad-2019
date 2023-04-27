#include "validator.h"

void run() {
	long long Max = Arg("max");
	long long Min = Arg("min", 1);
	
	long long n = Int(Min, Max);
	Space();
	long long m = Int(Min, Max);
	Endl();
	
	long long x1 = Int(0, n - 1);
	Space();
	long long y1 = Int(0, m - 1);
	Space();
	long long x2 = Int(0, n - 1);
	Space();
	long long y2 = Int(0, m - 1);
	Endl();
	
	assert(x1 != x2 || y1 != y2);

	if (Arg("nosame", 0)) {
		assert(x1 != x2);
		assert(y1 != y2);
	}
}
