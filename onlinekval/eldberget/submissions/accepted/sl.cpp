#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	K = min(K, N + M + 7);
	vector<string> board(N);
	rep(i,0,N) {
		cin >> board[i];
	}

	queue<tuple<int, int, int, int>> q;
	q.emplace(0,0,0,0);
	vector<vector<vi>> seen(N, vector<vi>(M, vi(K+1)));
	while (!q.empty()) {
		int i, j, r, dist;
		tie(i, j, r, dist) = q.front();
		q.pop();
		if (r > K) continue;
		if (seen[i][j][r]++) continue;
		if (i == N-1 && j == M-1) {
			cout << dist << endl;
			return 0;
		}
		const int DX[4] = {0,0,1,-1};
		const int DY[4] = {1,-1,0,0};
		rep(d,0,4) {
			int ni = i + DX[d];
			int nj = j + DY[d];
			if (ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
			int nr = r + (board[ni][nj] == '#');
			q.emplace(ni, nj, nr, dist + 1);
		}
	}
	cout << "nej" << endl;
}
