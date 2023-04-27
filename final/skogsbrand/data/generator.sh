#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution ng_100.cpp

compile gen_random.py
compile gen_chambers.py
compile gen_maze.py
compile gen_line.py

MAXN=100
MAXM=100
MAXX=99999
MAXT=1000000000

samplegroup
limits nMax=$MAXN mMax=$MAXM TMax=$MAXT xMax=$MAXX
sample 1
sample 2
sample 3
sample 4

group group1 5
limits nMax=1 mMax=0 TMax=$MAXT xMax=$MAXX
tc diamond1 gen_random n=1 m=0 T=10
tc diamond2 gen_random n=1 m=0 T=0
tc diamond3 gen_random n=1 m=0 T=1
tc diamond4 gen_random n=1 m=0 T=1000 maxx=$MAXX
tc diamond5 gen_random n=1 m=0 T=$MAXT maxx=$MAXX
tc diamond6 gen_random n=1 m=0 T=$((MAXT/2)) maxx=$MAXX

group group2 9
limits nMax=$MAXN mMax=0 TMax=100 xMax=99
tc smallbfs1 gen_random n=10 m=0 T=3 maxx=20
tc smallbfs2 gen_random n=25 m=0 T=0 maxx=5
tc smallbfs3 gen_random n=1 m=0 T=100 maxx=99
tc smallbfs4 gen_random n=$MAXN m=0 T=100 maxx=99
tc smallbfs5 gen_random n=$MAXN m=0 T=99 maxx=99
tc smallbfs6 gen_random n=$MAXN m=0 T=100 maxx=88
tc smallbfs7 gen_random n=$MAXN m=0 T=100 maxx=77
tc smallbfs8 gen_random n=$MAXN m=0 T=100 maxx=30
tc smallbfs9 gen_random n=$MAXN m=0 T=100 maxx=13
tc smallbfs10 gen_line n=$MAXN m=0 T=100 maxx=99 dx=1 dy=1

group group3 10
limits nMax=$MAXN mMax=$MAXM TMax=400 xMax=99
include_group group2
tc 1
tc 3
tc bigbfs1 gen_random n=$MAXN m=$MAXM T=400 maxx=99
tc bigbfs2 gen_random n=$MAXN m=$MAXM T=400 maxx=99
tc bigbfs3 gen_random n=$MAXN m=$MAXM T=400 maxx=99
tc bigbfs4 gen_random n=$MAXN m=$MAXM T=400 maxx=66
tc bigbfs5 gen_random n=$MAXN m=$MAXM T=400 maxx=22
tc bigbfs6 gen_chambers n=$MAXN m=$MAXM T=400 maxx=40
tc bigbfs7 gen_chambers n=$MAXN m=$MAXM T=400 maxx=99 small_only=1
tc bigbfs8 gen_chambers n=$MAXN m=$MAXM T=400 maxx=99 closed=1 small_only=1
tc bigbfs9 gen_maze n=$MAXN m=$MAXM T=101 maxx=99
tc bigbfs10 gen_maze n=$MAXN m=$MAXM T=400 maxx=99 closed=1
tc bigbfs11 gen_line n=48 m=48 T=400 maxx=99 dx=1 dy=1
tc bigbfs12 gen_line n=3 m=96 T=400 maxx=99

group group4 11
limits nMax=$MAXN mMax=0 TMax=$MAXT xMax=99
include_group group2
tc smallmzero1 gen_random n=$MAXN m=0 T=10000 maxx=99
tc smallmzero2 gen_random n=$MAXN m=0 T=$MAXT maxx=99
tc smallmzero3 gen_random n=1 m=0 T=$MAXT maxx=99
tc smallmzero4 gen_random n=$MAXN m=0 T=$MAXT maxx=99
tc smallmzero5 gen_random n=$MAXN m=0 T=$MAXT maxx=99
tc smallmzero6 gen_random n=$MAXN m=0 T=$MAXT maxx=13

group group5 21
limits nMax=$MAXN mMax=$MAXM TMax=$MAXT xMax=99
include_group group3
include_group group4
tc 2
tc 4
tc smallx1 gen_random n=$MAXN m=3 T=$MAXT maxx=30
tc smallx2 gen_random n=$MAXN m=33 T=$MAXT maxx=22
tc smallx3 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=22
tc smallx4 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=55
tc smallx5 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=99
tc smallx6 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=99
tc smallx7 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=99
tc smallx8 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=99
tc smallx9 gen_chambers n=$MAXN m=$MAXM T=$MAXT maxx=99
tc smallx10 gen_chambers n=$MAXN m=$MAXM T=$MAXT maxx=99 small_only=1 closed=1
tc smallx11 gen_chambers n=$MAXN m=$MAXM T=$MAXT maxx=99 small_only=1
tc smallx12 gen_maze n=$MAXN m=$MAXM T=$MAXT maxx=99
tc smallx13 gen_maze n=$MAXN m=$MAXM T=$MAXT maxx=99 extra_fire=1
tc smallx14 gen_maze n=$MAXN m=$MAXM T=$MAXT maxx=99 extra_fire=1 closed=1
tc smallx15 gen_line n=48 m=48 T=$MAXT maxx=99 dx=1 dy=1

group group6 15
limits nMax=$MAXN mMax=0 TMax=$MAXT xMax=$MAXX
include_group group1
include_group group4
tc bigmzero1 gen_random n=$MAXN m=0 T=$MAXT maxx=$MAXX
tc bigmzero2 gen_random n=$MAXN m=0 T=$MAXT maxx=$MAXX
tc bigmzero3 gen_random n=$MAXN m=0 T=$MAXT maxx=$MAXX
tc bigmzero4 gen_random n=2 m=0 T=$MAXT maxx=$MAXX
tc bigmzero5 gen_random n=33 m=0 T=$MAXT maxx=$MAXX
tc bigmzero6 gen_random n=$MAXN m=0 T=$MAXT maxx=$MAXX
tc bigmzero7 gen_random n=$MAXN m=0 T=200 maxx=$MAXX
tc bigmzero8 gen_random n=$MAXN m=0 T=2000 maxx=$MAXX
tc bigmzero9 gen_random n=$MAXN m=0 T=20000 maxx=$MAXX
tc bigmzero10 gen_random n=33 m=0 T=60000 maxx=$MAXX
tc bigmzero11 gen_line n=$MAXN m=0 T=9000 maxx=$MAXX
tc bigmzero12 gen_line n=$MAXN m=0 T=$MAXT maxx=$MAXX dx=1 dy=1
tc bigmzero13 gen_random n=$MAXN m=0 T=0 maxx=$MAXX

group group7 29
limits nMax=$MAXN mMax=$MAXM TMax=$MAXT xMax=$MAXX
include_group group5
include_group group6
tc full1 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX
tc full2 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX
tc full3 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX
tc full4 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX
tc full5 gen_random n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX
tc full6 gen_random n=$MAXN m=$MAXM T=100000 maxx=$MAXX
tc full7 gen_chambers n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX
tc full8 gen_chambers n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX
tc full9 gen_chambers n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX small_only=1
tc full10 gen_chambers n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX small_only=1 closed=1
tc full11 gen_maze n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX
tc full12 gen_line n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX dx=1 dy=1
tc full13 gen_line n=$MAXN m=$MAXM T=$MAXT maxx=$MAXX
tc full14 gen_maze n=$MAXN m=$MAXM T=11111 maxx=$MAXX closed=1 extra_fire=1
