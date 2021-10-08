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

int a[MAX_N];
int num[BITS][2];

inline void go(int pos, int x, int y)
{
	if (x != y)
	{
		int j;
		for (j = BITS - 1; j >= 0 && ((x ^ y) >> j) == 0; --j);
		++num[j][(x >> j & 1)];
	}
}

inline void ungo(int pos, int x, int y)
{
	if (x != y)
	{
		int j;
		for (j = BITS - 1; j >= 0 && ((x ^ y) >> j) == 0; --j);
		--num[j][(x >> j & 1)];
	}
}

inline void ans()
{
	int cur = 0;
	for (int i = 0; i < BITS; ++i)
	{
		if (num[i][0] && num[i][1])
		{
			printf("-1\n");
			return;
		}
		if (num[i][1])
		{
			cur |= (1 << i);
		}
	}
	printf("%d\n", cur);
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}

	for (int i = 0; i < n - 1; ++i)
	{
		go(i, a[i], a[i + 1]);
	}

	ans();

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; ++i)
	{
		int p, v;
		scanf("%d %d", &p, &v);
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
