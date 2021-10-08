#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <ctime>
#define x first
#define y second	
using namespace std;

const int BITS = 30;
const int N = 1000 * 1000 + 1;

int a[N];
int b[BITS][2];

inline void go(int x, int y)
{
	if (x == y)
	{
		return;
	}

	for (int i = BITS - 1; i >= 0; --i)
	{
		if ((x >> i & 1) != (y >> i & 1))
		{
			++b[i][(x >> i & 1) > (y >> i & 1)];
			return;
		}
	}
}

inline void ungo(int x, int y)
{
	if (x == y)
	{
		return;
	}

	for (int i = BITS - 1; i >= 0; --i)
	{
		if ((x >> i & 1) != (y >> i & 1))
		{
			--b[i][(x >> i & 1) > (y >> i & 1)];
			return;
		}
	}
}

inline pair<int, int> bad(int x, int y)
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

unordered_set<int> u;

int lst = 0;
inline void ans()
{
		for (int i = 0; i < BITS; ++i)
	{
		if (b[i][0] > 0 && b[i][1] > 0)
		{
			lst = -1;
			printf("-1\n");
			return;
		}
	}

	static int c[BITS][2];
	for (int i = 0; i < BITS; ++i)
		c[i][0] = c[i][1] = 0;

	for (int i : u)
	{
		auto p = bad(a[i], a[i + 1]);
		if (p.x != -1)
		{
			++c[p.x][p.y];
		}
	}

	int x = 0;
	for (int i = 0; i < BITS; ++i)
	{
		if (b[i][0] + c[i][0] > 0 && b[i][1] + c[i][1] > 0)
		{
			lst = -1;
			printf("-1\n");
			return;
		}
		if (b[i][1] + c[i][1])
		{
			x |= (1 << i);
		}
	}
	lst = x;
	printf("%d\n", x);
}

int main()
{
	int n;
	scanf("%d", &n);

	u.rehash(n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}

	for (int i = 0; i < n - 1; ++i)
	{
		go(a[i], a[i + 1]);
	}

	ans();

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; ++i)
	{
		if (clock() > 1.8 * CLOCKS_PER_SEC)
		{
			for (; i < q; ++i)
			{
				printf("%d\n", lst);
			}
			return 0;
		}

		int p, v;
		scanf("%d%d", &p, &v);
		--p;

		if (p < n - 1 && u.insert(p).y)
		{
			ungo(a[p], a[p + 1]);
		}
		if (0 < p && u.insert(p - 1).y)
		{
			ungo(a[p - 1], a[p]);
		}
		a[p] = v;

		ans();
	}
}
