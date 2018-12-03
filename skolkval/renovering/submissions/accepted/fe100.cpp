#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
	cin.sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vi x(n);
    vi y(m);
    rep(i,0,n) cin>>x[i];
    rep(i,0,m) cin>>y[i];

    sort(all(x));
    sort(all(y));

    vi toBuy;

    while(x.size()){
		if(y.size()&&x[x.size()-1]<=y[y.size()-1]){
			x.pop_back();
			y.pop_back();
		} else {
			toBuy.push_back(x[x.size()-1]);
            x.pop_back();
		}
    }

    sort(all(toBuy));

	cout<<toBuy.size()<<endl;
	rep(i,0,toBuy.size()){
		cout<<toBuy[i]<<" ";
	}
	cout<<endl;
}
