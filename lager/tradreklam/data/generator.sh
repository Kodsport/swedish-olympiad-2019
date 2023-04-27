#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution sl.cpp

compile gen_random.py
compile gen_logstar.py

N=2000
B=30000
MEDN=200
MEDB=500

samplegroup
limits n=15 b=500
sample 1
sample 2

group group1 10
limits n=15 b=$MEDB
tc n1 gen_random n=1 b=$MEDB cost=10 mode=random
tc zero gen_random n=10 b=$MEDB c1=1 cost=10 maxpop=0 mode=line
tc zero2 gen_random n=3 b=1 c1=1 cost=10 maxpop=0 mode=star
tc small-1 gen_random n=15 b=$MEDB mode=random
tc small-2 gen_random n=15 b=$MEDB mode=random shuffle=all
tc small-3 gen_random n=15 b=$MEDB mode=star
tc small-4 gen_random n=15 b=$MEDB mode=line
tc small-5 gen_random n=15 b=$MEDB mode=shallow
tc small-6 gen_random n=15 b=$MEDB mode=deep
tc smaller gen_random n=7 b=$MEDB cost=10 mode=random shuffle=all
tc small-cheap gen_random n=15 b=$MEDB br=40 mode=random

group group2 10
limits n=$N b=$B c1=1
tc zero
tc zero2
tc c1-1 gen_random c1=1 n=$N b=1000 mode=random shuffle=all
tc c1-2 gen_random c1=1 n=$N b=3 mode=random shuffle=all
tc c1-3 gen_random c1=1 n=$N b=1000 mode=star
tc c1-4 gen_random c1=1 n=$MEDN b=$MEDB mode=line
tc c1-5 gen_random c1=1 n=$N b=1000 mode=shallow shuffle=all
tc c1-6 gen_random c1=1 n=$N b=1000 mode=deep
tc c1-7 gen_random c1=1 n=10 b=5 mode=random
tc c1-8 gen_random c1=1 n=$N b=$B mode=random shuffle=all
tc c1-9 gen_random c1=1 n=$N b=$((N - 5)) mode=random
tc c1-10 gen_random c1=1 n=$MEDN b=100 mode=line
tc c1-11 gen_random c1=1 n=$MEDN b=100 mode=random

group group3 10
limits n=$N b=$MEDB line=1
tc n1
tc zero
tc zero2
tc small-4
tc c1-4
tc c1-10
tc line-1 gen_random n=$N b=$MEDB mode=line
tc line-2 gen_random n=$MEDN b=$MEDB mode=line shuffle=all
tc line-3 gen_random n=$MEDN b=$MEDB mode=line shuffle=all
tc line-4 gen_random n=$N b=$MEDB mode=line shuffle=all
tc line-5 gen_random n=$N b=$MEDB mode=line shuffle=all
tc line-6 gen_random n=$N b=$MEDB mode=line shuffle=all
tc line-cheap gen_random n=$N b=$MEDB br=40 mode=line shuffle=all
tc line-exp gen_random n=$N b=$MEDB br=0.02 mode=line shuffle=all

group group4 15
limits n=$MEDN b=$MEDB deg2=1
tc n1
tc zero
tc zero2
tc small-4
tc c1-4
tc c1-10
tc line-2
tc line-3
tc degtwo-1 gen_random n=$MEDN b=$MEDB mode=degtwo
tc degtwo-2 gen_random n=$MEDN b=$MEDB mode=degtwo
tc degtwo-3 gen_random n=$MEDN b=$MEDB mode=degtwo
tc degtwo-4 gen_random n=$MEDN b=$MEDB mode=degtwo
tc degtwo-5 gen_random n=$MEDN b=$MEDB cost=10 br=1 mode=degtwo

group group5 20
limits n=$MEDN b=$MEDB
include_group group1
include_group group4
tc med-1 gen_random n=$MEDN b=$MEDB mode=random
tc med-2 gen_random n=$MEDN b=$MEDB mode=random
tc med-3 gen_random n=$MEDN b=$MEDB mode=random
tc med-4 gen_random n=$MEDN b=$MEDB mode=random shuffle=all
tc med-5 gen_random n=$MEDN b=$MEDB mode=star
tc med-6 gen_random n=$MEDN b=$MEDB mode=line
tc med-7 gen_random n=$MEDN b=$MEDB mode=shallow
tc med-8 gen_random n=$MEDN b=$MEDB mode=deep
tc med-9 gen_random n=$MEDN b=$MEDB cost=10 mode=random

group group6 35
limits n=$N b=$B
include_group group2
include_group group3
include_group group5
include_group sample
tc c1-11
tc large-1 gen_random n=$N b=$B mode=random
tc large-2 gen_random n=$N b=$B mode=random exact=1
tc large-3 gen_random n=$N b=$B mode=random
tc large-4 gen_random n=$N b=$B mode=random shuffle=all
tc large-5 gen_random n=$N b=$B mode=star
tc large-6 gen_random n=$N b=$B mode=line
tc large-7 gen_random n=$N b=$B mode=shallow
tc large-8 gen_random n=$N b=$B mode=deep
tc large-9 gen_random n=$N b=$B cost=10 mode=random
tc large-10 gen_logstar n=$N b=$B
tc large-11 gen_random n=$N b=$B mode=random exact=2
tc large-12 gen_random n=$N b=$B mode=random exact=2 maxpop=200
tc large-13 gen_random n=$N b=$B mode=random br=0.02
