#include "validator.h"
using namespace std;

void run() {
	int nMax = Arg("nMax");
	int xMax = Arg("xMax");
	int n = Int(2, nMax);
	Endl();
	set<long long> S;
	long long inf = 2000000000;
	for(int c1 = 0; c1 < n; c1++){
		int a = Int(0, xMax);
		Space();
		int b = Int(0, xMax);
		Endl();
		assert(S.find(a*inf+b) == S.end());
		S.insert(a*inf+b);
	}
}
