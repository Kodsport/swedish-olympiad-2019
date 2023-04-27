#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 998244353;

const ll lim = 1000;

struct pt{
    ll x,y;
};

ll DX[4] = {0,0,1,-1};
ll DY[4] = {1,-1,0,0};
vector<pt> fire;
vector<pt> fire2;
bool blocked[2*lim + 101][2*lim + 101] = {0};
ll ANS[lim+1] = {0};
ll ans = 0;

void bfs(ll i){
    ANS[i] = ANS[i-1];
    fire2.clear();
    for(int c1 = 0; c1 < sz(fire); c1++){
        for(int c2 = 0; c2 < 4; c2++){
            ll x2 = fire[c1].x + DX[c2];
            ll y2 = fire[c1].y + DY[c2];
            if(!blocked[x2+lim+1][y2+lim+1]){
                fire2.push_back({x2,y2});
                blocked[x2+lim+1][y2+lim+1] = 1;
                ANS[i]++;
            }
        }
    }
    fire.clear();
    for(int c1 = 0; c1 < sz(fire2); c1++){
        fire.push_back(fire2[c1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> m >> T;

    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        fire.push_back({a,b});
        ans++;
        ANS[0]++;
        assert(max(a,b) < 100);
        blocked[a+lim+1][b+lim+1] = 1;
    }
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        assert(max(a,b) < 100);
        blocked[a+lim+1][b+lim+1] = 1;
    }

    for(int c1 = 1; c1 <= lim; c1++){
        bfs(c1);
    }
    if(T <= lim){
        cout << ANS[T] << "\n";
    }
    else{
        ll diff = ANS[lim]-ANS[lim-1];
        ll T2 = T-lim;
        if(diff == 0){
            cout << ANS[lim] << "\n";
        }
        else{
            cout << ANS[lim] + 2*T2*(T2+1) + diff*T2 << "\n";
        }
    }

    return 0;
}
