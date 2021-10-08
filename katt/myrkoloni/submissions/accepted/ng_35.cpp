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
const ll MAXN = 100000;

vector<vl> C(MAXN,vl());
ll A,B;

map<ll,ll> M;
vl used;
vl X,Y;

void add(ll i, ll j){
    ll h = i*B+j;
    if(M.find(h) == M.end()){
        M[h] = sz(used);
        used.push_back(h);
        X.push_back(i);
        Y.push_back(j);
    }
}

ll has(ll i, ll j){
    return i*B+j;
}
ll visited[MAXN] = {0};
ll counter = 0;

ll dfs(ll i, ll par, ll x1, ll x2, ll y1, ll y2){
    ll x = X[i];
    ll y = Y[i];
    if(!(x >= x1 && x <= x2 && y >= y1 && y <= y2))return 0;
    if(visited[i] == counter)return 0;
    visited[i] = counter;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(a != par){
            dfs(a,i,x1,x2,y1,y2);
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> A >> B >> n >> q;
    assert(n <= 3000 && q <= 3000);
    for(int c1 = 0; c1 < n-1; c1++){
        char ch;
        cin >> ch >> a >> b;a--;b--;
        if(ch=='h'){
            add(a,b);add(a+1,b);
            C[M[has(a,b)]].push_back(M[has(a+1,b)]);
            C[M[has(a+1,b)]].push_back(M[has(a,b)]);
        }
        else{
            add(a,b);add(a,b+1);
            C[M[has(a,b)]].push_back(M[has(a,b+1)]);
            C[M[has(a,b+1)]].push_back(M[has(a,b)]);
        }
    }
    for(int c1 = 0; c1 < q; c1++){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;x1--;x2--;y1--;y2--;
        ll ans = 0;
        counter++;
        for(int c1 = 0; c1 < sz(used); c1++){
            ans += dfs(c1, -1, x1,x2,y1,y2);
        }
        cout << ans << "\n";
    }

    return 0;
}

