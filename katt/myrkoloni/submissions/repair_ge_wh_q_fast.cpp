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
const int size = 300 * 1000 + 100;
const int inf = 1000 * 1000 * 1000;

int* nsum[size];
int* evs[size];
int* ehs[size];
int w, h, n, q;

char tp[size];
int x[size], y[size];

int main() {
	scanf("%d%d", &w, &h);
	scanf("%d%d", &n, &q);

	int xbmin = inf;
	int ybmin = inf;
	
	for (int i = 0; i < n - 1; i++) {
		scanf(" %c %d %d", &tp[i], &x[i], &y[i]);
		xbmin = min(xbmin, x[i]);
		ybmin = min(ybmin, y[i]);		
	}

	xbmin--;
	ybmin--;
	w -= xbmin;
	h -= ybmin;
	for (int i = 0; i < n - 1; i++) {
		x[i] -= xbmin;
		y[i] -= ybmin;
	}

	int xbmax = -inf;
	int ybmax = -inf;
	for (int i = 0; i < n - 1; i++) {
		xbmax = max(xbmax, x[i] + 1);
		ybmax = max(ybmax, y[i] + 1);
	}

	w = min(w, xbmax);
	h = min(h, ybmax);
	
	for (int i = 0; i <= w; i++) {
		nsum[i] = new int[h + 1];
		evs[i] = new int[h + 1];
		ehs[i] = new int[h + 1];
	}

	for (int i = 0; i < n - 1; i++) { 
		nsum[x[i]][y[i]] = 1;
		if (tp[i] == 'v') {
			ybmax = max(ybmax, y[i] + 1);
		
			nsum[x[i]][y[i] + 1] = 1;
			evs[x[i]][y[i]] = 1;
		} else {
    		xbmax = max(xbmax, x[i]);

			nsum[x[i] + 1][y[i]] = 1;
			ehs[x[i]][y[i]] = 1;
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
		xmin -= xbmin;
		xmax -= xbmin;
		ymin -= ybmin;
		ymax -= ybmin;
		xmin = max(xmin, 1);
		ymin = max(ymin, 1);
		xmax = min(xmax, w);
		ymax = min(ymax, h);
		if (xmax < min(xmin, 1) || ymax < min(ymin, 1)) {
			printf("0\n");
			continue;
		}

		int nodes = nsum[xmax][ymax] - nsum[xmin - 1][ymax] - nsum[xmax][ymin - 1] + nsum[xmin - 1][ymin - 1];
		int vers = evs[xmax][ymax - 1] - evs[xmin - 1][ymax - 1] - evs[xmax][ymin - 1] + evs[xmin - 1][ymin - 1];
		int hors = ehs[xmax - 1][ymax] - ehs[xmin - 1][ymax] - ehs[xmax - 1][ymin - 1] + ehs[xmin - 1][ymin - 1];

		printf("%d\n", nodes - vers - hors);
	}

    return 0;
}
