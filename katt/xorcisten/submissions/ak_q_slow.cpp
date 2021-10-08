#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <iostream>
#include <assert.h>
#define x first
#define y second
using namespace std;

const int MAX_N = 1000 * 1000 + 1;
const int BITS = 30;

int cur = 0;
int cnt_bad = 0;

int a[MAX_N];
int num[BITS][2];
pair<int, int> rest[MAX_N];

inline void go(int pos, int x, int y)
{
	if (x != y)
	{
		int j = 32 - __builtin_clz(x ^ y) - 1;
		rest[pos] = { j, (x >> j & 1) };
		++num[j][(x >> j & 1)];

		if (num[j][(x >> j & 1)] == 1)
		{
			if (num[j][((x >> j & 1)) ^ 1])
			{
				++cnt_bad;
			}
			else
			{
				if ((x >> j & 1))
				{
					cur |= (1 << j);
				}
				else
				{
					cur &= ~(1 << j);
				}
			}
		}
	}
	else
	{
		rest[pos] = { -1, -1 };
	}
}

inline void ungo(int pos, int x, int y)
{
	if (x != y)
	{
		int j = 32 - __builtin_clz(x ^ y) - 1;
		--num[j][(x >> j & 1)];

		if (num[j][(x >> j & 1)] == 0)
		{
			if (num[j][((x >> j & 1)) ^ 1])
			{
				--cnt_bad;
				if ((x >> j & 1) == 0)
				{
					cur |= (1 << j);
				}
				else
				{
					cur &= ~(1 << j);
				}
			}
			else
			{
				cur &= ~(1 << j);
			}
		}
	}
}

long long sum = 0;
inline void ans()
{
	if (cnt_bad)
	{
		cout << -1 << endl;
		sum -= 1;
	}
	else
	{
		cout << cur << endl;
		sum += cur;
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n - 1; ++i)
	{
		go(i, a[i], a[i + 1]);
	}

	ans();

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		int p, v;
		cin >> p >> v;
		--p;

		for (int j = max(p - 1, 0); j < min(p + 1, n - 1); ++j)
		{
			ungo(j, a[j], a[j + 1]);
		}

		a[p] = v;

		for (int j = max(p - 1, 0); j < min(p + 1, n - 1); ++j)
		{
			go(j, a[j], a[j + 1]);
		}

		ans();
	}
}
