#include <bits/stdc++.h>

using namespace std;

#define rep(x, s, e) for (int x = (int)(s); x < int(e); ++x)

int main() {
  int n;
  cin >> n;
  map<string, pair<int, string>> friends;
  rep(i, 0, n) {
    string name;
    int c;
    string date;
    cin >> name >> c >> date;

    auto it = friends.find(date);
    if (it == friends.end() || c > it->second.first) {
      friends[date] = {c, name};
    }
  }

  cout << friends.size() << endl;
  vector<string> out;
  for (auto buddy : friends) {
    out.push_back(buddy.second.second);
  }
  sort(out.begin(), out.end());
  for (auto pal : out) {
    cout << pal << endl;
  }

  return 0;
}
