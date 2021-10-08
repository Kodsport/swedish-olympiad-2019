#include <iostream>
#include <algorithm>
#include <vector>
#define x first
#define y second
#define endl '\n'
using namespace std;

const int BITS = 30;

inline void go(vector<int> &a, int i, vector<vector<int>> &b, vector<pair<int, int>> &c)
{
	for (int j = BITS - 1; j >= 0; --j)
	{
		if ((a[i] >> j & 1) != (a[i + 1] >> j & 1))
		{
			c[i] = { a[i] >> j & 1, j };
			++b[c[i].x][j];
			return;
		}
	}
	c[i] = {-1, -1};
}

long long sum = 0;
inline void ans(vector<vector<int>> &b)
{
	int x = 0;
	for (int i = 0; i < BITS; ++i)
	{
		if (min(b[0][i], b[1][i]) != 0)
		{
		    cout << -1 << endl;
		    sum -= 1;
			return;
		}
		if (b[1][i])
		{
			x |= (1 << i);
		}
	}
	cout << x << endl;
	sum += x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	vector<pair<int, int>> c(n - 1);
	vector<vector<int>> b(2, vector<int>(BITS));

	for (int i = 0; i < n - 1; ++i)
	{
		go(a, i, b, c);
	}

	ans(b);

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		int p, v;
		cin >> p >> v;
		--p;
		a[p] = v;

		for(int j = max(p - 1, 0); j < min(p + 1, n - 1); ++j)
		{
			if(c[j].x != -1)
			{
				--b[c[j].x][c[j].y];
			}
			go(a, j, b, c);
		}

		ans(b);
	}
	//cout << sum << endl;
}
