#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000 * 1000;

vector <int> vertex[size];
char tp[size];
int x[size], y[size];
vector <pair <int, int> > vec;
bool used[size];   

int xmin, xmax, ymin, ymax;
int w, h, n, q;

bool onfield(int x, int y) {
	return x >= xmin && x <= xmax && y >= ymin && y <= ymax;
}

void dfs(int v) {
	if (!onfield(vec[v].fs, vec[v].sc))
		return;

	used[v] = true;
	for (int i = 0; i < (int) vertex[v].size(); i++)
		if (!used[vertex[v][i]])
			dfs(vertex[v][i]);
}

int main() {
    scanf("%d%d", &w, &h);
    scanf("%d%d", &n, &q);

    for (int i = 0; i < n - 1; i++) {
    	scanf(" %c %d %d", &tp[i], &x[i], &y[i]);
    	vec.pb(mp(x[i], y[i]));
    	if (tp[i] == 'h')
    		vec.pb(mp(x[i] + 1, y[i]));
    	if (tp[i] == 'v')
    		vec.pb(mp(x[i], y[i] + 1));
    }

    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());

    for (int i = 0; i < n - 1; i++) {
    	int v1 = lower_bound(vec.begin(), vec.end(), mp(x[i], y[i])) - vec.begin();
    	int v2;
    	if (tp[i] == 'h')
    		v2 = lower_bound(vec.begin(), vec.end(), mp(x[i] + 1, y[i])) - vec.begin();
    	else
    		v2 = lower_bound(vec.begin(), vec.end(), mp(x[i], y[i] + 1)) - vec.begin();

    	vertex[v1].pb(v2);
    	vertex[v2].pb(v1);
    }

    for (int i = 0; i < q; i++) {
    	scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
    	for (int j = 0; j < n; j++)
    		used[j] = false;
    	int ans = 0;
    	for (int j = 0; j < n; j++)
    		if (!used[j] && onfield(vec[j].fs, vec[j].sc)) {
    			ans++;
    			dfs(j);
    		}

    	printf("%d\n", ans);
    }

    return 0;
}
