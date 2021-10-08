#include <iostream>
#include <algorithm>
#include <vector>
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

long long sum = 0;
inline void ans()
{
	int x = 0;
	for (int i = 0; i < BITS; ++i)
	{
		if (b[i][0] > 0 && b[i][1] > 0)
		{
		    printf("-1\n");
		    sum -= 1;
			return;
		}
		if (b[i][1])
		{
			x |= (1 << i);
		}
	}
	printf("%d\n", x);
	sum += x;
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
		go(a[i], a[i + 1]);
	}

	ans();

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; ++i)
	{
		int p, v;
		scanf("%d%d", &p, &v);
		--p;
		a[p] = v;

		for (int j = 0; j < BITS; ++j)
		{
			b[j][0] = b[j][1] = 0;
		}

		for (int i = 0; i < n - 1; ++i)
		{
			go(a[i], a[i + 1]);
		}

		ans();
	}
	//printf("%lld\n", sum);
}
