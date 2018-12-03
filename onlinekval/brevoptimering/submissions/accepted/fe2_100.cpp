#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

vector<vector<pair<ll,double>>> e;

vector<double> cMax;
vector<double> mem;

double getOutput(ll v){
	if(mem[v]!=-1) {
		return mem[v];
	}
	if(e[v].size()==0) return cMax[v];

    double in = 0;
    rep(i,0,e[v].size()){
        in += getOutput(e[v][i].first)*e[v][i].second;
    }

    double out = min(in,cMax[v]);

    return mem[v] = out;
}

int main(){
	cin.sync_with_stdio(false);
    ll n;
    cin>>n;
    e.resize(n);
    cMax.resize(n);
	mem.resize(n,-1);

    rep(i,0,n) {
        ll k;
        cin>>cMax[i]>>k;
        rep(l,0,k){
            ll j;
            double w;
            cin>>j>>w;
            e[j-1].emplace_back(i,w/100.0);
        }
    }

    rep(i,0,n){
        if(getOutput(i)==cMax[i]) cout<<i+1<<" ";
    }
    cout<<endl;
}