#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 3050;

bool E[N][N][4];
int vx[] = {1, 0, -1, 0}, vy[] = {0, 1, 0, -1};

bool was[N][N];

void DFS(int y, int x, int y1, int x1, int y2, int x2)
{
    was[y][x] = true;
    for (int v = 0; v < 4; v++)
    {
        int ty = y + vy[v];
        int tx = x + vx[v];
        if (!E[y][x][v])
            continue;
        if (was[ty][tx])
            continue;
        if (y < y1 || y > y2 || x < x1 || x > x2)
            continue;
        DFS(ty, tx, y1, x1, y2, x2);
    }
}

int main()
{
    int w, h, n, q;
    scanf("%d %d %d %d", &w, &h, &n, &q);
    for (int i = 0; i < n - 1; i++)
    {
        char t;
        int x, y;
        scanf(" %c %d %d", &t, &x, &y);
        ++x, ++y;
        if (t == 'h')
            E[y][x][0] = E[y][x + 1][2] = 1;
        if (t == 'v')
            E[y][x][1] = E[y + 1][x][3] = 1;
    }
    for (int i = 0; i < q; i++)
    {
        memset(was, 0, sizeof(was));
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        ++x1, ++y1, ++x2, ++y2;
        int ans = 0;
        for (int x = x1; x <= x2; x++)
            for (int y = y1; y <= y2; y++)
                if (!was[y][x] && *max_element(E[y][x], E[y][x] + 4) == 1)
                    ++ans, DFS(y, x, y1, x1, y2, x2);
        printf("%d\n", ans);
    }
    return 0;
}
