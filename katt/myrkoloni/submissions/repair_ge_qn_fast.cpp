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
const int size = 500 * 1000;

int w, h;
int n, q;
int xedge1[size], yedge1[size];
int xedge2[size], yedge2[size];
char tpedge[size];
int xc[size], yc[size];

bool onfield(int xc, int yc, int xmin, int ymin, int xmax, int ymax) {
	return (xc >= xmin && yc >= ymin && xc <= xmax && yc <= ymax);
} 

int main() {
    scanf("%d%d", &w, &h);
    scanf("%d%d", &n, &q);

    set <pair <int, int> > pts;

    for (int i = 0; i < n - 1; i++) {
    	scanf(" %c %d%d", &tpedge[i], &xedge1[i], &yedge1[i]);

		xedge2[i] = xedge1[i];
		yedge2[i] = yedge1[i];
		if (tpedge[i] == 'v')
			yedge2[i]++;
		if (tpedge[i] == 'h')
			xedge2[i]++;
		
		pts.insert(mp(xedge2[i], yedge2[i]));
		pts.insert(mp(xedge1[i], yedge1[i]));
    }

    int cnt = 0;
    for (set <pair <int, int> >::iterator it = pts.begin(); it != pts.end(); ++it) {
    	xc[cnt] = it->fs;
    	yc[cnt] = it->sc;
    	cnt++;
    }

    for (int i = 0; i < q; i++) {
    	int xmin, xmax, ymin, ymax;
    	scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);

    	int ans = 0;
    	for (int j = 0; j < n; j++)
    		ans += onfield(xc[j], yc[j], xmin, ymin, xmax, ymax);
    	for (int j = 0; j < n - 1; j++)
    		ans -= onfield(xedge1[j], yedge1[j], xmin, ymin, xmax, ymax) && onfield(xedge2[j], yedge2[j], xmin, ymin, xmax, ymax);

    	printf("%d\n", ans);
    }

    return 0;
}
