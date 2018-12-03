#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n,m,k;
vi a;

vector<vi> mem;

ll numPairs(vi v){
	ll ans = 0;
	rep(i,0,v.size()-1) ans += (v[i]==v[i+1]);

	return ans;
}

ll f(ll index, ll last){
	if(index==n) return 0;
	//cout<<index<<" "<<last<<endl;
	if(mem[index][last]!=-1) return mem[index][last];

	ll best = f(index+1, a[index]) + numPairs(vi({last,a[index]}));

	if(index<n-1)
		best = max(best, f(index+2,a[index]) + numPairs(vi({last,a[index+1],a[index]})));

	if(k==2){
		if(index<n-2)
			best = max(best, f(index+3,a[index]) + numPairs(vi({last,a[index+2],a[index+1],a[index]})));

		if(index<n-3)
			best = max(best, f(index+4,a[index+1]) + numPairs(vi({last,a[index+2],a[index+3],a[index],a[index+1]})));
	}


	return mem[index][last] = best;
}

int main(){
	cin.sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s >> k;
	n = sz(s);
	a.resize(n);

	rep(i,0,n) a[i] = s[i] - 'A', m = max(m, a[i] + 1);

	mem.resize(n,vi(m+1,-1));

	cout<<f(0,m)<<endl;
}
