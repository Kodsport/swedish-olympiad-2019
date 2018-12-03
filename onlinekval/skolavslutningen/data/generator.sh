#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution erik.cpp

compile gen.py

MAXN=700

samplegroup
limits nMax=5 mMax=5
sample 1
sample 2
sample 3
sample 4

group group1 15
limits nMax=5 mMax=5
tc bf-1 gen k=1 n=2 m=2
tc bf-2 gen k=4 n=3 m=5
tc bf-3 gen k=4 n=5 m=3
tc bf-4 gen k=3 n=1 m=5

group group2 15
limits nMax=$MAXN mMax=$MAXN k=2
tc k2-1 gen k=2 n=2 m=2
tc k2-2 gen k=2 n=3 m=5
tc k2-3 gen k=2 n=1 m=8
tc k2-4 gen k=2 n=20 m=15
tc k2-5 gen k=2 n=200 m=60
tc k2-6 gen k=2 n=$MAXN m=$MAXN
tc k2-7 gen k=2 n=15 m=$MAXN
tc k2-8 gen k=2 n=$MAXN m=50

group group3 35
limits nMax=50 mMax=50
tc nm50-1 gen k=1 n=1 m=1
tc nm50-2 gen k=10 n=1 m=15
tc nm50-3 gen k=1 n=25 m=15
tc nm50-4 gen k=26 n=50 m=50
tc nm50-5 gen k=20 n=25 m=15
tc nm50-6 gen k=8 n=40 m=5
tc nm50-7 gen k=18 n=35 m=45
tc nm50-8 gen k=15 n=40 m=17

group group4 35
limits nMax=$MAXN mMax=$MAXN
tc full-1 gen k=4 n=$((MAXN * 56 / 100)) m=$((MAXN * 20 / 100))
tc full-2 gen k=26 n=$MAXN m=$MAXN
tc full-3 gen k=20 n=$((MAXN * 45 / 100)) m=$((MAXN * 22 / 100))
tc full-4 gen k=10 n=3 m=$MAXN
tc full-5 gen k=17 n=$((MAXN * 9 / 10 - 2)) m=20
tc full-6 gen k=15 n=$((MAXN * 75 / 100)) m=$((MAXN * 9 / 10))

