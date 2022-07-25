#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N, B;
	cin >> N >> B;
	vi pop(N), pop2(N);
	rep(i,1,N) cin >> pop[i];
	vector<vector<pii>> ed(N);
	rep(i,0,N-1) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		ed[a].emplace_back(b, c);
		ed[b].emplace_back(a, c);
	}

	vi pars(N), parcost(N);
	function<int(int, int, int)> rec = [&](int at, int par, int pc) -> int {
		parcost[at] = pc;
		pars[at] = par;
		int r = pop[at];
		trav(pa, ed[at]) if (pa.first != par) {
			r += rec(pa.first, at, pa.second);
		}
		pop2[at] = r;
		return r;
	};
	rec(0,-1,-1);

	vi dead(N);
	function<void(int)> markDead = [&](int at) {
		if (dead[at]) return;
		dead[at] = true;
		trav(pa, ed[at]) if (pa.first != pars[at]) {
			markDead(pa.first);
		}
	};

	int res = 0;
	for (;;) {
		pair<double, int> best(-1, -1);
		rep(i,1,N) if (parcost[i] <= B && !dead[i] && parcost[i]) {
			best = max(best, make_pair(pop2[i] / (double)parcost[i], i));
		}
		if (best.second == -1) break;
		int ind = best.second;

		markDead(ind);

		int pc = parcost[ind], p2 = pop2[ind];
		while (ind != -1) {
			parcost[ind] -= pc;
			pop2[ind] -= p2;
			ind = pars[ind];
		}

		B -= pc;
		res += p2;
	}
	cout << res << endl;
}
