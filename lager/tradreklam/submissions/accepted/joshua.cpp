#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")//,tune=native")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = int(1e9);

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> p2;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (int i = high-1; i >= 0; i--)

#define _LOCAL _MSC_VER
#if _LOCAL > 0
#define deb __debugbreak();
#define assert(x) debassert(x)
#define popcount(x) __popcnt(x)
#define clz(x) _lzcnt_u32(x)
#else
#define clz(x) __builtin_clz(x)
#define deb ;
#define popcount(x) __builtin_popcountll(x)
#endif

inline void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

#ifdef _DEBUG
#define debassert(expr) if(!(expr)) deb;
#else
#define debassert(expr) ;
#endif

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define setcontains(set, x) (set.find(x) != set.end())
#define sz(container) ((int)container.size())
vector<p2> dirs = { {0,1},{0,-1},{1,0},{-1,0} };

// time and rng
auto Start = chrono::high_resolution_clock::now();
void resettimer() { Start = chrono::high_resolution_clock::now(); }
int elapsedmillis() { return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count(); }
random_device rd;
mt19937 rng(rd());
template<typename T, typename U> inline int randint(T lo, U hi) { return uniform_int_distribution<int>((int)lo, (int)hi)(rng); } // [lo,hi]
template<typename T> inline T randel(vector<T>& v) { return v[uniform_int_distribution<int>(int(0), int(v.size()) - int(1))(rng)]; } // [lo,hi]

int n;
int tin[2000];
int tout[2000];
int profit[2000];
int cost[2000];
int timer = 0;
int dfs(int u, int p, int c, vector<vector<p2>>& edges, vi& pop)
{
	cost[u] = c;
	int ret = pop[u];
	tin[timer++] = u;

	repe(e, edges[u]) if(e.first!=p) ret += dfs(e.first, u, e.second, edges, pop);

	tout[u] = timer;
	return profit[u]=ret;
}

int dp[2000][30001];
int best(int i, int c)
{
	if (i == n) return 0;
	int& v = dp[i][c];
	if (v != -1) return v;

	int ret = 0;
	int u = tin[i];
	ret = max(ret, best(i + 1, c));
	if (c>=cost[u]) ret = max(ret, profit[u] + best(tout[u], c - cost[u]));


	return v = ret;
}

signed main()
{
	fast();

	//ifstream in("c:\\users\\matis\\desktop\\comp_prog\\x64\\debug\\in.txt");
	//cin.rdbuf(in.rdbuf());

	int b;
	cin >> n >> b;

	vector<vector<p2>> edges(n);
	vi population(n);
	rep(i, n - 1)
	{
		cin >> population[i + 1];
	}

	memset(tin, -1, sizeof(tin));
	rep(i, n - 1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edges[a].emplace_back(b, c);
		edges[b].emplace_back(a, c);
	}

	dfs(0, 0, inf, edges, population);
	
	memset(dp, 0, sizeof(dp));
	vi best(n);

	auto add = [&](int me, int nextnode)
	{
		if (nextnode == -1) return;
		int u = tin[me];
		int c = cost[u];
		rep(j, b+1)
		{
			if (j - c >= 0) dp[nextnode][j] = max(dp[nextnode][j], profit[u] + dp[u][j - c]);
		}
	};
	rep(i, n)
	{
		int u = tin[i];
		int c = cost[u];
		
		add(i, tin[tout[tin[i]]]);
		if (i + 1 < n)
		{
			rep(j, b+1) dp[tin[i + 1]][j] = max(dp[tin[i + 1]][j], dp[u][j]);
		}
		per(j, b+1) if (j - c >= 0) dp[u][j] = max(dp[u][j], profit[u] + dp[u][j - c]);
	}
	int ans = 0;
	rep(i, n) rep(j, b + 1) ans = max(ans, dp[i][j]);
	cout << ans << endl;

	_Exit(0);
}
