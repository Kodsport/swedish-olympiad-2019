#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define x first
#define y second
using namespace std;

const int N = 1000 * 1000 + 1;
const int BITS = 30;

int a[N];
int n;

int t[4 * N][30][2];

inline pair<int, int> go(int x, int y)
{
	for (int i = BITS - 1; i >= 0; --i)
	{
		if ((x >> i & 1) != (y >> i & 1))
		{
			return { i, (x >> i & 1) > (y >> i & 1) };
		}
	}
	return { -1, -1 };
}

void build_t(int v, int l, int r)
{
	if (r - l == 1)
	{
		auto p = go(a[l], a[l + 1]);
		if (p.x != -1)
		{
			t[v][p.x][p.y] = 1;
		}
	}
	else
	{
		build_t(v * 2, l, (l + r) / 2);
		build_t(v * 2 + 1, (l + r) / 2, r);
		for (int i = 0; i < BITS; ++i)
		{
			t[v][i][0] = t[2 * v][i][0] + t[2 * v + 1][i][0];
			t[v][i][1] = t[2 * v][i][1] + t[2 * v + 1][i][1];
		}
	}
}

long long sum = 0;
inline void ans_t(int v)
{
	int x = 0;
	for (int i = 0; i < BITS; ++i)
	{
		if (t[v][i][0] > 0 && t[v][i][1] > 0)
		{
		    cout << -1 << endl;
		    sum -= 1;
			return;
		}
		if (t[v][i][1] > 0)
		{
			x |= (1 << i);
		}
	}
	cout << x << endl;
	sum += x;
}

void upd_t(int v, int l, int r, int V, bool add)
{
	if (V < l || r <= V)
	{
		return;
	}

	if (r - l == 1)
	{
		if (add)
		{
			auto p = go(a[l], a[l + 1]);
			if (p.x != -1)
			{
				++t[v][p.x][p.y];
			}
		}
		else
		{
			auto p = go(a[l], a[l + 1]);
			if (p.x != -1)
			{
				--t[v][p.x][p.y];
			}
		}
		return;
	}

	upd_t(2 * v, l, (l + r) / 2, V, add);
	upd_t(2 * v + 1, (l + r) / 2, r, V, add);
	for (int i = 0; i < BITS; ++i)
	{
		t[v][i][0] = t[2 * v][i][0] + t[2 * v + 1][i][0];
		t[v][i][1] = t[2 * v][i][1] + t[2 * v + 1][i][1];
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int q;
	cin >> q;
	
	if(n == 1)
	{
	    for(int i = 0; i < q + 1; ++i)
	    {
	        cout << 0 << endl;
	    }
	    return 0;
	}
	
	build_t(1, 0, n - 1);
	ans_t(1);

	for (int i = 0; i < q; ++i)
	{
		int p, v;
		cin >> p >> v;
		--p;

		if (p > 0)
		{
			upd_t(1, 0, n - 1, p - 1, false);
		}
		upd_t(1, 0, n - 1, p, false);

		a[p] = v;
		
		if (p > 0)
		{
			upd_t(1, 0, n - 1, p - 1, true);
		}
		upd_t(1, 0, n - 1, p, true);

		ans_t(1);
	}
	//cout << sum << endl;
}
