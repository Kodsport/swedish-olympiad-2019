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

const int MAXN = 200000;

vector<vl> C(MAXN, vl());
vector<vl> CW(MAXN, vl());
vl special;
bool is_special[MAXN] = {0};

vl ind;

// to check connectedness
bool connected(){
    bool mark[MAXN] = {0};
    int vis = 0;
    queue<ll> Q;
    Q.push(0);
    mark[0] = 1;
    vis++;
    while(!Q.empty()){
        ll i = Q.front();
        Q.pop();
        for(int c1 = 0; c1 < sz(C[i]); c1++){
            ll j = C[i][c1];
            if(!mark[j]){
                mark[j] = 1;
                vis++;
                Q.push(j);
            }
        }
    }
    return (vis == n);
}
//

ll upd[MAXN] = {0};
ll counter = 0;
ll DIST[MAXN] = {0};

void dijkstra(ll start){
    counter++;
    for(int c1 = 0; c1 < n; c1++){
        DIST[c1] = -1;
    }
    priority_queue<pll> pq;
    pq.push({0,start});
    DIST[start] = 0;
    while(!pq.empty()){
        ll i = pq.top().second;
        pq.pop();
        if(upd[i] != counter){
            upd[i] = counter;
            for(int c1 = 0; c1 < sz(C[i]); c1++){
                ll j = C[i][c1];
                ll w = CW[i][c1];
                if(DIST[j] == -1 || DIST[j] > DIST[i]+w){
                    DIST[j] = DIST[i]+w;
                    pq.push({-DIST[j],j});
                }
            }
        }
    }
}

ll start1, start2;

bool comp(ll i, ll j){
    return DIST[i] < DIST[j];
}

bool ANS[MAXN] = {0};
ll specials[MAXN] = {0};

void solve(ll start){
    dijkstra(start);
    sort(all(ind),comp);
    for(int c1 = 0; c1 < n; c1++){
        specials[c1] = 0;
    }
    for(int c1 = 0; c1 < n; c1++){
        ll a = ind[c1];
        specials[a] += is_special[a];
        if(specials[a] == k)ANS[a] = 1;
        for(int c2 = 0; c2 < sz(C[a]); c2++){
            ll j = C[a][c2];
            ll w = CW[a][c2];
            if(DIST[j] == DIST[a]+w)specials[j] = max(specials[a],specials[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n >> m >> k;
    for(int c1 = 0; c1 < k; c1++){
        cin >> a;
        a--;
        special.push_back(a);
        is_special[a] = 1;
    }
    for(int c1 = 0; c1 < n; c1++){
        ind.push_back(c1);
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
    assert(connected());

    if(k == 1){
        cout << n << "\n";
        for(int c1 = 0; c1 < n; c1++){
            cout << c1+1 << " ";
        }cout << "\n";
        return 0;
    }

    dijkstra(special[0]);
    start1 = 0;
    ll dmax = 0;
    for(int c1 = 0; c1 < sz(special); c1++){
        if(DIST[special[c1]] > dmax){
            dmax = DIST[special[c1]];
            start1 = special[c1];
        }
    }
    solve(start1);
    for(int c1 = 0; c1 < n; c1++){
        if(is_special[ind[c1]])start2 = ind[c1];
    }
    solve(start2);

    ll ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ans += ANS[c1];
    }
    cout << ans << "\n";
    int counter = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(ANS[c1]){
            if (counter++) cout.put(' ');
            cout << c1+1;
        }
    }
    cout << "\n";
    return 0;
}

