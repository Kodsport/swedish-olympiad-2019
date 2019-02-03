#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution ng_100.cpp

compile gen_random.py
compile gen_line.py
compile gen_star.py
compile gen_expstar.py
compile gen_breakearly.py

MAXN=200000

samplegroup
limits nMax=$MAXN mMax=$MAXN
sample 1
sample 2
sample 3
sample 4

group group1 5
limits nMax=$MAXN mMax=$MAXN mode=line
tc line1 gen_line n=10 k=2
tc line2 gen_line n=10 k=1
tc line3 gen_line n=$MAXN k=10000
tc line4 gen_line n=$MAXN k=$MAXN
tc line5 gen_line n=$MAXN k=2
tc line6 gen_line n=$MAXN k=1
tc line7 gen_line n=$MAXN k=100000 maxw=1
tc line8 gen_line n=$MAXN k=100000
tc line9 gen_line n=2 k=2

group group2 16
limits nMax=$MAXN mMax=$MAXN mode=tree
include_group group1
tc tree1 gen_random n=100 m=99 k=2
tc tree2 gen_random n=100 m=99 k=10 mode=valid
tc tree3 gen_random n=100 m=99 k=10 width=2 mode=valid
tc tree4 gen_random n=$MAXN m=$((MAXN-1)) k=2
tc tree5 gen_random n=$MAXN m=$((MAXN-1)) k=3 mode=valid
tc tree6 gen_random n=$MAXN m=$((MAXN-1)) k=7 mode=valid
tc tree7 gen_random n=$MAXN m=$((MAXN-1)) k=12 mode=valid
tc tree8 gen_random n=$MAXN m=$((MAXN-1)) k=12 mode=almost
tc tree9 gen_random n=$MAXN m=$((MAXN-1)) k=10000 width=3 mode=valid
tc tree10 gen_random n=$MAXN m=$((MAXN-1)) k=50000 width=3 mode=valid
tc tree11 gen_random n=$MAXN m=$((MAXN-1)) k=50000 width=3 mode=almost
tc tree12 gen_random n=$MAXN m=$((MAXN-1)) k=100000 width=2 mode=valid
tc tree13 gen_star n=$MAXN m=$((MAXN-1)) k=$((MAXN/2))

group group3 15
limits nMax=100 mMax=100
tc small1 gen_random n=3 m=3 k=2
tc small2 gen_random n=2 m=1 k=2
tc small3 gen_random n=100 m=100 k=1
tc small4 gen_random n=100 m=100 k=2
tc small5 gen_random n=100 m=100 k=10 mode=valid
tc small6 gen_random n=100 m=100 k=10 mode=almost
tc small7 gen_random n=100 m=100 k=50 width=3 mode=valid
tc small8 gen_random n=50 m=100 k=20 width=3 mode=valid
tc small9 gen_random n=100 m=99 k=50 width=1
tc small10 gen_random n=60 m=100 k=50
tc small11 gen_breakearly n=60

group group4 17
limits nMax=1000 mMax=1000
include_group group3
tc medium1 gen_random n=1000 m=1000 k=2
tc medium2 gen_random n=1000 m=1000 k=100 mode=valid
tc medium3 gen_random n=1000 m=1000 k=100 mode=almost
tc medium4 gen_random n=1000 m=1000 k=500
tc medium5 gen_random n=200 m=1000 k=30 width=5 mode=valid
tc medium6 gen_random n=800 m=1000 k=300 width=2 mode=valid
tc medium7 gen_random n=1000 m=1000 k=3 width=2 mode=valid
tc medium8 gen_random n=900 m=1000 k=100 mode=valid
tc medium9 gen_breakearly n=600

group group5 15
limits nMax=100000 mMax=100000 kMax=5
tc ksmall1 gen_random n=100000 m=100000 k=5 mode=valid
tc ksmall2 gen_random n=70000 m=100000 k=5 mode=valid
tc ksmall3 gen_random n=50000 m=100000 k=5 mode=valid
tc ksmall4 gen_random n=50000 m=100000 k=5 width=4 mode=valid
tc ksmall5 gen_random n=50000 m=100000 k=5 width=2 mode=valid
tc ksmall6 gen_random n=85000 m=100000 k=2 mode=valid
tc ksmall7 gen_random n=50 m=100 k=1
tc ksmall8 gen_random n=50000 m=100000 k=5 width=4 mode=almost
tc ksmall9 gen_random n=10 m=30 k=3 mode=valid
tc ksmall10 gen_line n=100000 k=3
tc ksmall11 gen_random n=30000 m=100000 k=5

group group6 32
limits nMax=$MAXN mMax=$MAXN
include_group group2
include_group group4
include_group group5
tc large1 gen_random n=$MAXN m=$MAXN k=$MAXN
tc large2 gen_random n=$MAXN m=$MAXN k=100000
tc large3 gen_random n=$MAXN m=$MAXN k=1000 mode=valid
tc large4 gen_random n=$((MAXN/2)) m=$MAXN k=1000 mode=valid
tc large5 gen_random n=$((MAXN/2)) m=$MAXN k=90 mode=valid
tc large6 gen_random n=$((MAXN/2)) m=$MAXN k=10000 mode=almost
tc large7 gen_random n=$((MAXN/2)) m=$MAXN k=10000 width=10 mode=valid
tc large8 gen_random n=$((MAXN/2)) m=$MAXN k=10000 width=5 mode=valid
tc large9 gen_random n=$((MAXN/2)) m=$MAXN k=200 width=5 mode=valid
tc large10 gen_random n=$((MAXN/2)) m=$MAXN k=30000 width=3 mode=valid
tc large11 gen_random n=$((MAXN*2/3)) m=$MAXN k=50000 width=2 mode=valid
tc large12 gen_star n=$MAXN m=$MAXN k=$((MAXN-44))
tc large13 gen_expstar n=$MAXN
tc large14 gen_breakearly n=$(($MAXN*3/5))
tc large15 gen_random n=$((MAXN-44)) m=$MAXN k=30000 width=3 mode=valid
tc large16 gen_random n=$((MAXN-44)) m=$MAXN k=30000 width=2 mode=valid
