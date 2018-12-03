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

ll n,m,T,k,d;
const ll big = 1000000007;

string s;
int ANS[101] = {0};

int M[101][101] = {0};
bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

void simulate(int x, int y, int dx, int dy, int i){
    if(i >= k)return;
    int j = i;
    if(M[x][y] == -1){
        M[x][y] = i;
        j++;
    }
    if(x+dx < 0 || x+dx >= n)return simulate(x-dx,y+dy,-dx,dy,j);
    if(y+dy < 0 || y+dy >= m)return simulate(x+dx,y-dy,dx,-dy,j);
    simulate(x+dx,y+dy,dx,dy,j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,e;

    cin >> n >> m;
    cin >> s;
	k = sz(s);
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            M[c1][c2] = -1;
        }
    }
    simulate(0,0,1,1,0);
    int seen = 0;
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            if(M[c1][c2] != -1){
                ANS[M[c1][c2]] = seen;
                seen++;
            }
        }
    }
    for(int c1 = 0; c1 < k; c1++){
        cout << s[ANS[c1]];
    }
    return 0;
}
