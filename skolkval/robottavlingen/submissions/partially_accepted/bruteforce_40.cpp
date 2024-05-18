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

vi A;
vi B;

int M[11][11] = {0};

int low = big;
int high = 0;

void brute(int i, int j){
    if(i == n){
        bool yes = 1;
        int sum = 0;
        for(int c1 = 0; c1 < n; c1++){
            int ma = 0;
            for(int c2 = 0; c2 < n; c2++){
                ma = max(ma,M[c1][c2]);
                sum += M[c1][c2];
            }
            if(ma != A[c1])yes = 0;
        }
        for(int c1 = 0; c1 < n; c1++){
            int ma = 0;
            for(int c2 = 0; c2 < n; c2++){
                ma = max(ma,M[c2][c1]);
            }
            if(ma != B[c1])yes = 0;
        }
        if(yes){
            low = min(low,sum);
            high = max(high,sum);
        }
        return;
    }
    if(j == n){
        brute(i+1,0);
        return;
    }
    for(int c1 = 1; c1 <= 5; c1++){
        M[i][j] = c1;
        brute(i,j+1);
    }
    return;
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
    assert(n <= 3);
    brute(0,0);
    cout << low << " " << high << "\n";

    return 0;
}

