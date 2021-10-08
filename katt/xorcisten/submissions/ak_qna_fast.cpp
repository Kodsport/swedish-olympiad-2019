#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000 * 1000 + 1;
int a[N];
int n;

long long sum = 0;
void ans()
{
	int mx = a[0];
	for(int i = 1; i < n; ++i)
	{
		mx = max(mx, a[i]);
	}
    
    int to = 1;
    while(to <= mx)
    {
        to <<= 1;
    }
    
	for (int i = 0; i <= to; ++i)
	{
		bool ok = true;
		for(int j = 1; j < n; ++j)
		{
			if((a[j - 1] ^ i) > (a[j] ^ i))
			{
				ok = false;
				break;
			}
		}
		if(ok)
		{
		    printf("%d\n", i);
			sum += i;
			return;
		}
	}
	printf("-1\n");
	sum -= 1;    
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
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
		ans();
	}
	//printf("%lld\n", sum);
}
