#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long sum = 0;
void ans(vector<int> &a)
{
    int mx = *max_element(a.begin(), a.end());
    int to = 1;
    while(to <= mx)
    {
        to <<= 1;
    }
    
	for (int i = 0; i <= to; ++i)
	{
		auto b = a;
		for (int &j : b)
		{
			j ^= i;
		}
		if (is_sorted(b.begin(), b.end()))
		{
            cout << i << endl;
			sum += i;
			return;
		}
	}
	cout << -1 << endl;
	sum -= 1;
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	ans(a);

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int p, v;
		cin >> p >> v;
		--p;
		a[p] = v;
		ans(a);
	}
	//cout << sum << endl;
}
