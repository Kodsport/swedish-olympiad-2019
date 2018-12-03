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

int main(){
	cin.sync_with_stdio(false); cin.tie(0);

	ll n;
	cin>>n;
	vi r(n);
	vi c(n);
	rep(i,0,n) cin>>r[i];
	rep(i,0,n) cin>>c[i];

	ll mx = 0;
	rep(i,0,n)
		rep(j,0,n){
			mx += min(r[i],c[j]);
		}
	map<ll,ll> freqR;
	map<ll,ll> freqC;

	rep(i,0,n){
		freqR[r[i]]++;
		freqC[c[i]]++;
	}

	ll mn = n*n;

	rep(i,1,6){
		mn += max(freqC[i],freqR[i])*(i-1);
	}

	cout<<mn<<" "<<mx<<endl;

}
