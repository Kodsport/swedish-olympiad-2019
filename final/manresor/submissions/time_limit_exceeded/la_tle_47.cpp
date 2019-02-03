#include <bits/stdc++.h>
using namespace std;

int INF = 2*1e9;
int N,M,K;
vector<int> d,g,p,r;

int get_smallest_price(int distance){
    int lo = -1, hi = M-1;
    while(hi - lo > 1){
        int mid = (hi+lo)/2;
        if(g[mid] >= distance) hi = mid;
        else lo = mid;
    }
    return p[hi];
}

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){int temp; cin >> temp; d.push_back(temp);}
    for(int i = 0; i < M; i++){int temp; cin >> temp; g.push_back(temp);}
    for(int i = 0; i < M; i++){int temp; cin >> temp; p.push_back(temp);}
    for(int i = 0; i < K; i++){int temp; cin >> temp; r.push_back(temp);}
    vector<int> prev_discount;
    if(K>0){
        for(auto day : d){
            if(r[0] > day){prev_discount.push_back(-1); continue;}
            int lo = 0, hi = K;
            while(hi - lo > 1){
                int mid = (hi+lo)/2;
                if(r[mid] > day) hi = mid;
                else lo = mid;
            }
            prev_discount.push_back(r[lo]);
        }
    }

    vector<vector<int> > cost(N,vector<int>(N,-1));
    for(int i = 0; i < N; i++) cost[i][i] = p[0];
    for(int i = 0; i < N; i++){
        if(K > 0 && prev_discount[i] != -1 && d[i]-prev_discount[i]+1 <= g.back()){
            cost[i][i] = min(cost[i][i],get_smallest_price(d[i]-prev_discount[i]+1)/2);
        }
    }

    for(int diff = 1; diff < N; diff++){
        for(int fr = 0; fr < N-diff; fr++){
            int to = fr+diff;
            int min_cost = INF;
            if(d[to]-d[fr]+1 <= g.back()) min_cost = get_smallest_price(d[to]-d[fr]+1);
            if(K>0 && prev_discount[fr] != -1 && d[to]-prev_discount[fr]+1<=g.back()){
                min_cost = min(min_cost,get_smallest_price(d[to]-prev_discount[fr]+1)/2);
            }
            for(int mid = fr; mid < to; mid++){
                min_cost = min(min_cost,cost[fr][mid]+cost[mid+1][to]);
            }
            cost[fr][to] = min_cost;
        }
    }

    cout << cost[0][N-1] << endl;
    return 0;
}
