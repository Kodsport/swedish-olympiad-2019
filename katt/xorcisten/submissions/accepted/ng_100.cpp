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

const int MAXN = 1000000;

int nums[MAXN];
int N[2][30];
ll masks[MAXN];

int get_bit(ll a, ll i){
    return (((1ll << i)&a)!=0);
}

void remove_mask(int i){
    for(int c1 = 0; c1 < 60; c1+=2){
        N[0][c1/2] -= get_bit(masks[i],c1);
        N[1][c1/2] -= get_bit(masks[i],c1+1);
    }
}

ll get_mask(int a, int b){
    ll res = 0;
    bool same = 1;
    for(int c1 = 29; c1 >= 0; c1--){
        res *= 4;
        if(!same || get_bit(a,c1) == get_bit(b,c1)){
            res += 3;
            N[0][c1]++;
            N[1][c1]++;
        }
        else{
            if(get_bit(a,c1) == 0){
                res += 1;
                N[0][c1]++;
            }
            else{
                N[1][c1]++;
                res += 2;
            }
            same = 0;
        }
    }
    return res;
}

void modify(int i, int v){
    nums[i] = v;
    if(i > 0){
        remove_mask(i-1);
        masks[i-1] = get_mask(nums[i-1],nums[i]);
    }
    if(i < n-1){
        remove_mask(i);
        masks[i] = get_mask(nums[i],nums[i+1]);
    }
}

int solve(){
    int ans = 0;
    for(int c1 = 29; c1 >= 0; c1--){
        ans *= 2;
        if(N[0][c1] != n-1){
            if(N[1][c1] == n-1){
                ans++;
            }
            else{
                return -1;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b;

    cin >> n;
    int prev = -1;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        nums[c1] = a;
        if(c1 > 0)masks[c1-1] = get_mask(prev,a);
        prev = a;
    }
    cin >> q;
    cout << solve() << "\n";
    for(int c1 = 0; c1 < q; c1++){
        cin >> a >> b;
        a--;
        modify(a,b);
        cout << solve() << "\n";
    }
    return 0;
}
