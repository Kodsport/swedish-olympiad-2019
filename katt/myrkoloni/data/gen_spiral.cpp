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
const int px[4] = {1, 0, -1, 0};
const int py[4] = {0, 1, 0, -1};

int main(int argc, char ** argv) {
	registerGen(argc, argv, 1);
	
	if (argc < 9) {
		cerr << "Usage: w, h, n, q, step, direction (1 or -1), xstart, ystart" << endl;

		return 1;
	}

	int w = atoi(argv[1]);
	int h = atoi(argv[2]);
	int n = atoi(argv[3]);
	int q = atoi(argv[4]);
	int step = atoi(argv[5]);
	int dir = atoi(argv[6]);
	int curx = atoi(argv[7]);
	int cury = atoi(argv[8]);

	int len = 1;
	int stdir = rnd.next(0, 3);
	vector <pair <char, pair <int, int> > > edges;
	int hn = n - 1;
	while (hn > 0) {
		for (int i = 0; i < len && hn > 0; i++) {
			int nx = curx + px[stdir];
			int ny = cury + py[stdir];
			if (nx != curx) {
				edges.pb(mp('h', mp(min(nx, curx), cury)));
			} else {
				edges.pb(mp('v', mp(curx, min(ny, cury))));
			}

			curx = nx;
			cury = ny;
			hn--;
		}

		stdir = (stdir + 4 + dir) % 4;
		len += step;
	}

	shuffle(edges.begin(), edges.end());

	printf("%d %d\n", w, h);
	printf("%d %d\n", n, q);

	assert((int) edges.size() == n - 1);
	for (int i = 0; i < n - 1; i++)
		printf("%c %d %d\n", edges[i].fs, edges[i].sc.fs, edges[i].sc.sc);

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