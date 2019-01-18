#include "validator.h"
#include <set>
using namespace std;

void run() {
	int nMax = Arg("nMax");
	int mMax = Arg("mMax");
	int TMax = Arg("TMax");
	int xMax = Arg("xMax");

	int n = Int(1, nMax);
	Space();
	int m = Int(0, mMax);
	Space();
	Int(0, TMax);
	Endl();
	set<long long> S;
	long long inf = 2'000'000'000;
	for(int c1 = 0; c1 < n+m; c1++){
		int a = Int(0, xMax);
		Space();
		int b = Int(0, xMax);
		Endl();
		assert(S.find(a*inf+b) == S.end());
		S.insert(a*inf+b);
	}
}
