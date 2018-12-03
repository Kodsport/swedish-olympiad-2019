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
	cin>>n>>m>>k;

	vector<pii> meals(m);

	rep(i,0,n){
		ll meal; cin>>meal;
		meals[meal-1].second++;
	}

	rep(i,0,m) cin>>meals[i].first;

	sort(all(meals));
	reverse(all(meals));

	vi freeMeals;

	vi swaps;

	rep(i,0,m){
		ll p = meals[i].second;
		ll c = meals[i].first;
		//cout<<p<<" "<<c<<endl;
		if(p == 0){
			freeMeals.push_back(c);
		} else k--;
		//cout<<freeMeals.size()<<endl;
		while(freeMeals.size()>0&&p>1){
			swaps.push_back(freeMeals[freeMeals.size()-1]-c);
			freeMeals.pop_back();
			p--;
		}
	}

	if(sz(swaps) < k) {
		cout<<-1<<endl;
		return 0;
	}

	sort(all(swaps));

	ll ans = 0;

	rep(i,0,k) ans+=swaps[i];

	cout<<ans<<endl;
}
