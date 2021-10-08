#include <cstdio>
#include <memory.h>
#include <unistd.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 1000500;

vector<int> V[4][N];
map<pair<int, int>, int> num;

int to[4][N];

int X[N], Y[N];

void DFS(int v, int dir = -1)
{
    if (dir != -1)
    {
        int layer = (dir & 1) ? Y[v] : X[v];
        int pos = (dir & 1) ? X[v] : Y[v];
        V[dir][layer].push_back(pos);
    }
    for (int d = 0; d < 4; d++)
    {
        if ((d ^ dir) == 2)
            continue;
        if (to[d][v] == -1)
            continue;
        int u = to[d][v];
        DFS(u, d);
    }
}

int vx[] = {1, 0, -1, 0}, vy[] = {0, 1, 0, -1};

char IT[N];
int IX[N], IY[N];

int get_between(const vector<int>& V, int l, int r)
{
    return upper_bound(V.begin(), V.end(), r) - lower_bound(V.begin(), V.end(), l);
}

int RX1[N], RY1[N], RX2[N], RY2[N];

int main()
{
    memset(to, -1, sizeof(to));
    int w, h, n, q;
    ignore = scanf("%d %d %d %d", &w, &h, &n, &q);
    for (int i = 0; i < n - 1; i++)
    {
        char t;
        int x, y;
        ignore = scanf(" %c %d %d", &t, &x, &y);
        IT[i] = t, IX[i] = x, IY[i] = y;
    }
    for (int i = 0; i < q; i++)
        ignore = scanf("%d %d %d %d", &RX1[i], &RY1[i], &RX2[i], &RY2[i]);
    
    for (int i = 0; i < n - 1; i++)
    {
        int t = IT[i];
        int x = IX[i], y = IY[i];
        num[make_pair(x, y)];
        num[make_pair(x + (t == 'h'), y + (t == 'v'))];
    }
    int pt = 0;
    for (map<pair<int, int>, int>::iterator it = num.begin(); it != num.end(); it++)
        it->second = pt, X[pt] = it->first.first, Y[pt] = it->first.second, ++pt;
    for (int i = 0; i < n - 1; i++)
    {
        int x = IX[i], y = IY[i];
        char t = IT[i];
        if (t == 'h')
        {
            int a = num[make_pair(x, y)];
            int b = num[make_pair(x + 1, y)];
            to[0][a] = b;
            to[2][b] = a;
        }
        else
        {
            int a = num[make_pair(x, y)];
            int b = num[make_pair(x, y + 1)];
            to[1][a] = b;
            to[3][b] = a;
        }
    }
    DFS(0);
    for (int d = 0; d < 4; d++)
        for (int i = 0; i < N; i++)
            sort(V[d][i].begin(), V[d][i].end());
    for (int i = 0; i < q; i++)
    {
        int x1 = RX1[i], y1 = RY1[i], x2 = RX2[i], y2 = RY2[i];
        int ans = (X[0] >= x1 && X[0] <= x2) && (Y[0] >= y1 && Y[0] <= y2);
        ans += get_between(V[0][x1], y1, y2);
        ans += get_between(V[2][x2], y1, y2);
        ans += get_between(V[1][y1], x1, x2);
        ans += get_between(V[3][y2], x1, x2);
        printf("%d\n", ans);
    }
    return 0;
}

