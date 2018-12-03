#include <bits/stdc++.h>
using namespace std;

#define rep(a, b, c) for(int a = (b); a < (c); a++)
#define all(v) v.begin(), v.end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9, mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<pii> v(m, {0, 0}); // {price, orders}
  rep(i, 0, n) {
    int x;
    cin >> x;
    v[x-1].second ++;
  }
  rep(i, 0, m)
    cin >> v[i].first;
  sort(all(v));
  // note that menu items which have not been ordered will end up
  // before ordered menu items of the same cost.

  int unique = 0;
  rep(i, 0, m)
    unique += v[i].second != 0;

  priority_queue<int, vi, greater<int>> moves;
  for(int i = m; i --> 0;)
    for(int j = i; j < m && v[i].second > 1; j++)
      if (v[j].second == 0) {
        v[j].second ++;
        v[i].second --;
        moves.push(v[j].first - v[i].first);
      }

  ll ans = 0;
  while (unique < k && !moves.empty()) {
    ans += moves.top();
    moves.pop();
    unique ++;
  }

  if (unique >= k)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}