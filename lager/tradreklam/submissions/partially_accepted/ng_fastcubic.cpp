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

const ll MAXN = 2000;
const ll MAXC = 30000;

ll P[MAXN] = {0};
ll SS[MAXN] = {0};
vector<vl> C(MAXN, vl());
vector<vl> CW(MAXN, vl());

ll DP[MAXN][MAXC+1] = {0};
vector<vl> I(MAXN, vl());
ll TEMP[MAXC+1] = {0};

void merg(int from, int to){
    for(int c1 = 0; c1 <= m; c1++){
        TEMP[c1] = 0;
    }
    for(int c1 = 0; c1 < sz(I[from]); c1++){
        for(int c2 = 0; c2 <= m; c2++){
            int c = I[from][c1] + c2;
            if(c > m)break;
            TEMP[c] = max(TEMP[c], DP[from][I[from][c1]] + DP[to][c2]);
        }
    }
    for(int c1 = 0; c1 <= m; c1++){
        DP[to][c1] = TEMP[c1];
    }
}

void dp(int i, int par, int cost){
    int j = -1;
    int best = -1;
    SS[i] = P[i];
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        int a = C[i][c1];
        if(a != par){
            dp(a,i,CW[i][c1]);
            SS[i] += SS[a];
            if(sz(I[a]) > best){
                best = sz(I[a]);
                j = a;
            }
        }
    }
    if(j != -1){
        for(int c1 = 0; c1 <= m; c1++){
            DP[i][c1] = DP[j][c1];
        }
        for(int c1 = 0; c1 < sz(C[i]); c1++){
            int a = C[i][c1];
            if(a != par && a != j){
                merg(a,i);
            }
        }
    }
    if(par != -1 && cost <= m){
        DP[i][cost] = max(DP[i][cost],SS[i]);
    }
    int ma = -1;
    for(int c1 = 0;  c1 <= m; c1++){
        if(DP[i][c1] > ma){
            ma = DP[i][c1];
            I[i].push_back(c1);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> m;
    P[0] = 0;
    for(int c1 = 1; c1 < n; c1++){
        cin >> P[c1];
    }
    for(int c1 = 0; c1 < n-1; c1++){
        cin >> a >> b >> c;
		--a, --b;
        C[a].push_back(b);
        C[b].push_back(a);
        CW[a].push_back(c);
        CW[b].push_back(c);
    }
    dp(0,-1,0);

    ll ans = 0;
    for(int c1 = 0; c1 <= m; c1++){
        ans = max(ans, DP[0][c1]);
    }
    cout << ans << "\n";

    return 0;
}
