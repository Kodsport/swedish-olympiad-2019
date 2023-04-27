#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fe_100.cpp

compile gen_random.py

samplegroup
limits easyWin=0
sample 1
sample 2

group group1 42
limits easyWin=1

tc easy-1 gen_random easyWin=1 probA=0.5
tc easy-2 gen_random easyWin=1 probA=0.5
tc easy-3 gen_random easyWin=1 probA=0.5
tc easy-4 gen_random easyWin=1 probA=0.5
tc easy-5 gen_random easyWin=1 probA=0.5
tc easy-6 gen_random easyWin=1 probA=0.5
tc easy-7 gen_random easyWin=1 probA=0.5
tc easy-8 gen_random easyWin=1 probA=0.5
tc most-a gen_random easyWin=1 probA=0.7
tc most-b gen_random easyWin=1 probA=0.3
tc all-a gen_random easyWin=1 probA=1
tc all-b gen_random easyWin=1 probA=0

group group2 58
limits easyWin=0

include_group group1
include_group sample

tc hard-1 gen_random easyWin=0 probA=0.5
tc hard-2 gen_random easyWin=0 probA=0.5
tc hard-3 gen_random easyWin=0 probA=0.5
tc hard-4 gen_random easyWin=0 probA=0.5
tc hard-5 gen_random easyWin=0 probA=0.5
tc hard-6 gen_random easyWin=0 probA=0.5
tc hard-7 gen_random easyWin=0 probA=0.5
tc hard-8 gen_random easyWin=0 probA=0.5
