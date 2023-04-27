#include "validator.h"
using namespace std;

void run() {
	int aexp = Arg("aexp");
	int maxa = (1 << aexp) - 1;
	int nq = Arg("nq");
	int n = Int(1, nq);
	Endl();

	SpacedInts(n, 0, maxa);

	int q = Int(0, nq);
	Endl();

	for (int i = 0; i < q; i++) {
		Int(1, n);
		Space();
		Int(0, maxa);
		Endl();
	}
}
