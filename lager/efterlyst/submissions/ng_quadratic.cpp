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

ll n,m,T,k;
const ll big = 1000000007;
const ll big2 = 998244353;

const int MAXN = 1000;

vector<vl> C(MAXN, vl());
vector<vl> CW(MAXN, vl());
vl special;
bool is_special[MAXN] = {0};
ll DIST[MAXN][MAXN] = {0};
bool ANS[MAXN] = {0};
ll mark[MAXN] = {0};
ll counter = 0;

void dijkstra(ll i){
    counter++;
    priority_queue<pll> pq;
    pq.push({0,i});
    DIST[i][i] = 1;
    while(!pq.empty()){
        ll j = pq.top().second;
        pq.pop();
        if(mark[j] != counter){
            mark[j] = counter;
            for(int c1 = 0; c1 < sz(C[j]); c1++){
                ll j2 = C[j][c1];
                ll w = CW[j][c1];
                if(DIST[i][j2] == 0 || DIST[i][j2] > DIST[i][j]+w){
                    DIST[i][j2] = DIST[i][j]+w;
                    pq.push({-DIST[i][j2],j2});
                }
            }
        }
    }
}

ll testing = 0;
bool comp(ll i, ll j){
    return DIST[testing][i] < DIST[testing][j];
}

bool test(ll i){
    testing = i;
    sort(all(special),comp);
    ll d1 = DIST[i][special[k-1]]-1;
    ll d2 = DIST[i][special[0]]-1;
    for(int c1 = 1; c1 < k; c1++){
        d2 += DIST[special[c1-1]][special[c1]]-1;
    }
    return (d1 == d2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> m >> k;
    for(int c1 = 0; c1 < k; c1++){
        cin >> a;
        a--;
        special.push_back(a);
        is_special[a] = 1;
    }
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b >> c;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
        CW[a].push_back(c);
        CW[b].push_back(c);
    }
    assert(n <= MAXN && m <= MAXN);

    for(int c1 = 0; c1 < n; c1++){
        dijkstra(c1);
    }
    a = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(test(c1)){
            a++;
            ANS[c1] = 1;
        }
    }
    cout << a << "\n";
    if(a > 0){
        for(int c1 = 0; c1 < n; c1++){
            if(ANS[c1])cout << c1+1 << " ";
        }
        cout << "\n";
    }

    return 0;
}

