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

const ll MAXN = 200000;

// Runs a (k <= 5)-solution, but breaks early and stops when the Dijkstra has visited 20 million vertices.

ll visits = 0;
ll threshold = 20000000;

vector<vl> C(MAXN,vl());
vector<vl> CW(MAXN,vl());

vl specials;
bool is_special[MAXN] = {0};

bool ANS[MAXN] = {0};

ll SPEC[MAXN] = {0};
ll DIST[MAXN] = {0};
ll UPD[MAXN] = {0};
ll counter = 0;
ll mark[MAXN] = {0};

void dijkstra(ll i){
    counter++;
    priority_queue<pll> pq;
    pq.push({0,i});
    UPD[i] = counter;
    DIST[i] = 0;
    SPEC[i] = 1;
    ll spcs = 0;
    while(!pq.empty()){
        ll a = pq.top().second;
        pq.pop();
        
        if(visits > threshold)return;
        
        if(mark[a] != counter){
            mark[a] = counter;
            spcs += is_special[a];
            if(is_special[a] && spcs != SPEC[a])return;
            if(SPEC[a] == k)ANS[a] = 1;
            for(int c1 = 0; c1 < sz(C[a]); c1++){
                    
                if(visits > threshold)return;
                    
                ll b = C[a][c1];
                ll w = CW[a][c1];
                if(UPD[b] == counter && DIST[b] == w+DIST[a]){
                    SPEC[b] = max(SPEC[b],SPEC[a]+is_special[b]);
                }
                if(UPD[b] != counter || DIST[b] > w+DIST[a]){
                    SPEC[b] = SPEC[a]+is_special[b];
                    DIST[b] = w+DIST[a];
                    UPD[b] = counter;
                    visits++;
                    pq.push({-DIST[b],b});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> m >> k;
   // assert((n <= 1000 && m <= 1000) || k <= 5);
    for(int c1 = 0;  c1 < k; c1++){
        cin >> a;
        a--;
        specials.push_back(a);
        is_special[a] = 1;
    }

    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b >> c;
        a--;b--;
        C[a].push_back(b);
        C[b].push_back(a);
        CW[a].push_back(c);
        CW[b].push_back(c);
    }

    for(int c1 = 0; c1 < k; c1++){
        dijkstra(specials[c1]);
    }
    a = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(ANS[c1])a++;
    }
    cout << a << "\n";
    for(int c1 = 0; c1 < n; c1++){
        if(ANS[c1]){cout << c1+1 << " ";}
    }

    return 0;
}
