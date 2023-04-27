#include "validator.h"

void run() {
	int klo = 0, khi = 200, exactk = Arg("k");
	if (exactk != -1) {
		klo = khi = exactk;
	}

	int n = Int(2, 100);
	Space();
	int m = Int(2, 100);
	Space();
	int k = Int(klo, khi);
	Endl();

	vector<string> board(n, string(m, '\0'));
	vector<string> rboard(m, string(n, '\0'));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c = Char();
			assert(c == '#' || c == '.');
			board[i][j] = c;
			rboard[j][i] = c;
		}
		Endl();
	}

	assert(board[0][0] == '.');
	assert(board[n-1][m-1] == '.');

	string special = Arg("special");
	if (special == "right_down") {
		// There must be a solution that only walks right and down, which we can find by DP:
		vector<vector<int>> dp(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x = INT_MAX;
				if (i) x = min(x, dp[i-1][j]);
				if (j) x = min(x, dp[i][j-1]);
				if (i == 0 && j == 0) x = 0;
				if (board[i][j] == '#') x++;
				dp[i][j] = x;
			}
		}
		assert(dp[n-1][m-1] <= k);
	}
	else if (special == "pillars") {
		assert(k == 0);
		for (int j = 0; j < m; j++) {
			string line = rboard[j];
			size_t ind1 = line.find('.');
			size_t ind2 = line.rfind('.');
			assert(ind1 != string::npos);
			assert(ind2 != string::npos);
			ind2++;
			for (size_t i = 0; (int)i < n; i++) {
				bool mid1 = (line[i] == '.');
				bool mid2 = (ind1 <= i && i < ind2);
				assert(mid1 == mid2);
			}
		}
	}
	else {
		assert(special == "none");
	}
}
