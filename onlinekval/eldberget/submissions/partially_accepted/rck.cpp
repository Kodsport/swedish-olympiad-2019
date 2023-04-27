#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
    cin.sync_with_stdio(false);
    ll r,c,k;
    cin>>r>>c>>k;
    vector<vector<bool>> fire(r,vector<bool>(c));
    rep(i,0,r)
        rep(j,0,c){
            char c;
            cin>>c;
            fire[i][j] = c=='#';
       } 
    queue<tuple<ll,ll,ll,ll>> q;
    q.emplace(0,0,0,0);
    vector<vector<vector<bool>>> seen(r,vector<vector<bool>>(c,vector<bool>(k)));
    while(q.size()){
        ll x,y,f,s;
        tie(x,y,f,s) = q.front();
        q.pop();
        if(x<0||x>=r||y<0||y>=c) continue;
        f += fire[x][y];
        if(f>k||seen[x][y][f]) continue;
        seen[x][y][f] = true;
        if(x==r-1&&y==c-1){
           cout<<s<<endl;
           return 0;
        }
        q.emplace(x,y-1,f,s+1);
        q.emplace(x+1,y,f,s+1);
        q.emplace(x,y+1,f,s+1);
        q.emplace(x-1,y,f,s+1);
    }
    cout<<"nej"<<endl;
}

