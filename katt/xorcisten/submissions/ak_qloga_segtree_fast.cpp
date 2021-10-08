#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define x first
#define y second
using namespace std;

const int N = 1000 * 1000 + 1;
const int BITS = 30;

int a[N];
int n;

int t[4 * N][2];

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
			t[v][p.y] = (1 << p.x);
		}
	}
	else
	{
		build_t(v << 1, l, (l + r) >> 1);
		build_t(v << 1 | 1, (l + r) >> 1, r);
		for (int i = 0; i < BITS; ++i)
		{
			t[v][0] = t[v << 1][0] | t[v << 1 | 1][0];
			t[v][1] = t[v << 1][1] | t[v << 1 | 1][1];
		}
	}
}

long long sum = 0;
inline void ans_t(int v)
{
	int x = 0;
	for (int i = 0; i < BITS; ++i)
	{
		if ((t[v][0] >> i & 1) && (t[v][1] >> i & 1))
		{
			printf("-1\n");
			sum -= 1;
			return;
		}
		if (t[v][1] >> i & 1)
		{
			x |= (1 << i);
		}
	}
	printf("%d\n", x);
	sum += x;
}

void upd_t(int v, int l, int r, int V, int x, int y, bool val)
{
	if (V < l || r <= V)
	{
		return;
	}

	if (r - l == 1)
	{
		if (val)
			t[v][y] |= (1 << x);
		else
			t[v][y] &= ~(1 << x);
		return;
	}

	upd_t(v << 1, l, (l + r) >> 1, V, x, y, val);
	upd_t(v << 1 | 1, (l + r) >> 1, r, V, x, y, val);
	t[v][y] = t[v << 1][y] | t[v << 1 | 1][y];
}


int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}

	int q;
	scanf("%d", &q);

	if (n == 1)
	{
		for (int i = 0; i < q + 1; ++i)
		{
			printf("0\n");
		}
		return 0;
	}

	build_t(1, 0, n - 1);
	ans_t(1);

	for (int i = 0; i < q; ++i)
	{
		int p, v;
		scanf("%d%d", &p, &v);
		--p;

		pair<int, int> x;

		if (p > 0)
		{
			auto x = go(a[p - 1], a[p]);
			if (x.x != -1)
			{
				upd_t(1, 0, n - 1, p - 1, x.x, x.y, false);
			}
		}
		x = go(a[p], a[p + 1]);
		if (x.x != -1)
		{
			upd_t(1, 0, n - 1, p, x.x, x.y, false);
		}

		a[p] = v;

		if (p > 0)
		{
			auto x = go(a[p - 1], a[p]);
			if (x.x != -1)
			{
				upd_t(1, 0, n - 1, p - 1, x.x, x.y, true);
			}
		}
		x = go(a[p], a[p + 1]);
		if (x.x != -1)
		{
			upd_t(1, 0, n - 1, p, x.x, x.y, true);
		}

		ans_t(1);
	}
	//printf("%lld\n", sum);
}
