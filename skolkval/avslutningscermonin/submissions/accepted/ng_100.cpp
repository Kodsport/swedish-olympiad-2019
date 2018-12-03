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

int DP[40][6] = {0};
bool DPC[40][6] = {0};

int dp(int i, int last){
    if(i == n)return 0;
    if(DPC[i][last])return DP[i][last];
    int ans = (A[i] == last) + dp(i+1,A[i]);
    if(i < n-1)ans = max(ans, (A[i+1] == last) + (A[i] == A[i+1]) + dp(i+2,A[i]));
    if(i < n-2 && k == 2)ans = max(ans, (A[i+2] == last) + (A[i+2] == A[i+1]) + (A[i+1] == A[i]) + dp(i+3,A[i]));
    if(i < n-3 && k == 2)ans = max(ans, (A[i+2] == last) + (A[i+2] == A[i+3]) + (A[i+3] == A[i]) + (A[i] == A[i+1]) + dp(i+4,A[i+1]));
    DPC[i][last] = 1;
    DP[i][last] = ans;
    return ans;
}

int main(){
	string s;
	cin >> s >> k;
	n = sz(s);
    for(int c1 = 0; c1 < n; c1++){
        A.push_back(s[c1] - 'A');
		m = max(m, (ll)(A.back() + 1));
    }
    cout << dp(0,5) << "\n";

    return 0;
}
