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
const int size = 3010;

int nsum[size][size];
int evs[size][size];
int ehs[size][size];
int w, h, n, q;

int main() {
	scanf("%d%d", &w, &h);
	scanf("%d%d", &n, &q);
	
	for (int i = 0; i < n - 1; i++) {
		char tp;
		int x, y;
		scanf(" %c %d %d", &tp, &x, &y);
		nsum[x][y] = 1;
		if (tp == 'v') {
			nsum[x][y + 1] = 1;
			evs[x][y] = 1;
		} else {
			nsum[x + 1][y] = 1;
			ehs[x][y] = 1;
		}
	}

	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= h; j++) {
			nsum[i][j] = nsum[i][j] + nsum[i - 1][j] + nsum[i][j - 1] - nsum[i - 1][j - 1];
			evs[i][j] = evs[i][j] + evs[i - 1][j] + evs[i][j - 1] - evs[i - 1][j - 1];
			ehs[i][j] = ehs[i][j] + ehs[i - 1][j] + ehs[i][j - 1] - ehs[i - 1][j - 1];
		}

	for (int i = 0; i < q; i++) {
		int xmin, ymin, xmax, ymax;
		scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
		int nodes = nsum[xmax][ymax] - nsum[xmin - 1][ymax] - nsum[xmax][ymin - 1] + nsum[xmin - 1][ymin - 1];
		int vers = evs[xmax][ymax - 1] - evs[xmin - 1][ymax - 1] - evs[xmax][ymin - 1] + evs[xmin - 1][ymin - 1];
		int hors = ehs[xmax - 1][ymax] - ehs[xmin - 1][ymax] - ehs[xmax - 1][ymin - 1] + ehs[xmin - 1][ymin - 1];

		printf("%d\n", nodes - vers - hors);
	}

    return 0;
}
