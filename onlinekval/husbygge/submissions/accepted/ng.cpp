#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

int const MAXK = 40000;
int const MAXN = 1000;
int const MAXA = 101;

int n,m,k,T;
int A[MAXN][MAXN] = {};
vector<vector<pii> > buckets(MAXA, vector<pii>()); //points sorted w.r.t A
vector<pii> points;

int person[MAXN][MAXN] = {};
int X[MAXK] = {};
int Y[MAXK] = {};

int best_score = 0;
int X_ANS[MAXK] = {};
int Y_ANS[MAXK] = {};

mt19937 rng(8765878);
uniform_int_distribution<int> uid(0,1000000000);

int random(int r){
    return uid(rng)%r;
}

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

void reset_solution(){
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            person[c1][c2] = -1;
        }
    }
    for(int c1 = 0; c1 < k; c1++){
        X[c1] = -1;
        Y[c1] = -1;
    }
}

void move_person(int i, int x, int y){
    if(inbounds(X[i],Y[i])){
        person[X[i]][Y[i]] = -1;
    }
    person[x][y] = i;
    X[i] = x;
    Y[i] = y;
    return;
}

int personal_score(int i){
    assert(inbounds(X[i],Y[i]));
    assert(person[X[i]][Y[i]] == i);

    if(k*k < 3*n*m){  // If k is small, check all pairs instead of doing BFS.
        int mindist = 1e9;
        for(int c1 = 0; c1 < k; c1++){
            if(c1 != i)mindist = min(mindist, abs(X[c1]-X[i]) + abs(Y[c1]-Y[i]));
        }
        return mindist*A[X[i]][Y[i]];
    }

    int ans = A[X[i]][Y[i]];
    for(int c1 = 1; c1 <= n+m; c1++){
        bool found = 0;
        for(int c2 = -c1; c2 <= c1; c2++){
            int x = c2+X[i];
            int y1 = Y[i] + (c1-abs(c2));
            int y2 = Y[i] - (c1-abs(c2));
            if(inbounds(x,y1) && person[x][y1] != -1)found = 1;
            if(inbounds(x,y2) && person[x][y2] != -1)found = 1;
            if(found)break;
        }
        if(found)break;
        ans += A[X[i]][Y[i]];
    }
    return ans;
}

// Finds the score by running a BFS from each person
int score(){
    int ans = 0;
    for(int c1 = 0; c1 < k; c1++){
        ans += personal_score(c1);
    }
    return ans;
}

int q1,q2;
// Compares with respect to distance to (q1,q2)
bool comp1(pii p1, pii p2){
    return abs(p1.first-q1)+abs(p1.second-q2) > abs(p2.first-q1)+abs(p2.second-q2);
}

// Maximizes one persons happiness
void one_person_happy(){
    reset_solution();
    int startx = 0;
    int starty = 0;
    int start_score = 0;
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            int corner_dist = 0;
            corner_dist = max(corner_dist, c1+c2);
            corner_dist = max(corner_dist, c1+m-1-c2);
            corner_dist = max(corner_dist, n-1-c1+c2);
            corner_dist = max(corner_dist, n-1-c1+m-1-c2);
            int temp_score = corner_dist*A[c1][c2];
            if(temp_score > start_score){
                start_score = temp_score;
                startx = c1;
                starty = c2;
            }
        }
    }
    move_person(0,startx,starty);
    q1 = startx;
    q2 = starty;
    sort(all(points),comp1);
    for(int c1 = 1; c1 < k; c1++){
        move_person(c1,points[c1-1].first,points[c1-1].second);
    }
    int sc = score();
    if(sc > best_score){
        for(int c1 = 0; c1 < k; c1++){
            X_ANS[c1] = X[c1];
            Y_ANS[c1] = Y[c1];
        }
        best_score = sc;
    }
    return;
}

// Greedily places people so that the distance between any two is bigger than d.
// When there are no more "good" cells, it crams the remaining people in the upper left corner.
int bad[MAXN][MAXN] = {};
int gp_counter = 0;
void greedy_packing(int d, bool greedy_order = 1){
    gp_counter++;
    reset_solution();
    if(greedy_order){
        int j = 0;
        for(int c1 = 100; c1 >= 0; c1--){
            if(sz(buckets[c1]) > 0){
                shuffle(all(buckets[c1]),rng);
                for(int c2 = 0; c2 < sz(buckets[c1]); c2++){
                    points[j] = buckets[c1][c2];
                    j++;
                }
            }
        }
    }
    else{
        shuffle(all(points),rng);
    }
    int i = 0;
    for(int c1 = 0; c1 < n*m; c1++){
        int x = points[c1].first;
        int y = points[c1].second;
        if(bad[x][y] != gp_counter){
            move_person(i,x,y);
            i++;
            for(int c3 = -d; c3 <= d; c3++){
                for(int c4 = -(d-abs(c3)); c4 <= (d-abs(c3)); c4++){
                    int x2 = x+c3;
                    int y2 = y+c4;
                    if(inbounds(x2,y2)){
                        bad[x2][y2] = gp_counter;
                    }
                }
            }
        }
        if(i >= k)break;
    }

    if(i < k){
        for(int c1 = 0; c1 < n+m; c1++){
            for(int c2 = 0; c2 <= c1; c2++){
                int x = c1-c2;
                int y = c2;
                if(!inbounds(x,y))continue;
                if(person[x][y] != -1)continue;
                move_person(i,x,y);
                i++;
                if(i >= k)break;
            }
            if(i >= k)break;
        }
    }
    assert(i == k);
    int sc = score();
    if(sc > best_score){
        for(int c1 = 0; c1 < k; c1++){
            X_ANS[c1] = X[c1];
            Y_ANS[c1] = Y[c1];
        }
        best_score = sc;
    }
    return;
}

