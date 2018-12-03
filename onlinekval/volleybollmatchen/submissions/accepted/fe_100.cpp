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

	ll n;
	cin>>n;
	ll aScore = 0;
	ll bScore = 0;
	ll aSet = 0;
	ll bSet = 0;
	rep(i,0,n){
		char c;
		cin>>c;

		if(c=='A') aScore++;
		if(c=='B') bScore++;
		
		ll winScore = (aSet+bSet==2)?15:25;
		if(aScore>=winScore&&aScore>=2+bScore){
			aSet++;
			aScore=0;
			bScore=0;
		}
		if(bScore>=winScore&&bScore>=2+aScore){
			bSet++;
			aScore=0;
			bScore=0;
		}
	}

	cout<<aSet<<" "<<bSet<<endl;
}
