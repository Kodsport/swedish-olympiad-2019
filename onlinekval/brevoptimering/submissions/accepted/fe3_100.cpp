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

int main(){
	cin.sync_with_stdio(false);
	ll n;
	cin>>n;
	e.resize(n);
	vector<double> cMax(n);

    vi inDeg(n);

    rep(i,0,n) {
        ll k;
        cin>>cMax[i]>>k;
        rep(l,0,k){
            ll j;
            double w;
            cin>>j>>w;
            e[i].emplace_back(j-1,w/100.0);
            inDeg[j-1]++;
        }
    }

	vi inDone(n);

    vector<double> input(n,0);

    queue<ll> q;

    rep(i,0,n){
		if(inDeg[i]==0){
			input[i] = cMax[i];
			q.push(i);
		}
    }

    vi ans;

    while(q.size()){
		ll v = q.front();
		q.pop();
		//cout<<input[v]<<" "<<cMax[v]<<endl;
		double output = min(input[v],cMax[v]);
        if(output==cMax[v]) ans.push_back(v);
        rep(j,0,e[v].size()){
			ll u = e[v][j].first;
			input[u] += e[v][j].second*output;
			inDone[u]++;
			if(inDone[u]==inDeg[u]) q.push(u);
        }
    }
    sort(all(ans));
    rep(i,0,ans.size()){
    	if(i) cout<<" ";
    	cout<<ans[i]+1;
    }
    cout<<endl;

}