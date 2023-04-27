#include "validator.h"

void run(){
    int nMax = Arg("nMax");
    int mMax = Arg("mMax");
    int kMax = Arg("kMax");
    assert(kMax <= nMax);

    int piMax = Arg("piMax");
    int days = Arg("days");

    int simpleG = Arg("simpleG", 0);

    int N = Int(1,nMax);
    Space();
    int M = Int(1,mMax);
    Space();
    int K = Int(0,min(N,kMax));
    Endl();

    vector<int> d = SpacedInts(N, 1, days);
    vector<int> g = SpacedInts(M, 1, days);
    vector<int> p = SpacedInts(M, 2, piMax);
    vector<int> r = SpacedInts(K, 1, days);

    for(int i = 0; i < N-1; i++) assert(d[i] < d[i+1]);
    for(int i = 0; i < M-1; i++) assert(g[i] < g[i+1]);
    for(int i = 0; i < M-1; i++) assert(p[i] < p[i+1]);
    for(int i = 0; i < M; i++) assert(p[i]%2==0);
    for(int i = 0; i < K-1; i++) assert(r[i] < r[i+1]);

    if (simpleG) {
        for(int i = 0; i < M; i++) assert(g[i] == i+1);
    }
}
