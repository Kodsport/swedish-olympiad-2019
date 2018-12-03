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

    vector<vi> g(n,vi(m,-1));

    ll r = 0;
    ll c = 0;
    ll dr = 1;
    ll dc = 1;
    ll ind = 0;
    while(ind<str.size()){
        if(g[r][c]==-1){
            g[r][c] = ind;
            ind++;
        }

		r+=dr;
		c+=dc;

        if(r<0){ r = 1; dr = 1; }
        if(c<0){ c = 1; dc = 1; }
        if(r>=n){ r = n-2; dr = -1; }
        if(c>=m){ c = m-2; dc = -1; }
    }

    vi encNum;
    rep(i,0,n)
		rep(j,0,m)
			if(g[i][j]!=-1)
				encNum.push_back(g[i][j]);

    string dec(str.size(),'.');

    rep(i,0,str.size())
		dec[encNum[i]] = str[i];

    cout<<dec<<endl;
}
