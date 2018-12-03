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

	ll n,m,k;

	string s;
	cin >> s >> k;
	n = sz(s);

	vi v(n);
	rep(i,0,n) v[i] = s[i] - 'A', m = max(m, v[i] + 1);
	//rep(i,0,n) cout<<v[i]<<" ";
	//cout<<endl;

	ll bestAns = 0;

	rep(w,0,2){
		vi a = v;
		vector<bool> moved(n);

		rep(i,0,n){
			if(a[i]==0||moved[i]) continue;
			if(i>0&&a[i-1]==1){
			} else if(i>1&&a[i-2]==1&&!moved[i-1]){
				swap(a[i],a[i-1]);
				moved[i] = moved[i-1] = true;
			} else if(i>2&&a[i-3]==1&&!moved[i-2]){
				swap(a[i],a[i-2]);
				moved[i] = moved[i-2] = true;
			} else if(i<n-2&&a[i+2]==0&&!moved[i+2]){
				swap(a[i],a[i+2]);
				moved[i] = moved[i+2] = true;
			} else if(i<n-1&&!moved[i+1]){
				swap(a[i],a[i+1]);
				moved[i] = moved[i+1] = true;
			}	
		}

		ll ans = 0;
		//rep(i,0,n) cout<<a[i]<<" ";
		//cout<<endl;
		rep(i,0,n-1) ans += (a[i]==a[i+1]);
		//cout<<ans<<endl;
		bestAns = max(bestAns,ans);
		
		rep(i,0,n) v[i] = !v[i];
	}
	
	cout<<bestAns<<endl;
}
