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
const ll big = 1100000000;

const ll MAXN = 100;
const ll MAXX = 99999;
const ll MAXT = 1000000000;

struct pt{
    ll x,y;
};

vector<pt> starts;
vector<pt> blocks;
vl X;
vl Y;
vector<pll> XI;
vector<pll> YI;
set<ll> blocked;
vector<vector<pt> > rect(400001, vector<pt>());
vector<vl> ID(400001, vl());
unordered_map<ll,ll> M;   // Point to rectangle ID
ll rects = 0;

vector<pt> allpoints;
unordered_map<ll,ll> M2;  // Point to allpoints ID

vector<vl> graph(400000,vl());
vector<vl> weights(400000,vl());

ll DX[4] = {0,0,-1,1};
ll DY[4] = {1,-1,0,0};

ll has(ll x, ll y){
    ll base = 2ll * big;
    return x*base+y;
}

ll dist(pt p1, pt p2){
    return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}

ll corner(ll d){
    if(d < 0)return 0;
    return ((d+1)*(d+2))/2;
}

ll side(ll d1, ll d2, ll L){
    ll ans = 0;
    for(ll x = 0; x < L; x++){
        ll temp = 0;
        temp = max(temp, d1-x+1);
        temp = max(temp, d2-(L-1-x)+1);
        ans += temp;
    }
    return ans;
}

ll rectangle(ll d1, ll d2, ll d3, ll d4, ll L1, ll L2){
    if(L1 > L2){
        return rectangle(d1,d3,d2,d4,L2,L1);
    }
    ll ans = 0;
    for(ll x = 0; x < L1; x++){
        ll temp1 = 0;
        temp1 = max(temp1, d1-x+1);
        temp1 = max(temp1, d2-(L1-1-x)+1);
        ll temp2 = 0;
        temp2 = max(temp2, d3-x+1);
        temp2 = max(temp2, d4-(L1-1-x)+1);
        ans += min(temp1+temp2,L2);
    }
    return ans;
}

bool is_blocked(ll x, ll y){
    if(x < 0 || y < 0 || x > MAXX || y > MAXX)return 0;
    return (blocked.find(x*MAXX+y) != blocked.end());
}

bool BLOCKED[1000001] = {0};

void addedge(ll i, ll j, ll w){
    if(i == j)return;
    if(!(BLOCKED[i] || BLOCKED[j])){
        graph[i].push_back(j);
        graph[j].push_back(i);
        weights[i].push_back(w);
        weights[j].push_back(w);
    }
}

ll DIST[400001] = {0};
bool mark[400001] = {0};

