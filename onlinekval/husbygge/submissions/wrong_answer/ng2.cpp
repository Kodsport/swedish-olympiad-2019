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
double average = 0.0;

int person[MAXN][MAXN] = {0};
int X[MAXK] = {};
int Y[MAXK] = {};

int best_score = 0;
int X_ANS[MAXK] = {};
int Y_ANS[MAXK] = {};

mt19937 rng(8765878);
uniform_int_distribution<int> uid(0,1000000000);

int DX[4] = {0,0,1,-1};
int DY[4] = {1,-1,0,0};

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

int personal_score(int i);

int lazy_score[MAXK] = {};
bool lazy_valid = 0;

void move_person(int i, int x, int y, int lazy = 0){
    if(inbounds(X[i],Y[i])){
        person[X[i]][Y[i]] = -1;
    }
    int x2 = X[i];
    int y2 = Y[i];
    person[x][y] = i;
    X[i] = x;
    Y[i] = y;
    if(lazy){
        for(int c1 = 0;  c1 < k; c1++){
            assert(inbounds(X[c1],Y[c1]));
            if(lazy_valid == 0 || c1 == i || lazy_score[c1] == (abs(x2-X[c1]) + abs(y2-Y[c1]))*A[X[c1]][Y[c1]]){
                lazy_score[c1] = personal_score(c1);
            }
            else{
                lazy_score[c1] = min(lazy_score[c1], (abs(x-X[c1]) + abs(y-Y[c1]))*A[X[c1]][Y[c1]]);
            }
        }
        lazy_valid = 1;
    }
    else{
        lazy_valid = 0;
    }
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
        if(lazy_valid){
            ans += lazy_score[c1];
        }
        else{
            ans += personal_score(c1);
        }
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


bool comp2(pii p1, pii p2){
    return p1.first*m+p1.second < p2.first*m+p2.second;
}

// Greedily places people so that the distance between any two is bigger than d.
// When there are no more "good" cells, it crams the remaining people in the upper left corner.
int bad[MAXN][MAXN] = {0};
int gp_counter = 0;
void greedy_packing(int d, bool place_in_corner = 1, bool greedy_order = 1, bool weighted = 0){
    gp_counter++;
    reset_solution();
    //if(greedy_order){
        int j = 0;
        for(int c1 = MAXA-1; c1 >= 0; c1--){
            if(sz(buckets[c1]) > 0){
                if(greedy_order){
                    shuffle(all(buckets[c1]),rng);
                }
                else{
                    sort(all(buckets[c1]),comp2);
                }
                for(int c2 = 0; c2 < sz(buckets[c1]); c2++){
                    points[j] = buckets[c1][c2];
                    j++;
                }
            }
        }
    //}
    /*
    else{
        for(int c1 = 0; c1 < n; c1++){
            for(int c2 = 0; c2 < m; c2++){
                points[c1*m+c2] = {c1,c2};
            }
        }
    }
    */
    int i = 0;
    for(int c1 = 0; c1 < n*m; c1++){
        int x = points[c1].first;
        int y = points[c1].second;
        if(bad[x][y] != gp_counter){
            move_person(i,x,y);
            i++;
            int dist = d;
            if(weighted)dist = d/(A[x][y]+1);
            for(int c3 = -dist; c3 <= dist; c3++){
                for(int c4 = -(dist-abs(c3)); c4 <= (dist-abs(c3)); c4++){
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
        if(!place_in_corner){
            for(int c1 = i; c1 < k; c1++){
                int x = random(n);
                int y = random(m);
                while(person[x][y] != -1){
                    x = random(n);
                    y = random(m);
                }
                move_person(c1,x,y);

            }i=k;
        }
        else{
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

void hill_climb(int iterations){
    reset_solution();
    for(int c1 = 0; c1 < k; c1++){
        X[c1] = X_ANS[c1];
        Y[c1] = Y_ANS[c1];
        person[X[c1]][Y[c1]] = c1;
    }
    int old_score = best_score;
    for(int c1 = 0; c1 < iterations; c1++){
        int i = random(k);


        for(int c2 = 0; c2 < 4; c2++){
            int x2 = X[i]+DX[c2];
            int y2 = Y[i]+DY[c2];
            if(inbounds(x2,y2) && person[x2][y2] == -1){
                move_person(i,x2,y2,1);
                int new_score = score();
                if(new_score > old_score){
                    old_score = new_score;
                    break;
                }
                else{
                    move_person(i,x2-DX[c2],y2-DY[c2],1);
                }
            }
        }


    }
    int sc = score();
    if(sc > best_score){
        for(int c1 = 0; c1 < k; c1++){
            X_ANS[c1] = X[c1];
            Y_ANS[c1] = Y[c1];
        }
        best_score = sc;
    }
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
    //cerr << best_score << "\n";
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

void solve_blank(){
    for(int c1 = 0; c1 <=n+m; c1++){
        greedy_packing(c1,1,0);
    }
}

void run_solutions(int low, int high, int iterations, bool corner, bool weighted = 0){
    double extra = 1.0;
    if(weighted)extra = average;
    int good_d = (int)round(extra*sqrt(double(n*m)/double(2*k))-extra);
    int best_d = good_d;
    for(int c1 = low; c1 <= high; c1++){
        if(good_d+c1 >= 0){
            int old_score = best_score;
            greedy_packing(c1+good_d,corner,1,weighted);
            if(best_score > old_score){
                best_d = c1+good_d;
            }
        }
    }
    for(int c1 = 0; c1 < iterations; c1++){
        greedy_packing(best_d,corner,1,weighted);
    }
}


int solve(int t){
    T = t;
    cin >> n >> m >> k;

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            cin >> A[c1][c2];
            average += A[c1][c2];
            buckets[A[c1][c2]].push_back({c1,c2});
            points.push_back({c1,c2});
        }
    }
    average /= double(n*m);

    switch(T){
        case 1:
            solve_blank();
            hill_climb(20000);
            print_answer();
            break;
        case 2:
            run_solutions(-100,100,1000,0);
            hill_climb(10000);
            print_answer();
            break;
        case 3:
            dp_solver();
            print_answer();
            break;
        case 4:
            run_solutions(-2,3,1,0);
            hill_climb(50);
            print_answer();
            break;
        case 5:
            run_solutions(-100,100,1000,1);
            hill_climb(10000);
            print_answer();
            break;
        case 6:
            run_solutions(-2,3,5,1);
            hill_climb(80);
            print_answer();
            break;
        case 7:
            run_solutions(-100,100,1000,1);
            hill_climb(10000);
            print_answer();
            break;
        case 8:
            run_solutions(-100,100,1000,1);
            hill_climb(20000);
            print_answer();
            break;
        case 9:
            run_solutions(-2,3,1,1);
            hill_climb(20);
            print_answer();
            break;
        case 10:
            //run_solutions(-100,100,2000,0);
            solve_blank();
            hill_climb(8000);
            print_answer();
            break;
        default:
            run_solutions(-2,3,1,1);
            print_answer();
            break;
    }
    return 0;
}

int main()
{
	cout << "wrong answer to avoid getting more than 10 points on any testcase" << endl;
   // freopen("case09.in","r",stdin);
    int t;
    cin >> t;
    return solve(t);
}