int const M1_MAXN = 201;
int const M1_MAXK = 31;
int dp_counter = 0;
int DPC[M1_MAXN][M1_MAXN][M1_MAXK] = {};
int DP[M1_MAXN][M1_MAXN][M1_MAXK] = {};
int NEX[M1_MAXN][M1_MAXN][M1_MAXK] = {};

int dp(int prev, int i, int left, int y = 0){
    if(left == 0)return 0;
    if(i >= n)return -1e9;
    if(DPC[prev+1][i+1][left] == dp_counter)return DP[prev][i+1][left];
    if(i == -1){
        int ans = 0;
        for(int c1 = 0; c1 < n; c1++){
            int temp = dp(-1,c1,left-1) + M1_MAXN*A[c1][y];
            if(temp > ans){
                ans = temp;
                NEX[prev+1][i+1][left] = c1;
                DP[prev+1][i+1][left] = ans;
                DPC[prev+1][i+1][left] = dp_counter;
            }
        }
        return ans;
    }
    int prev_dist;
    if(prev == -1){
        prev_dist = M1_MAXN;
    }
    else{
        prev_dist = i-prev;
    }
    int ans = -1e9;
    for(int c1 = i+1; c1 < n; c1++){
        int temp = A[c1][y]*(c1-i) + dp(i,c1,left-1) - A[i][y] * max(0,prev_dist-(c1-i));
        if(temp > ans){
            NEX[prev+1][i+1][left] = c1;
            ans = temp;
        }
    }
    DPC[prev+1][i+1][left] = dp_counter;
    DP[prev+1][i+1][left] = ans;
    return ans;
}

// Mostly for m=1.
void dp_solver(){
    reset_solution();
    dp_counter++;
    dp(-1,-1,k);

    int prev = -1;
    int i = -1;
    for(int c1 = 0; c1 < k; c1++){
        int j = NEX[prev+1][i+1][k-c1];
        prev = i;
        i = j;
        move_person(c1,i,0);
    }
    int sc = score();
    if(sc > best_score){
        for(int c1 = 0; c1 < k; c1++){
            X_ANS[c1] = X[c1];
            Y_ANS[c1] = Y[c1];
        }
        best_score = sc;
    }
    return;
}

void print_answer(){
    for(int c1 = 0; c1 < k; c1++){
        cout << X_ANS[c1]+1 << " " << Y_ANS[c1]+1 << "\n";
    }
    cerr << best_score << "\n";
    return;
}

//// (for debugging)
void print_all(){
    reset_solution();
    for(int c1 = 0; c1 < k; c1++){
        person[X_ANS[c1]][Y_ANS[c1]] = c1;
    }
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            if(person[c1][c2] != -1){
                cerr << 'X';
            }
            else{
                cerr << ' ';
            }
        }
        cerr << "\n";
    }
}
////

int solve(int t)
{
	T = t;
    cin >> n >> m >> k;

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            cin >> A[c1][c2];
            buckets[A[c1][c2]].push_back({c1,c2});
            points.push_back({c1,c2});
        }
    }

    if(m == 1){
        dp_solver();
        print_answer();
        return 0;
    }

    int good_d = (int)round(sqrt(double(n*m)/double(2*k)))-1;

    if(good_d > 10){
        one_person_happy();
    }

    if(n*m == 1e6){

        for(int c1 = -1; c1 <= 4; c1++){
            if(good_d+c1 >= 0){
                greedy_packing(c1+good_d);
            }
        }
        print_answer();
        return 0;
    }

    if(n*m < 1e6){
        int best_d = good_d;
        for(int c1 = -100; c1 <= 100; c1++){
            if(good_d+c1 >= 0){
                int old_score = best_score;
                greedy_packing(c1+good_d);
                if(best_score > old_score){
                    best_d = c1+good_d;
                }
            }
        }
        for(int c1 = 0; c1 < 800; c1++){
            greedy_packing(best_d);
        }
        print_answer();
        return 0;
    }

    return 0;
}

int main() {
    //freopen("T2.txt","r",stdin);
	int t;
    cin >> t;
	return solve(t);
}
