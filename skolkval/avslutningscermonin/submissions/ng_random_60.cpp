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
int mark[41] = {0};

// Tries a bunch of random solutions, picks the best one.

int f(int c){
    for(int c1 = 0; c1 < n; c1++){
        B[c1] = A[c1];
    }
    for(int c1 = 0; c1 < n; c1++){
        if(mark[c1] == c)continue;
        int r = c1+rand()%(k+1);
        while(r > n-1 || mark[r] == c){
            r = c1+rand()%(k+1);
        }
        mark[c1] = c;
        mark[r] = c;
        swap(B[c1],B[r]);
    }
    int res = 0;
    for(int c1 = 0; c1 < n-1; c1++){
        res += (B[c1]==B[c1+1]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
	string s;
	cin >> s >> k;
	n = sz(s);

    int a,b,c,e;

    for(int c1 = 0; c1 < n; c1++){
		a = s[c1] - 'A';
		m = max(m, (ll)(a + 1));
        A.push_back(a);
        B.push_back(a);
    }

    int ans = 0;
    for(int c1 = 0; c1 < 1000000; c1++){
        a = f(c1);
        ans = max(ans,a);
    }
    cout << ans << "\n";

    return 0;
}
