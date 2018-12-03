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
	cin.sync_with_stdio(0);
	int T; cin >> T;
	int N, M, K;
	cin >> N >> M >> K;
	vector<vi> board(N, vi(M));
	rep(i,0,N) rep(j,0,M)
		cin >> board[i][j];

	priority_queue<tuple<int, int, int, int>> pq;
	rep(i,0,N) rep(j,0,M)
		pq.push(make_tuple(board[i][j], rand(), i, j));

	rep(it,0,K) {
		auto pa = pq.top();
		pq.pop();
		int i, j;
		tie(ignore, ignore, i, j) = pa;
		cout << i+1 << ' ' << j+1 << endl;
	}
}
