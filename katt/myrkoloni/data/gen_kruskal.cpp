#include "testlib.h"
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
const int limit = 1000 * 1000 * 1000;

vector <int> par;

int w, h, n, q;

int getnumber(int x, int y) {
    return h * x + y;
}

int getx(int num) {
	return num / h;
}

int gety(int num) {
	return num % h;
}

int getpar(int v) {
	if (par[v] != v)
		par[v] = getpar(par[v]);
	return par[v];
}

int main(int argc, char ** argv) {
    registerGen(argc, argv, 1);
    
    if (argc < 4) {
    	cerr << "Usage: w, h, q" << endl;

    	return 1;
    }

    w = atoi(argv[1]);
    h = atoi(argv[2]);
    q = atoi(argv[3]);

    assert(w * 1ll * h <= limit);
    int n = w * h;
    
    par.resize(n);
    for (int i = 0; i < n; i++)
    	par[i] = i;
    
    printf("%d %d\n", w, h);
    printf("%d %d\n", n, q);

    vector <pair <int, int> > edges;
    for (int i = 0; i < w - 1; i++)
    	for (int j = 0; j < h; j++)
    		edges.pb(mp(getnumber(i, j), getnumber(i + 1, j)));
    for (int i = 0; i < w; i++)
    	for (int j = 0; j < h - 1; j++)
    		edges.pb(mp(getnumber(i, j), getnumber(i, j + 1)));

    shuffle(edges.begin(), edges.end());

    for (int i = 0; i < (int) edges.size(); i++) {
    	int v = getpar(edges[i].fs);
    	int u = getpar(edges[i].sc);

    	if (v != u) {
    		int xc1 = getx(edges[i].fs);
    		int yc1 = gety(edges[i].fs);
    		int xc2 = getx(edges[i].sc);

    		if (xc1 == xc2)
    			printf("v ");
    		else
    			printf("h ");

    		printf("%d %d\n", xc1 + 1, yc1 + 1);

    		par[v] = u;
    	}
    }

    for (int i = 0; i < q; i++) {
    	int xmin = rnd.next(1, w);
    	int xmax = rnd.next(1, w);
    	if (xmin > xmax)
    		swap(xmin, xmax);

        int ymin = rnd.next(1, h);
        int ymax = rnd.next(1, h);
        if (ymin > ymax)
        	swap(ymin, ymax);

        printf("%d %d %d %d\n", xmin, ymin, xmax, ymax);
    }

    return 0;
}