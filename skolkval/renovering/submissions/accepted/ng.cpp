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

vi A,B;

int main(){
    int a,b,c;
    cin >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    for(int c1 = 0; c1 < m; c1++){
        cin >> a;
        B.push_back(a);
    }
    sort(all(A));
    sort(all(B));
    for(int c1 = sz(B)-1; c1 >= 0; c1--){
        for(int c2 = sz(A)-1; c2 >= 0; c2--){
            if(A[c2] != 0 && A[c2] <= B[c1]){
                A[c2] = 0;
                break;
            }
        }
    }
    int a1 = 0;
    int a2 = 0;
    for(int c1 = 0; c1 < sz(A); c1++){
        if(A[c1] != 0){
            a1++;
        }
    }
    cout << a1 << "\n";
    for(int c1 = 0; c1 < sz(A); c1++){
        if(A[c1] != 0)cout << A[c1] << " ";
    }
    return 0;
}
