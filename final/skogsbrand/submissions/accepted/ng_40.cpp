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

const ll maxx = 99999;

struct pt{
    ll x,y;
};

vector<pt> P;

ll dist(ll x, ll y){
    ll d = big;
    for(int c1 = 0; c1 < n; c1++){
        d = min(d,abs(P[c1].x-x)+abs(P[c1].y-y));
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> m >> T;
    assert(m == 0);
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        P.push_back({a,b});
    }

    ll ans = 0;
    for(ll c1 = 0; c1 <= maxx; c1++){
        vector<pii> Y;
        Y.push_back({0,0});
        Y.push_back({maxx,0});
        for(ll c2 = 0; c2 < n; c2++){
            ll dx = abs(P[c2].x-c1);
            ll dy = T-dx;
            if(dy >= 0){
                Y.push_back({max(0ll,P[c2].y-dy),1});
                Y.push_back({min(maxx,P[c2].y+dy)+1,-1});
            }
        }
        sort(all(Y));
        ll cs = 0;
        ll prev = -1;
        for(ll c2 = 0; c2 < sz(Y); c2++){
            ll y = Y[c2].first;
            if(cs > 0 && prev != y){
                ans += y-prev;
            }
            cs += Y[c2].second;
            prev = y;
        }
    }

    for(int c1 = 0; c1 <= maxx; c1++){
        ll x = c1;
        ll y = 0;
        ll d = dist(x,y);
        d = T-d;
        if(d > 0){
            ans += d;
        }
    }

    for(int c1 = 0; c1 <= maxx; c1++){
        ll x = c1;
        ll y = maxx;
        ll d = dist(x,y);
        d = T-d;
        if(d > 0){
            ans += d;
        }
    }

    for(int c1 = 0; c1 <= maxx; c1++){
        ll x = 0;
        ll y = c1;
        ll d = dist(x,y);
        d = T-d;
        if(d > 0){
            ans += d;
        }
    }

    for(int c1 = 0; c1 <= maxx; c1++){
        ll x = maxx;
        ll y = c1;
        ll d = dist(x,y);
        d = T-d;
        if(d > 0){
            ans += d;
        }
    }

    ll DX[4] = {0,0,maxx,maxx};
    ll DY[4] = {0,maxx,0,maxx};

    for(int c1 = 0; c1 < 4; c1++){
        ll d = dist(DX[c1],DY[c1]);
        d = T-d;
        if(d > 0)ans += (d*(d-1))/2;
    }

    cout << ans << "\n";

    return 0;
}
