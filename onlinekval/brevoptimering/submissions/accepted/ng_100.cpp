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

vector<vi> C(1000000, vi());
vector<vector<double>> CW(1000000, vector<double>());
vector<double> production;

double IN[1000001] = {0};
bool seen[1000001] = {0};

double in(int i){
    if(sz(C[i]) == 0)return big*big;
    if(seen[i])return IN[i];
    double ans = 0;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        int a = C[i][c1];
        double w = CW[i][c1];
        double contribution = w*min(in(a),production[a]);
        ans += contribution;
    }
    IN[i] = ans;
    seen[i] = 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        production.push_back(a);
        cin >> a;
        for(int c2 = 0; c2 < a; c2++){
            double w;
            cin >> b >> w;
            b--;
            C[b].push_back(c1);
            CW[b].push_back(w/100.0);
        }
    }
    double eps = 0.00000001;
    for(int c1 = 0; c1 < n; c1++){
        //assert(abs(in(c1)-production[c1]) > 0.001 || sz(C[c1]) == 0);
        if(in(c1)-production[c1] > -eps)cout << c1+1 << " ";
    }

    return 0;
}
