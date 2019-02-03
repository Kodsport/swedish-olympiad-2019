#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, M;
vector<ll> Time, dur, cost, saleTime;
map<ll, int> timeMap;

vector<ll> mem;
ll rec(int at) {
	if (at == N) return 0;
	ll &out = mem[at];
	if (out != -1) return out;
	ll res = LLONG_MAX;
	rep(it,0,2) {
		ll t = Time[at];
		if (it == 1) {
			auto it = upper_bound(all(saleTime), t);
			if (it == saleTime.begin()) continue;
			--it;
			t = *it;
		}
		rep(i,0,M) {
			int j = timeMap.lower_bound(t + dur[i])->second;
			if (j > at)
				res = min(res, (it == 1 ? cost[i] / 2 : cost[i]) + rec(j));
		}
	}
	return out = res;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int K;
	cin >> N >> M >> K;
	Time.resize(N);
	dur.resize(M);
	cost.resize(M);
	saleTime.resize(K);
	rep(i,0,N) cin >> Time[i], --Time[i];
	rep(i,0,M) cin >> dur[i];
	rep(i,0,M) cin >> cost[i];
	rep(i,0,K) cin >> saleTime[i], --saleTime[i];

	rep(i,0,N) timeMap[Time[i]] = i;
	timeMap[LLONG_MAX] = N;
	mem.assign(N, -1);

	ll r = rec(0);
	assert(r < INT_MAX);
	cout << r << endl;
}
