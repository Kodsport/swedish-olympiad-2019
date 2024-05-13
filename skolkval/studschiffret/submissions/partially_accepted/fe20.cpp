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
    string str;
    cin>>n>>m>>str;
   // cout<<str<<endl;
	int k = sz(str);
    string dec(k,'.');

    ll row1Len = k/2+(k%2!=0);
    rep(i,0,row1Len) {
    	dec[i*2] = str[i];
    	//cout<<dec<<endl;
    }
    rep(i,row1Len,k) {
    	dec[(i-row1Len)*2+1] = str[i];
    	//cout<<dec<<endl;
    }
    cout<<dec<<endl;
}
