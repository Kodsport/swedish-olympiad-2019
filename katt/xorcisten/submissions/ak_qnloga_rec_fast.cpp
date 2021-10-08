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

pair<int, int> ans(int l, int r, int b)
{
	if (r - l <= 1 || b < 0)
	{
		return { 0, 0 };
	}

	int num = (a[l] >> b & 1);
	
	int i;
	for (i = l + 1; i < r && (a[i] >> b & 1) == num; ++i);

	if (i == r)
	{
		return ans(l, r, b - 1);
	}

	int j;
	for (j = i + 1; j < r && (a[j] >> b & 1) != num; ++j);

	if (j != r)
	{
		return{ -1, -1 };
	}

	pair<int, int> p = { 0, 0 };
	if (num == 0)
		p.y = (1 << b);
	else
		p.x = (1 << b);

	auto q = ans(l, i, b - 1);
	p.x |= q.x;
	p.y |= q.y;
	if (p.x & p.y)
	{
		return { -1, -1 };
	}

	q = ans(i, r, b - 1);
	p.x |= q.x;
	p.y |= q.y;
	if (p.x & p.y)
	{
		return { -1, -1 };
	}

	return p;
}

inline int ans(int n)
{
	return ans(0, n, BITS - 1).x;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}

	printf("%d\n", ans(n));

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; ++i)
	{
		int p, v;
		scanf("%d %d", &p, &v);
		--p;
		a[p] = v;

		printf("%d\n", ans(n));
	}
}
