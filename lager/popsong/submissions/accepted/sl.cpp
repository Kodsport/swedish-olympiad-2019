// O(n^2), decently optimized
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace {
vector<pii> stack;
int solve(const vi& lcp) {
	int n = sz(lcp), res = 0;
	stack.clear();
	stack.emplace_back(-1, 0);
	for (int i = 0; i < n; i++) {
		int x = lcp[i];
		int left = i;
		while (stack.back().first >= x) {
			int val = stack.back().first;
			int pos = stack.back().second;
			int len = i - pos;
			left = pos;
			res = max(res, val * (len + 1));
			stack.pop_back();
		}
		stack.push_back(pii(x, left));
	}
	while (sz(stack) > 1) {
		int val = stack.back().first;
		int len = n - stack.back().second;
		res = max(res, val * (len + 1));
		stack.pop_back();
	}
	return res;
}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string str;
	cin >> str;
	int N = sz(str);
	str += string(N, '\0');
	vi lcp;
	int res = 0;
	for (int k = 1; k <= N/2; k++) {
		lcp.clear();
		for (int i = 0; i+2*k <= N; i += k) {
			int j = 0;
			while (j < k && str[i+k-j-1] == str[i+2*k-j-1])
				j++;
			lcp.push_back(j);
		}
		res = max(res, solve(lcp));
		if (sz(lcp) == 1) { // 2x optimization (breaks early and avoids looping over vectors of size 1)
			int val = lcp[0];
			int lim = min(k, N - 2*k + 1);
			rep(j,1,lim) {
				if (str[j+k-1] == str[j+2*k-1])
					val = min(val + 1, k);
				else
					val = 0;
				res = max(res, val * 2);
			}
			continue;
		}
		rep(j,1,k) {
			for (int i = 0, i2 = 0; i+2*k <= N; i += k, i2++) {
				if (str[i+j+k-1] == str[i+j+2*k-1])
					lcp[i2] = min(lcp[i2] + 1, k);
				else
					lcp[i2] = 0;
			}
			res = max(res, solve(lcp));
		}
	}
	cout << res << endl;
}
