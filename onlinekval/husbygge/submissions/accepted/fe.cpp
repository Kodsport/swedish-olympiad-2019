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

ll n,m,k;
vector<vi> g;

ll score(vector<pii> pos){
	ll sum = 0;
	//assert(pos.size()==k);
	rep(i,0,pos.size()){
		//ll i = 300;
		ll minDist = 1e18;
		rep(l,0,pos.size()){
			if(l==i) continue;
			minDist = min(minDist,abs(pos[i].first-pos[l].first)+abs(pos[i].second-pos[l].second));
		}
		//cout<<i<<" "<<minDist<<endl;
		sum+=minDist*g[pos[i].first][pos[i].second];
	}

	return sum;
}

void debugprint(vector<pii> pos){
	//assert(pos.size()==k);
	vector<string> p(n,string(m,'.'));
	rep(i,0,pos.size()){
		//cout<<pos[i].first<<" "<<pos[i].second<<endl;
		p[pos[i].first][pos[i].second] = '#';
	}
	rep(i,0,n) cout<<p[i]<<endl;
	cout<<score(pos)<<endl;
}

void print(vector<pii> pos){
	rep(i,0,k){
		cout<<pos[i].first+1<<" "<<pos[i].second+1<<endl;
	}
}

ll getMinDist(ll x,ll y,ll ign, vector<pii> &pos){
	ll minDist = 1e18;
	rep(l,0,k){
		ll dist = abs(x-pos[l].first)+abs(y-pos[l].second);
		if(l == ign) continue;
		minDist = min(minDist,dist);
	}
	return minDist;
}

ll hillclimb(vector<pii> pos){
	if(pos.size()==0)
		rep(i,0,k) pos.emplace_back(rand()%n,rand()%m);

	ll w = 200;
	if(k>=10000) w = 20;
	double fStep = 100;
	double mul = pow(0.1/fStep,1.0/w);
	assert(0.5<=mul&&mul<1);
	while(w--){
		ll step = (ll)fStep+1;
		rep(i,0,k){
			ll x = pos[i].first;
			ll y = pos[i].second;
			vector<pii> d = {{0,-step},{0,step},{step,0},{-step,0}};
			random_shuffle(all(d));
			ll bestDir = -1;
			ll bestScore = getMinDist(x,y,i,pos)*g[x][y];
			rep(j,0,4){
				ll x1 = x+d[j].first;
				ll y1 = y+d[j].second; 
				if(!(x1>=0&&x1<n&&y1>=0&&y1<m)) continue;
				ll minDist = getMinDist(x1,y1,i,pos);
				if(minDist*g[x1][y1]>=bestScore){
					bestScore = minDist*g[x1][y1];
					bestDir = j;
				}
			}
			if(bestDir==-1) continue;
			pos[i].first+=d[bestDir].first;
			pos[i].second+=d[bestDir].second;
		}
		//cout<<score(pos)<<endl;
		fStep *= mul;
	}

	//debugprint(pos);
	print(pos);
	return 0;//score(pos);
}

void solve8(){
	vector<pii> pos;
	vector<vector<bool>> p(n,vector<bool>(m,false));
	rep(i,0,n) rep(j,0,m) if(g[i][j]>=50) {
		pos.emplace_back(i,j);
		p[i][j] = true;
	}

	rep(i,0,n) {
		if(sz(pos)>=k) break;
		rep(j,0,m){
			if(sz(pos)>=k) break;
			if(!p[i][j]) {
				pos.emplace_back(i,j);
				p[i][j] = true;
			}
		}
	}

	print(pos);
}

void solve(int t) {
	cin>>n>>m>>k;
	g.resize(n,vi(m));
	rep(i,0,n)
		rep(j,0,m)
			cin>>g[i][j];

	switch(t){
		case 1:
			//solve1();
			hillclimb(vector<pii>(0));
			break;
		case 4:
			//solve1();
			//hillclimb(vector<pii>(0));
			break;
		case 5:
			hillclimb(vector<pii>(0));
			break;
		case 6:
			// hillclimb(vector<pii>(0));
			break;
		case 8:
			solve8();
			break;
		case 9:
			solve8(); // ?
			break;
		case 10:
			srand(66772);
			hillclimb(vector<pii>(0));
			break;
		default:
			hillclimb(vector<pii>(0));
			break;
	}
}

int main(){
	cin.sync_with_stdio(false); cin.tie(0);

	int t; cin>>t;
	solve(t);
	return 0;
}
