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

int n,m,T,k,q;
const ll big = 1000000007;

const int MAXN = 2000;

vl X;
vl Y;

vector<pll> DI;

ll d2(ll x1, ll y1, ll x2, ll y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int best1[MAXN] = {0};
int best2[MAXN] = {0};

int UPD[MAXN*MAXN+1];
int lo = 0;
int hi = 0;

void reset(){
    for(int c1 = lo; c1 < hi; c1++){
        best1[UPD[c1]] = max(best1[UPD[c1]],best2[UPD[c1]]);
        best2[UPD[c1]] = 0;
    }
    lo = hi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d,e;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        X.push_back(a);
        Y.push_back(b);
    }

    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = c1+1; c2 < n; c2++){
            ll dis = d2(X[c1],Y[c1],X[c2],Y[c2]);
            DI.push_back({dis,c1*n+c2});
            DI.push_back({dis,c2*n+c1});
        }
    }

    sort(all(DI));

    ll prev = -123;

    for(int c1 = 0; c1 < n; c1++){
        best1[c1] = 1;
    }

    for(int c1 = 0; c1 < sz(DI); c1++){
        ll i = DI[c1].second/n;
        ll j = DI[c1].second%n;
        ll da = DI[c1].first;
        if(da != prev)reset();
        best2[j] = max(best2[j], 1 + best1[i]);
        UPD[hi] = j;
        hi++;
        prev = da;
    }
    reset();
    int ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ans = max(ans, best1[c1]);
    }
    cout << ans << "\n";
    return 0;
}

