#include "validator.h"

struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};

void run() {
	bool c1 = Arg("c1", false);
	bool line = Arg("line", false);
	bool deg2 = Arg("deg2", false);

	int n = Int(1, Arg("n"));
	Space();
	int budget = Int(1, Arg("b"));
	Endl();

	SpacedInts(n-1, 0, 30000);

	UF uf(n);
	vector<int> deg(n);
	for (int i = 0; i < n-1; i++) {
		int a = Int(1, n);
		Space();
		int b = Int(1, n);
		Space();
		int c = Int(1, budget + 1);
		Endl();
		a--, b--;
		assert(a != b);
		uf.join(a, b);
		deg[a]++;
		deg[b]++;
		if (c1) assert(c == 1);
	}

	assert(uf.size(0) == n);

	if (line) {
		for (int i = 0; i < n; i++)
			assert(deg[i] <= 2);
	}
	if (deg2) {
		// <= deg 2 when rooted
		assert(deg[0] <= 2);
		for (int i = 0; i < n; i++)
			assert(deg[i] <= 3);
	}
}
