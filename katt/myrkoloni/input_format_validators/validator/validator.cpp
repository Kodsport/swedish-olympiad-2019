#include "validator.h"
using namespace std;

bool flag_tree = true;
vector<vector<int>> vertex;
vector<bool> used;

void dfs(int v, int fr) {
	used[v] = true;
	for (int i = 0; i < (int) vertex[v].size(); i++) {
		if (vertex[v][i] != fr) {
			if (used[vertex[v][i]]) {
				flag_tree = false;
				return;
			} else {
				dfs(vertex[v][i], v);
			}
		}
	}
}

void run() {
	int ab = Arg("ab");
	int nq = Arg("nq");

	int w = Int(1, ab);
	Space();
	int h = Int(1, ab);
	Endl();

	int n = Int(1, nq);
	Space();
	int q = Int(1, nq);
	Endl();

	set<pair<char, pair<int, int>>> edges;
	map<pair<int, int>, int> nums;
	auto getnumber = [&](int xc, int yc) -> int {
		if (nums.find(make_pair(xc, yc)) == nums.end()) {
			int tsz = (int)nums.size();
			nums[make_pair(xc, yc)] = tsz;
			vertex.emplace_back();
			used.push_back(false);
		}

		return nums[make_pair(xc, yc)];
	};

	for (int i = 0; i < n - 1; i++) {
		char tp = Char();
		Space();
		int x = Int(1, w);
		Space();
		int y = Int(1, h);
		Endl();
		assert(tp == 'h' || tp == 'v');

		assert(edges.find(make_pair(tp, make_pair(x, y))) == edges.end());
		edges.insert(make_pair(tp, make_pair(x, y)));

		int v1 = getnumber(x, y);
		if (tp == 'h')
			x++;
		if (tp == 'v')
			y++;
		assert(x >= 1 && x <= w);
		assert(y >= 1 && y <= h);
		int v2 = getnumber(x, y);

		vertex[v1].push_back(v2);
		vertex[v2].push_back(v1);
	}

	assert((int)vertex.size() == n);

	dfs(0, -1);
	for (int i = 0; i < n; i++)
		assert(used[i]);
	assert(flag_tree);

	for (int i = 0; i < q; i++) {
		int xmin = Int(1, w);
		Space();
		int ymin = Int(1, h);
		Space();
		Int(xmin, w);
		Space();
		Int(ymin, h);
		Endl();
	}
}
