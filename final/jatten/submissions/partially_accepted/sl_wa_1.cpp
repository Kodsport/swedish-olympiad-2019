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
	int x, y;
	Pos swap() const { return {y, x}; }
};

Pos solve(Pos bounds, Pos a, Pos b) {
	int xdif = abs(b.x - a.x);
	int ydif = abs(b.y - a.y);
	if (xdif < ydif) return solve(bounds.swap(), a.swap(), b.swap()).swap();
	if (a.x > b.x) swap(a, b);
	assert(xdif >= ydif);
	assert(xdif >= 1);

	if (bounds.y == 1 || bounds.x == 1) {
		throw false;
	}

	if (ydif == 0) {
		int ny = a.y == 0 ? 1 : a.y - 1;
		if (xdif >= 3) return {b.x-1, ny};
		int nx = a.x - 1;
		if (nx == -1) {
			nx = b.x + 1;
			if (nx == bounds.x) throw false;
		}
		return {nx, ny};
	}

	if (xdif == 1) {
		// if (a.x != 0) return {a.x-1, a.y};
		if (b.x != bounds.x-1) return {b.x+1, b.y};
		if (a.y > b.y) swap(a, b);
		if (a.y != 0) return {a.x, a.y-1};
		if (b.y != bounds.y-1) return {b.x, b.y+1};
		throw false;
	}

	return {a.x+1, a.y};
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	Pos bounds, p1, p2;
	cin >> bounds.x >> bounds.y;
	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	try {
		Pos r = solve(bounds, p1, p2);
		cout << r.x << ' ' << r.y << endl;
	} catch(bool) {
		cout << "impossible" << endl;
	}
}
