#include "validator.h"
#include <cmath>

struct Edge {
	int target;
	double proportion;
};

void assertLine(const vector<vector<Edge>>& e) {
	// Varje person skickar brev till max en person ($k \leq 1$) och tar emot brev från max en person
	vector<int> hasIn(e.size());
	for (const auto& vec : e) {
		assert(vec.size() <= 1);
		for (auto ed : vec) {
			assert(!hasIn[ed.target]);
			hasIn[ed.target] = true;
		}
	}
}

void assertTree(const vector<vector<Edge>>& e) {
	// Varje person tar emot brev från exakt en annan person, förutom person $1$ som inte tar emot från någon
	vector<int> inDeg(e.size());
	for (const auto& vec : e) for (auto ed : vec) {
		inDeg[ed.target]++;
	}
	assert(inDeg[0] == 0);
	for (size_t i = 1; i < e.size(); i++) {
		assert(inDeg[i] == 1);
	}
}

void assertSorted(const vector<vector<Edge>>& e) {
	for (int i = 0; i < (int)e.size(); ++i) {
		for (auto ed : e[i]) {
			if (ed.target <= i) {
				cout << i << " -> " << ed.target << " " << ed.proportion << " " << endl;
				assert(false);
			}
		}
	}
}

void run() {
	string mode = Arg("mode");
	int nMax = Arg("nMax");
	int mMax = Arg("mMax");

	int n = Int(1,nMax);
	Endl();

	vector<vector<Edge>> e(n);
	vector<double> cMax(n);
	vector<int> inDeg(n);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		int c = Int(0, 100'000);
		cMax[i] = c;
		Space();
		int k = Int(0, n-1);
		m += k;
		int c_tot = 0;
		set<int> outputSet;
		for (int l = 0; l < k; ++l) {
			Space();
			int j = Int(1, n);
			--j;
			Space();
			int w = Int(1, 100);
			assert(j != i);
			assert(!outputSet.count(j));
			outputSet.insert(j);
			c_tot += w;
			e[i].emplace_back(Edge{j, w/100.0});
			++inDeg[j];
		}
		Endl();
		assert(c_tot == 100 || k == 0);
	}
	assert(m <= mMax);

	vector<int> inDone(n);
	vector<double> input(n);
	queue<int> q;

	for (int i = 0; i < n; ++i) {
		if (inDeg[i] == 0) {
			input[i] = 1e18;
			q.push(i);
		}
	}

	while (q.size()) {
		int v = q.front();
		q.pop();
		double output = min(input[v], cMax[v]);
		assert(abs(input[v] - cMax[v]) > 1e-4);

		for (auto ed : e[v]) {
			int u = ed.target;
			input[u] += ed.proportion * output;
			inDone[u]++;
			if (inDone[u] == inDeg[u]) q.push(u);
		}
	}

	for (int i = 0; i < n; i++) {
		assert(inDone[i] == inDeg[i]); // no cycles
	}

	if (mode=="line") assertLine(e);
	if (mode=="sorted") assertSorted(e);
	if (mode=="tree") assertTree(e);
}
