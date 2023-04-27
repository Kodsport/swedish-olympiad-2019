#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> X;
vector<int> Y;
int DP[3001][3001] = {0};
int n;

ll dist(int i, int j){
    ll x1 = X[i];
    ll x2 = X[j];
    ll y1 = Y[i];
    ll y2 = Y[j];
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int dp(int to , int from){
    ll d = dist(to,from);
    int ans = 0;
    if(DP[to][from] != -1)return DP[to][from];
    for(int c1 = 0; c1 < n; c1++){
        if(c1 != to){
            ll d2 = dist(to,c1);
            if(d2 > d){
                ans = max(ans , dp(c1,to));
            }
        }
    }
    DP[to][from] = ans+1;
    return ans+1;
}

int main()
{
    cin >> n;
    assert(n <= 200);
    for(int c = 0; c < n; c++){
        int x,y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
        for(int c2 = 0; c2 < n; c2++){
            DP[c][c2] = -1;
        }
    }
    int ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ans = max(ans , dp(c1,c1));
    }
    cout << ans << "\n";
    return 0;
}

