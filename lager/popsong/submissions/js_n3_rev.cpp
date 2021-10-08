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

  string S;
  cin >> S;

  int ans = 0;
  rep(p,0,sz(S)) {
    int left = sz(S) - p;
    for (int len = left/2 + 1; len >= 1; --len) {
      int strs = left / len;
      if (strs * len <= ans) continue;
      for (int k = len - 1; k >= 0; --k) {
        char toeq = S[p + k];
        rep(t,0,strs) {
          int idx = p + k + t * len;
          if (S[idx] != toeq) {
            strs = t;
            break;
          }
        }
        if (strs < 2) break;
        if (strs * len <= ans) break;
        ans = max(ans, strs * (len - k));
      }
    }
  }
  cout << ans << endl;
}
