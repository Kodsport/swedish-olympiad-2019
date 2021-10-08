#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, K;
vi special, isSpecial;
vector<vector<pair<int, ll>>> ed;

int furthestSpecial(int start) {
	vi seen(N);
	priority_queue<pair<ll, int>> q;
	q.push({0, start});
	pair<ll, int> far(-1, -1);
	while (!q.empty()) {
		auto pa = q.top();
		q.pop();
		ll dist = -pa.first;
		int x = pa.second;
		if (seen[x]++) continue;
		if (isSpecial[x]) far = max(far, {dist, x});
		trav(pa2, ed[x]) {
			int y = pa2.first;
			ll dist2 = dist + pa2.second;
			q.push({-dist2, y});
		}
	}
	assert(count(all(seen), 0) == 0);
	return far.second;
}

vi solve(int start) {
	vi seen(N);
	priority_queue<tuple<ll, int, int>> q;
	q.push({0, 0, start});
	vi res;
	while (!q.empty()) {
		auto pa = q.top();
		q.pop();
		ll dist = -get<0>(pa);
		int co = get<1>(pa);
		int x = get<2>(pa);
		if (seen[x]++) continue;
		co += isSpecial[x];
		if (co == K) res.push_back(x);
		trav(pa2, ed[x]) {
			int y = pa2.first;
			ll dist2 = dist + pa2.second;
			q.push({-dist2, co, y});
		}
	}
	assert(count(all(seen), 0) == 0);
	return res;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int M;
	cin >> N >> M >> K;
	special.resize(K);
	isSpecial.resize(N);
	rep(i,0,K) cin >> special[i], --special[i], isSpecial[special[i]] = 1;
	ed.resize(N);
	rep(i,0,M) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		--a, --b;
		ed[a].emplace_back(b, w);
		ed[b].emplace_back(a, w);
	}

	int a = furthestSpecial(special[0]);
	int b = furthestSpecial(a);

	vi cand(N);
	trav(x, solve(a)) cand[x] = 1;
	trav(x, solve(b)) cand[x] = 1;

	vi res;
	rep(i,0,N) if (cand[i]) {
		res.push_back(i+1);
	}
	cout << sz(res) << endl;
	trav(x, res) cout << x << ' ';
	cout << endl;
}
