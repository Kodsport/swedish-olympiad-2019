#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
	vi e;
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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N, B;
	cin >> N >> B;
	vi values(N);
	rep(i,1,N) cin >> values[i];
	vector<vector<pii>> ed(N);
	vector<tuple<int, int, int>> eds;
	rep(i,0,N-1) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		ed[a].emplace_back(b, c);
		ed[b].emplace_back(a, c);
		eds.emplace_back(a, b, c);
	}

	int res = 0;
	rep(bi,0,(1 << (N-1))) {
		int co = 0, re = 0;
		UF uf(N);
		rep(i,0,N-1) if (bi & (1 << i)) {
			co += get<2>(eds[i]);
		} else {
			uf.join(get<0>(eds[i]), get<1>(eds[i]));
		}
		if (co > B) continue;
		rep(i,1,N) {
			if (uf.find(i) != uf.find(0))
				re += values[i];
		}
		res = max(res, re);
	}
	cout << res << endl;
}
