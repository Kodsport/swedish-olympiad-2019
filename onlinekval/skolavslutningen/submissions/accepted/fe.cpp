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

vector<vi> e;
vector<bool> seen;

void dfs(ll v){
	if(seen[v]) return;
	seen[v] = true;
	rep(i,0,e[v].size()) dfs(e[v][i]);
}

int main(){
	cin.sync_with_stdio(false); cin.tie(0);

	ll n,m,k;
	cin>>n>>m>>k;

	e.resize(n*m);
	seen.resize(n*m);

	vector<vi> classes(k);

	rep(i,0,n)
		rep(j,0,m){
			char person;
			cin>>person;
			classes[person-'A'].push_back(i*m+j);
			if(i<n-1){
				e[i*m+j].push_back(i*m+j+m);
				e[i*m+j+m].push_back(i*m+j);
			}
		}

	rep(i,0,k){
		rep(j,0,classes[i].size()-1){
			e[classes[i][j]].push_back(classes[i][j+1]);
			e[classes[i][j+1]].push_back(classes[i][j]);
		} 
	}

	ll numComp = 0;
	rep(i,0,n*m){
		if(!seen[i]){
			numComp++;
			dfs(i);
		}
	}
	cout<<numComp<<endl;
}
