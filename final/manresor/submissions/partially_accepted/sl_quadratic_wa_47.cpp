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
	int N, M;
	vector<int> Time, dur, cost, saleTime;
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
	dur.push_back(INT_MAX);
	cost.push_back(1 << 30);

	vi res(N+1);
	for (int i = N; i--;) {
		int r = INT_MAX;

		// no sale
		int k = 0;
		rep(j,i,N) {
			// include [i, j]
			int timeReq = Time[j] - Time[i] + 1;
			while (dur[k] < timeReq) k++;
			r = min(r, cost[k] + res[j + 1]);
		}

		// sale
		if (K > 0) {
			auto it = upper_bound(all(saleTime), Time[i]);
			if (it == saleTime.begin()) goto skip;
			--it;
			int tStart = *it;

			int k = 0;
			rep(j,i,N) {
				// include [i, j]
				int timeReq = Time[j] - tStart + 1;
				while (dur[k] < timeReq) k++;
				r = min(r, cost[k]/2 + res[j + 1]);
			}
		}
skip:

		res[i] = r;
	}

	cout << res[0] << endl;
}
