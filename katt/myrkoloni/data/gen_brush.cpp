#include "testlib.h"
#include <cstdio>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int w = atoi(argv[1]);
    int h = atoi(argv[2]);
    int q = atoi(argv[3]);
    int t = atoi(argv[4]);
    printf("%d %d\n%d %d\n", w, h, w * h, q);
    if (t == 1)
    {
        for (int i = 1; i < h; i++)
            printf("v %d %d\n", 1, i);
        for (int i = 1; i <= h; i++)
            for (int j = 1; j < w; j++)
                printf("h %d %d\n", j, i);
    }
    else
    {
        for (int i = 1; i < w; i++)
            printf("h %d %d\n", i, 1);
        for (int i = 1; i <= w; i++)
            for (int j = 1; j < h; j++)
                printf("v %d %d\n", i, j);
    }
    for (int i = 0; i < q; i++)
    {
       int x1 = rnd.next(2, w / 3 + 1), x2 = rnd.next(2 * w / 3, w);
       int y1 = rnd.next(2, h / 3 + 1), y2 = rnd.next(2 * h / 3, h);
       printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
}
