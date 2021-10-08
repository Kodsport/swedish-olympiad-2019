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

vl D;
vi ind;
vi I;
vi J;

bool comp(int i, int j){
    return D[i] < D[j];
}

ll d2(ll x1, ll y1, ll x2, ll y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int best1[MAXN] = {0};
int best2[MAXN] = {0};

vi upd;

void reset(){
    for(int c1 = 0; c1 < sz(upd); c1++){
        best1[upd[c1]] = max(best1[upd[c1]],best2[upd[c1]]);
        best2[upd[c1]] = 0;
    }
    upd.clear();
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

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = c1+1; c2 < n; c2++){
            ind.push_back(sz(ind));
            I.push_back(c1);
            J.push_back(c2);
            D.push_back(d2(X[c1],Y[c1],X[c2],Y[c2]));
            ind.push_back(sz(ind));
            I.push_back(c2);
            J.push_back(c1);
            D.push_back(d2(X[c1],Y[c1],X[c2],Y[c2]));
        }
    }

    sort(all(ind),comp);

    ll prev = -123;

    for(int c1 = 0; c1 < n; c1++){
        best1[c1] = 1;
    }

    for(int c1 = 0; c1 < sz(ind); c1++){
        a = ind[c1];
        if(D[a] != prev)reset();
        best2[J[a]] = max(best2[J[a]], 1 + best1[I[a]]);
        upd.push_back(J[a]);
        prev = D[a];
    }
    reset();
    int ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ans = max(ans, best1[c1]);
    }
    cout << ans << "\n";
    return 0;
}

