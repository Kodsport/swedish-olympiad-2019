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
	ll E,C,A;
	ll e,c,a;
	cin>>A>>C>>E;
	cin>>a>>c>>e;

    if(c*2<C) cout<<"E";
    else if(a*2<A) cout<<"C";
	else cout<<"A";
	cout<<endl;
}
