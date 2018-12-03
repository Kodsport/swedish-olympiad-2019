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

int maxv[11][11] = {0};
vi A;
vi B;

int M[11][11] = {0};

bool verify_row(int i){
    int ma = 0;
    for(int c1 = 0; c1 < n; c1++){
        ma = max(ma, M[i][c1]);
    }
    return (ma == A[i]);
}

bool verify_col(int i){
    int ma = 0;
    for(int c1 = 0; c1 < n; c1++){
        ma = max(ma, M[c1][i]);
    }
    return (ma == B[i]);
}

int low = big;
int high = 0;

int lim = 1000000;
int counter = 0;

void backtrack(int i, int sum){
    if(i == n*n){
        low = min(low,sum);
        high = max(high,sum);
        return;
    }
    counter++;
    if(counter >= lim)return;

    int r = i/n;
    int c = i%n;

    vi D;
    for(int c1 = 1; c1 <= maxv[r][c]; c1++){
        D.push_back(c1);
    }
   // random_shuffle(all(D));

    for(int c1 = 0; c1 < maxv[r][c]; c1++){
        M[r][c] = D[c1];
        bool yes = 1;
        if(c == n-1){
            yes &= verify_row(r);
        }
        if(r == n-1){
            yes &= verify_col(c);
        }
        if(yes){
            backtrack(i+1,sum+D[c1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        B.push_back(a);
    }

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < n; c2++){
            maxv[c1][c2] = min(A[c1],B[c2]);
        }
    }
    backtrack(0,0);
    cout << low << " " << high << "\n";
    return 0;
}

