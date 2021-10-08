#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int B;
vector<vector<pii>> ed;
vi pop;
int rec(int at, int par, int parcost, vi& dp) {
	int cover = pop[at];
	vi cp = dp;
	trav(pa, ed[at]) if (pa.first != par) {
		cover += rec(pa.first, at, pa.second, dp);
	}
	rep(b,0,B+1) if (b + parcost <= B) {
		dp[b + parcost] = max(dp[b + parcost], cp[b] + cover);
	}
	return cover;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N >> B;
	pop.resize(N);
	rep(i,1,N) cin >> pop[i];
	ed.resize(N);
	rep(it,0,N-1) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		assert(cin);
		ed[a].emplace_back(b, c);
		ed[b].emplace_back(a, c);
	}

	vector<int> dp(B+1);
	rec(0, -1, B+1, dp);
	cout << *max_element(all(dp)) << endl;
}
