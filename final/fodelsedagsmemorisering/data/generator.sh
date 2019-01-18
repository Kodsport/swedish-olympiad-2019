#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution kl.cpp
compile gen_random.py

MAXN=2000
MAXC=100000

samplegroup
limits nMax=$MAXN cMax=$MAXC
sample 1
sample 2

group group1 30
limits nMax=100 cMax=$MAXC
tc small_random0 gen_random N=1 maxC=10000
tc small_random1 gen_random N=10 maxC=10
tc small_random2 gen_random N=20 maxC=20
tc small_random3 gen_random N=30 maxC=30
tc small_random4 gen_random N=40 maxC=40
tc small_random5 gen_random N=50 maxC=50
tc small_random6 gen_random N=100 maxC=100
tc small_random7 gen_random N=100 maxC=1000
tc small_random8 gen_random N=100 maxC=10000
tc small_random9 gen_random N=100 maxC=100000
tc small_random10 gen_random N=100 maxC=100000
tc small_same1 gen_random N=100 maxC=10000 same=99
tc small_same2 gen_random N=100 maxC=10000 same=100

group group2 70
limits nMax=$MAXN cMax=$MAXC
include_group group1
tc large_random1 gen_random N=300 maxC=100000
tc large_random2 gen_random N=500 maxC=100000
tc large_random3 gen_random N=750 maxC=100000
tc large_random4 gen_random N=1000 maxC=100000
tc large_random5 gen_random N=1500 maxC=100000
tc large_random6 gen_random N=2000 maxC=100000
tc large_random7 gen_random N=2000 maxC=100000
tc large_random8 gen_random N=2000 maxC=100000
tc large_random9 gen_random N=2000 maxC=100000
tc large_random10 gen_random N=2000 maxC=100000
tc large_same gen_random N=2000 maxC=100000 same=1999
