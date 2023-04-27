#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fe_100.cpp

compile gen_random.py

MAXN=100000


samplegroup
limits mode=standard nMax=$MAXN mMax=$MAXN
sample 1
sample 2
sample 3

group group1 12
limits mode=line nMax=$MAXN mMax=$MAXN
tc 1
tc line1 gen_random mode=line n=$MAXN m=$((MAXN - 1))
tc line2 gen_random mode=line n=$MAXN m=$((MAXN / 10))
tc line3 gen_random mode=line n=$MAXN m=$((MAXN * 9 / 10))

group group2 17
limits mode=tree nMax=$MAXN mMax=$MAXN
tc 2
tc tree1 gen_random mode=shallowTree n=10
tc tree2 gen_random mode=shallowTree n=20
tc tree3 gen_random mode=shallowTree n=100
tc tree4 gen_random mode=shallowTree n=$((MAXN / 10))
tc tree5 gen_random mode=shallowTree n=$MAXN
tc tree6 gen_random mode=shallowTree n=$MAXN
tc tree7 gen_random mode=deepTree n=$MAXN
tc tree8 gen_random mode=deepTree n=$MAXN
tc tree9 gen_random mode=deepTree n=$MAXN

group group3 21
limits mode=sorted nMax=$MAXN mMax=$MAXN
tc 3
tc sorted1 gen_random mode=sorted n=$MAXN m=$MAXN
tc sorted2 gen_random mode=sorted n=$((MAXN - 1)) m=$MAXN
tc sorted3 gen_random mode=sorted n=$((MAXN / 10)) m=$MAXN
tc sorted4 gen_random mode=sorted n=1000 m=4000
tc sorted5 gen_random mode=sorted n=$MAXN m=1000

group group4 25
limits mode=standard nMax=10 mMax=10
tc tiny1 gen_random mode=standard n=1 m=0
tc tiny2 gen_random mode=standard n=3 m=3
tc tiny3 gen_random mode=standard n=10 m=7 maxc=5
tc tiny4 gen_random mode=standard n=7 m=10
tc tiny5 gen_random mode=standard n=5 m=10 maxc=5
tc tiny6 gen_random mode=standard n=10 m=10

group group5 25
limits mode=standard nMax=$MAXN mMax=$MAXN
include_group group1
include_group group2
include_group group3
include_group group4
include_group sample
tc full1 gen_random mode=standard n=$MAXN m=$MAXN
tc full2 gen_random mode=standard n=$((MAXN - 1)) m=$MAXN
tc full3 gen_random mode=standard n=$((MAXN / 3)) m=$MAXN
tc full4 gen_random mode=standard n=$((MAXN / 3)) m=$MAXN maxc=10
tc full5 gen_random mode=standard n=$MAXN m=1000
