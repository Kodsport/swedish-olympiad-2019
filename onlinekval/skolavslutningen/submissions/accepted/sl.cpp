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
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<char>> grid(N, vector<char>(M));
	map<char, vector<pii>> occ;
	rep(i,0,N) rep(j,0,M) {
		cin >> grid[i][j];
		occ[grid[i][j]].emplace_back(i, j);
	}
	UF uf(N*M);
	rep(i,0,N-1) rep(j,0,M) {
		uf.join(i*M+j, (i+1)*M+j);
	}
	trav(pa, occ) {
		int n = sz(pa.second);
		rep(i,0,n-1) {
			auto a = pa.second[i];
			auto b = pa.second[i+1];
			uf.join(a.first*M + a.second, b.first*M + b.second);
		}
	}

	int comps = 0;
	rep(i,0,N*M) if (uf.find(i) == i) comps++;
	cout << comps << endl;
}
