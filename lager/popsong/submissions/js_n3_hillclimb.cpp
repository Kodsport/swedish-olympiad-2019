#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T = 100000000;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  string S;
  cin >> S;

  int ans = 0;
  auto dop = [&](int p) {
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
        T--;
      }
    }
  };
  for (int it = 0; it < 100; it++) {
    int x = rand() % sz(S);
    int v = ans;
    for (int jmp = 1<<20; jmp >= 1; jmp /= 2) {
      rep(itx,0,15) {
        int l = x - jmp;
        int r = x + jmp;
        if (l >= 0) {
          dop(l);
          if (ans > v) {
            v = ans;
            x = l;
          }
        }
        if (r < sz(S)) {
          dop(r);
          if (ans > v) {
            v = ans;
            x = r;
          }
        }
        if (x != l && x != r) break;
      }
    }
  }
  for (int p = 0; p < sz(S) && T >= 0; ++p) {
    dop(p);
  }
  cout << ans << endl;
}
