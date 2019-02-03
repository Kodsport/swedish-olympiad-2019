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
	string mode = Arg("mode", "");

	int n = Int(1, Arg("nMax"));
	Space();
	int m = Int(1, Arg("mMax"));
	Space();
	int k = Int(1, Arg("kMax", n));
	Endl();

	bool line = (mode == "line");
	if (mode == "tree" || line) {
		assert(m == n-1);
	} else {
		assert(mode == "");
	}

	vector<int> special = SpacedInts(k, 1, n);
	AssertUnique(special);

	UF uf(n);
	vector<vector<int>> ed(n);
	for(int c1 = 0; c1 < m; c1++){
		int a = Int(1, n);
		Space();
		int b = Int(1, n);
		Space();
		int c = Int(1,1000000000);
		Endl();
		assert(a != b);
		uf.join(a-1, b-1);
		ed[a-1].push_back(b-1);
		ed[b-1].push_back(a-1);
	}

	// No duplicate edges
	for (int i = 0; i < n; i++) {
		AssertUnique(ed[i]);
	}

	// Connected
	assert(uf.size(0) == n);

	if (line) {
		// 0 connects to 1, 1 to 2, etc.
		// We have checked above that it's a tree, so this is sufficient.
		for (int i = 0; i < n-1; i++) {
			assert(count(ed[i].begin(), ed[i].end(), i+1) == 1);
		}
	}
}
