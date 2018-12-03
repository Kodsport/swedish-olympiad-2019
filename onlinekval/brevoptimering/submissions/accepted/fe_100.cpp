#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

vi toposort;
vector<vector<pair<ll,double>>> e;
vector<bool> seen;

void dfs(ll v){
	if(seen[v]) return;
	seen[v] = true;
	rep(i,0,e[v].size()) dfs(e[v][i].first);
	toposort.push_back(v);
}

int main(){
	cin.sync_with_stdio(false);
	ll n;
	cin >> n;
	e.resize(n);
	seen.resize(n);
	vector<double> cMax(n);

	rep(i,0,n){
		cin >> cMax[i];
		ll k;
		cin >> k;
		rep(l,0,k) {
			ll j;
			double w;
			cin >> j >> w;
			--j;
			e[i].emplace_back(j,w/100);
		}
	}

	rep(i,0,n) dfs(i);

	reverse(all(toposort));

	vector<double> input(n,1e18);
	vi answer;
	rep(i,0,n){
		ll v = toposort[i];
		double output = 0;
		output = min(input[v],cMax[v]);
		if(abs(output-cMax[v]) < 1e-6)answer.push_back(v+1);
		rep(j,0,e[v].size()){
			ll u = e[v][j].first;
			if(input[u]==1e18)
				input[u] = 0;
			input[u] += e[v][j].second*output;
		}
	}
	sort(all(answer));
	rep(i,0,sz(answer)){
		if (i) cout << ' ';
		cout << answer[i];
	}
	cout<<endl;
}
