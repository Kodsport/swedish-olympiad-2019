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

ll const MAXN = 2000;

vector<vector<pll> > P(MAXN, vector<pll>());

ll X[MAXN];
ll Y[MAXN];

ll dist(int i, int j){
    return (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
}

int DP[MAXN][MAXN] = {0};
bool DPC[MAXN][MAXN] = {0};

int dp(int i, int j){
    if(DPC[i][j])return DP[i][j];
    ll d = dist(i,j);
    int ans = 1;
    for(int c1 = 0; c1 < n; c1++){
        if(P[j][c1].first <= d)break;
        ans = max(ans,1+dp(j,P[j][c1].second));
    }
    DPC[i][j] = 1;
    DP[i][j] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> X[c1] >> Y[c1];
    }
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < n; c2++){
            P[c1].push_back({dist(c1,c2),c2});
        }
        sort(all(P[c1]));
        reverse(all(P[c1]));
    }
    int ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ans = max(ans, dp(c1,c1));
    }
    cout << ans << "\n";

    return 0;
}

