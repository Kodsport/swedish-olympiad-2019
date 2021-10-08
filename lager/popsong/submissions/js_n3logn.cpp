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
    rep(s,p+2,sz(S)+1) {
      int len = s - p;
      rep(l,1,len/2+1) {
        if (len % l != 0) continue;
        int strs = len / l;
        rep(k,0,l) {
          char w = S[p + (l - 1 - k)];
          rep(t,0,strs) {
            int idx = p + t * l + (l - 1 - k);
            if (S[idx] != w) {
              ans = max(ans, strs * k);
              goto done;
            }
          }
        }
        ans = max(ans, strs * l);
done:;
      }
    }
  }
  cout << ans << endl;
}
