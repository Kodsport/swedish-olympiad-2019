#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Pos {
	ll x, y;
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int nfires, nwalls;
	ll T;
	cin >> nfires >> nwalls;
	cin >> T;
	set<ll> xs, ys;
	vector<Pos> fire(nfires), wall(nwalls);
	rep(i,0,nfires) {
		cin >> fire[i].x >> fire[i].y;
		xs.insert(fire[i].x);
		ys.insert(fire[i].y);
	}
	rep(i,0,nwalls) {
		cin >> wall[i].x >> wall[i].y;
		xs.insert(wall[i].x);
		ys.insert(wall[i].y);
	}
	assert(cin);

	const ll inf = 1100000000;

	typedef pair<ll, ll> IV;
	vector<IV> xiv, yiv;

	ll last = -inf;
	trav(x, xs) {
		if (x != last) xiv.emplace_back(last, x - 1);
		xiv.emplace_back(x, x);
		last = x + 1;
	}
	xiv.emplace_back(last, inf);

	last = -inf;
	trav(y, ys) {
		if (y != last) yiv.emplace_back(last, y - 1);
		yiv.emplace_back(y, y);
		last = y + 1;
	}
	yiv.emplace_back(last, inf);

	int H = sz(yiv), W = sz(xiv);
	vector<vi> iswall(H, vi(W));

	auto find = [&](Pos pos) -> pii {
		int xi = (int)(lower_bound(all(xiv), make_pair(pos.x, pos.x)) - begin(xiv));
		int yi = (int)(lower_bound(all(yiv), make_pair(pos.y, pos.y)) - begin(yiv));
		return {yi, xi};
	};

	rep(i,0,nwalls) {
		pii rect = find(wall[i]);
		iswall[rect.first][rect.second] = 1;
	}

	vector<vector<ll>> dists[4];
	rep(i,0,4)
		dists[i].assign(sz(yiv), vector<ll>(sz(xiv), inf));

	priority_queue<tuple<ll, pii, int>> q;
	rep(i,0,nfires) {
		pii rect = find(fire[i]);
		q.push(make_tuple(0, rect, 0));
	}

	while (!q.empty()) {
		auto pa = q.top();
		q.pop();
		ll dist;
		pii pos;
		int corner;
		tie(dist, pos, corner) = pa;
		dist = -dist;
		ll& D = dists[corner][pos.first][pos.second];
		if (D != inf) continue;
		D = dist;
		if (iswall[pos.first][pos.second]) continue;

		auto add = [&](pii pos2, int c2, ll dist2) {
			q.push(make_tuple(-dist2, pos2, c2));
		};

		ll ylo = yiv[pos.first].first;
		ll yhi = yiv[pos.first].second;
		if (ylo != -inf && yhi != inf)
			add(pos, corner ^ 1, dist + (yhi - ylo));

		ll xlo = xiv[pos.second].first;
		ll xhi = xiv[pos.second].second;
		if (xlo != -inf && xhi != inf)
			add(pos, corner ^ 2, dist + (xhi - xlo));

		add({pos.first + (corner & 1 ? 1 : -1), pos.second}, corner ^ 1, dist + 1);
		add({pos.first, pos.second + (corner & 2 ? 1 : -1)}, corner ^ 2, dist + 1);
	}

	ll res = 0;
	rep(i,0,H) rep(j,0,W) if (!iswall[i][j]) {
		// a -- b
		// |    |
		// d -- c
		ll a = max(T + 1 - dists[0][i][j], 0LL);
		ll b = max(T + 1 - dists[2][i][j], 0LL);
		ll c = max(T + 1 - dists[3][i][j], 0LL);
		ll d = max(T + 1 - dists[1][i][j], 0LL);
		ll h = yiv[i].second - yiv[i].first + 1;
		ll w = xiv[j].second - xiv[j].first + 1;

		// Just to filter out boring debug output:
		if (!a && !b && !c && !d) continue;
		if (h == 1 && w == 1) {
			res += 1;
			continue;
		}

		auto sub = [&](ll k) -> ll {
			if (k < 2) return 0;
			if (k & 1) return ((k-1)/2) * ((k-1)/2);
			else return (k/2) * (k/2-1);
		};

		ll area = h * w;
		if (a + c < w + h - 1 && b + d < w + h - 1) {
			area *= 4;

			area -= (h + w - 2 - a - c) * (h + w - 2 - b - d) * 2;

			area -= (2*(h + w - 2) - a - b - c - d) * 2;

			area -= (h + a + d) & 1;
			area -= (h + b + c) & 1;
			area -= (w + a + b) & 1;
			area -= (w + c + d) & 1;

			area += sub(w - a - b) * 4;
			area += sub(w - c - d) * 4;
			area += sub(h - a - d) * 4;
			area += sub(h - b - c) * 4;

			assert(area % 4 == 0);
			area /= 4;
		}

		res += area;
	}
	cout << res << endl;
}

