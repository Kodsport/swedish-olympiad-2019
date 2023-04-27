#include <bits/stdc++.h>
using namespace std;

struct Node {
	int x;
	int y;
};

vector<Node> nodes;

int64_t dist(const Node& a, const Node& b) {
	int64_t dx = a.x - b.x;
	int64_t dy = a.y - b.y;
	return dx * dx + dy * dy;
}

int memo[2001][2001];

int dp(int n1, int n2) {
	if (memo[n1][n2] != -1)
		return memo[n1][n2];
	
	int64_t d0 = dist(nodes[n1], nodes[n2]);
	
	int ans = 0;
	for (int i = 0; i < nodes.size(); i++) {
		if (i != n1 && i != n2 && dist(nodes[n2], nodes[i]) > d0) {
			ans = max(ans, dp(n2, i) + 1);
		}
	}
	
	return memo[n1][n2] = ans;
}

int main() {
	int N;
	cin >> N;
	if (N > 200)
		return 1;
	
	nodes.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> nodes[i].x >> nodes[i].y;
	}
	
	memset(memo, -1, sizeof(memo));
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			ans = max(ans, max(dp(i, j), dp(j, i)));
		}
	}
	cout << (ans + 2) << endl;
}
