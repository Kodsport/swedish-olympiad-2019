#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fe100.cpp

compile gen_random.py

samplegroup
sample 1
sample 2

group group1 40
tc 2
tc g1-1 gen_random ans=E
tc g1-2 gen_random ans=C
tc g1-3 gen_random ans=A
tc g1-4 gen_random ans=E
tc g1-5 gen_random ans=C
tc g1-6 gen_random ans=A
tc g1-7 gen_random ans=E
tc g1-8 gen_random ans=C
tc g1-9 gen_random ans=A

group group2 60
include_group group1
tc 1
tc g2-1 gen_random ans=D
tc g2-2 gen_random ans=B
tc g2-3 gen_random ans=D
tc g2-4 gen_random ans=B
tc g2-5 gen_random ans=D
tc g2-6 gen_random ans=B
