#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution ng_100.cpp

compile gen_random.py
compile gen_triangle.py
compile gen_line.py
compile gen_cluster.py

MAXN=2000
MAXX=1000000000

samplegroup
limits nMax=$MAXN xMax=$MAXX
sample 1
sample 2
sample 3

group group1 10
limits nMax=3 xMax=$MAXX
tc triangle1 gen_random n=2
tc triangle2 gen_random n=3
tc triangle3 gen_random n=3
tc triangle4 gen_random n=3
tc triangle5 gen_triangle x1=0 y1=0 x2=$MAXX y2=0 x3=0 y3=$MAXX
tc triangle6 gen_triangle x1=0 y1=0 x2=100 y2=100 x3=$MAXX y3=$MAXX
tc triangle7 gen_triangle x1=0 y1=0 x2=$MAXX y2=$MAXX x3=$((MAXX-1)) y3=$MAXX

group group2 10
limits nMax=5 xMax=$MAXX
include_group group1
tc small1 gen_random n=4
tc small2 gen_random n=4
tc small3 gen_random n=5
tc small4 gen_random n=5
tc small5 gen_random n=5
tc small6 gen_line n=5 dx=1 dy=1
tc small7 gen_cluster n=5 isolated=1

group group3 30
limits nMax=200 xMax=$MAXX
include_group group2
tc medium1 gen_random n=10
tc medium2 gen_random n=50
tc medium3 gen_random n=200
tc medium4 gen_random n=200
tc medium5 gen_random n=200
tc medium6 gen_random n=200
tc medium7 gen_random n=200
tc medium8 gen_line n=200 dx=1 dy=0
tc medium9 gen_cluster n=200 isolated=0
tc medium10 gen_cluster n=200 isolated=10
tc medium11 gen_cluster n=199 isolated=100

group group4 50
limits nMax=$MAXN xMax=$MAXX
include_group group3
tc large1 gen_random n=400
tc large2 gen_random n=800
tc large3 gen_random n=1600
tc large4 gen_random n=$MAXN
tc large5 gen_random n=$MAXN
tc large6 gen_random n=$MAXN
tc large7 gen_random n=$MAXN
tc large8 gen_random n=$MAXN
tc large9 gen_line n=$MAXN dx=1234 dy=711
tc large10 gen_cluster n=$MAXN isolated=0
tc large11 gen_cluster n=$MAXN isolated=1
tc large12 gen_cluster n=$MAXN isolated=300
