#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

struct Dish {
	int use, cost;
};

bool operator<(Dish a, Dish b) {
	return make_pair(a.cost, a.use) > make_pair(b.cost, b.use);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N, M, K, v;
	cin >> N >> M >> K;
	vector<int> avail, options;
	vector<Dish> dishes(M);
	rep(i,0,N) cin >> v, dishes[v-1].use++;
	rep(i,0,M) cin >> dishes[i].cost;
	sort(dishes.begin(), dishes.end());
	for (Dish d : dishes) {
		avail.push_back(d.cost);
		rep(it, 0, d.use) if (!avail.empty()) {
			int c = avail.back() - d.cost;
			avail.pop_back();
			options.push_back(c);
		}
	}
	if ((int)options.size() < K) {
		cout << -1 << endl;
	} else {
		nth_element(options.begin(), options.begin() + K, options.end());
		cout << accumulate(options.begin(), options.begin() + K, 0LL) << endl;
	}
}