void dijkstra(){
    priority_queue<pll> pq;
    for(ll c1 = 0; c1 < sz(allpoints); c1++){
        DIST[c1] = big;
    }
    for(ll c1 = 0; c1 < n; c1++){
        ll i = M2[has(starts[c1].x,starts[c1].y)];
        pq.push({0,i});
        DIST[i] = 0;
    }
    ll vis = 0;
    while(!pq.empty()){
        vis++;
        ll a = pq.top().second;
        pq.pop();
        if(!mark[a]){
            mark[a] = 1;
            for(ll c1 = 0; c1 < sz(graph[a]); c1++){
                ll b = graph[a][c1];
                ll w = weights[a][c1];
                if(DIST[b] == big || DIST[b] > DIST[a]+w){
                    DIST[b] = DIST[a]+w;
                    pq.push({-DIST[b],b});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> T;
    assert(n <= MAXN && n > 0);
    assert(m <= MAXN && m >= 0);
    assert(T <= MAXT && T >= 0);
    for(int c1 = 0; c1 < n; c1++){
        ll a,b;
        cin >> a >> b;
        assert(a <= MAXX && b <= MAXX && a >= 0 && b >= 0);
        starts.push_back({a,b});
        X.push_back(a);
        Y.push_back(b);
    }
    for(int c1 = 0; c1 < m; c1++){
        ll a,b;
        cin >> a >> b;
        assert(a <= MAXX && b <= MAXX && a >= 0 && b >= 0);
        blocks.push_back({a,b});
        blocked.insert(a*MAXX+b);
        X.push_back(a);
        Y.push_back(b);
    }
    X.push_back(-big);
    X.push_back(big);
    Y.push_back(-big);
    Y.push_back(big);
    sort(all(X));
    sort(all(Y));

    ll prevx = -big;
    for(ll c1 = 1; c1 < sz(X); c1++){
        if(X[c1] == prevx)continue;
        if(X[c1] > prevx+1){
            XI.push_back({prevx+1, X[c1]-1});
        }
        if(X[c1] != big)XI.push_back({X[c1],X[c1]});
        prevx = X[c1];
    }

    ll prevy = -big;
    for(ll c1 = 1; c1 < sz(Y); c1++){
        if(Y[c1] == prevy)continue;
        if(Y[c1] > prevy+1){
            YI.push_back({prevy+1, Y[c1]-1});
        }
        if(Y[c1] != big)YI.push_back({Y[c1],Y[c1]});
        prevy = Y[c1];
    }

    for(ll c1 = 0; c1 < sz(XI); c1++){
        for(ll c2 = 0; c2 < sz(YI); c2++){
            ll r = c1*sz(YI)+c2;
            rects++;
            vl X2;
            vl Y2;
            X2.push_back(XI[c1].first);
            X2.push_back(XI[c1].second);
            Y2.push_back(YI[c2].first);
            Y2.push_back(YI[c2].second);
            for(ll c3 = 0; c3 < 2; c3++){
                for(ll c4 = 0; c4 < 2; c4++){
                    rect[r].push_back({X2[c3],Y2[c4]});
                    ll a = has(X2[c3],Y2[c4]);
                    if(M.find(a) == M.end()){
                        M[has(X2[c3],Y2[c4])] = r;
                        M2[has(X2[c3],Y2[c4])] = sz(allpoints);
                        if(is_blocked(X2[c3],Y2[c3])){
                            BLOCKED[sz(allpoints)] = 1;
                        }
                        allpoints.push_back({X2[c3],Y2[c4]});

                    }
                    ID[r].push_back(M2[has(X2[c3],Y2[c4])]);
                }
            }
        }
    }
    for(ll c1 = 0; c1 < rects; c1++){
        for(ll c2 = 0; c2 < sz(rect[c1]); c2++){
            for(ll c3 = c2+1; c3 < sz(rect[c1]); c3++){
                ll id1 = ID[c1][c2];
                ll id2 = ID[c1][c3];
                if(rect[c1][c2].x != rect[c1][c3].x && rect[c1][c2].y != rect[c1][c3].y)continue;
                addedge(id1,id2,dist(rect[c1][c2],rect[c1][c3]));

            }
            for(ll c3 = 0; c3 < 4; c3++){
                ll x2 = rect[c1][c2].x+DX[c3];
                ll y2 = rect[c1][c2].y+DY[c3];
                ll hsh = has(x2,y2);
                if(M.find(hsh) != M.end()){
                    if(M[hsh] != c1){
                        ll id1 = ID[c1][c2];
                        ll id2 = M2[hsh];
                        addedge(id1,id2,1);
                    }
                }
            }
        }
    }

    /*
    ll edges = 0;
    for(ll c1 = 0; c1 < sz(allpoints); c1++){
        edges += sz(graph[c1]);
    }

    cerr << sz(allpoints) << " "<< edges/2 << "\n";
    */
    dijkstra();

    ll ans = 0;
    for(ll c1 = 0; c1 < rects; c1++){
        ll d1 = T-DIST[ID[c1][0]];
        ll d2 = T-DIST[ID[c1][1]];
        ll d3 = T-DIST[ID[c1][2]];
        ll d4 = T-DIST[ID[c1][3]];
        ll L2 = abs(rect[c1][0].x-rect[c1][2].x)+1;
        ll L1 = abs(rect[c1][0].y-rect[c1][1].y)+1;
        if(L1 > 100000000 && L2 > 100000000){
            ans += corner(max(d1,max(d2,max(d3,d4))));
        }
        else{
            ans += rectangle(d1,d2,d3,d4,L1,L2);
        }
    }
    cout << ans << "\n";
    return 0;
}

