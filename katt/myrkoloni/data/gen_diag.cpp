#include "testlib.h"
#include <cstdio>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

int vx[] = {1, 0, -1, 0};
int vy[] = {0, 1, 0, -1};

struct edge
{
    char t;
    int x, y;
    edge(char _t, int _x, int _y)
    {
        t = _t, x = _x, y = _y;
    }
};

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int w = atoi(argv[1]);
    int h = w;
    int n = atoi(argv[2]);
    int q = atoi(argv[3]);
    double prob = atof(argv[4]);
    printf("%d %d\n%d %d\n", w, h, n, q);
    int x0 = w;
    int y0 = h;
    vector<pair<int, int> > Q;
    set<pair<int, int> > used;
    int dn = 0.9 * n;
    vector<edge> E;
    for (int i = 0; i < dn; i++)
    {
        int dir = (rnd.next() < prob) ? 2 : 3;
        x0 += vx[dir], y0 += vy[dir];
        Q.push_back(make_pair(x0, y0));
        E.push_back(edge("hv"[dir == 3], x0, y0));   
    }
    Q.push_back(make_pair(x0, y0));

    used.insert(Q.begin(), Q.end());
    int mnx = x0, mny = y0, mxx = w, mxy = h;
    for (int i = 0; i < n - dn - 1; i++)
    {
        while (true)
        {
            assert(!Q.empty());
            int ind = rnd.next(0, (int)Q.size() - 1);
            int x = Q[ind].first;
            int y = Q[ind].second;
            vector<int> dir;
            for (int v = 0; v < 4; v++)
            {
                int ty = y + vy[v];
                int tx = x + vx[v];
                if (used.find(make_pair(tx, ty)) != used.end())
                    continue;
                if (ty >= 1 && ty <= h && tx >= 1 && tx <= w)
                    dir.push_back(v);
            }
            if (dir.empty())
            {
                swap(Q[ind], Q.back());
                Q.pop_back();
                continue;
            }
            int d = dir[rnd.next(0, (int)dir.size() - 1)];
            int ny = y + vy[d];
            int nx = x + vx[d];
            mnx = min(mnx, nx);
            mny = min(mny, ny);
            mxx = max(mxx, nx);
            mxy = max(mxy, ny);
            used.insert(make_pair(nx, ny));
            Q.push_back(make_pair(nx, ny));
            E.push_back(edge("hv"[d & 1], min(x, nx), min(y, ny)));
            break;
        }
    }
    int real_w = mxx - mnx, real_h = mxy - mny;
    mnx = max(1, (int)(mnx - real_w / 10));
    mxx = min(w, (int)(mxx + real_w / 10));
    mny = max(1, (int)(mny - real_h / 10));
    mxy = min(h, (int)(mxy + real_h / 10));
    shuffle(E.begin(), E.end());
    for (int i = 0; i < (int)E.size(); i++)
        printf("%c %d %d\n", E[i].t, E[i].x, E[i].y);
    for (int i = 0; i < q; i++)
    {
        int x1 = rnd.next(mnx, (3 * mnx + mxx) / 4);
        int x2 = rnd.next((mnx + 3 * mxx) / 4, mxx);
        if (x1 > x2)
            swap(x1, x2);
        int y1 = rnd.next(mny, (3 * mny + mxy) / 4);
        int y2 = rnd.next((mny + 3 * mxy) / 4, mxy);
        if (y1 > y2)
            swap(y1, y2);
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
    return 0;
}
