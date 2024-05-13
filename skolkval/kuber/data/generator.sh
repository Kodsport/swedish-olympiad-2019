#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution fe.py

compile gen_rand.py

samplegroup
sample 1
sample 2

group group1 20
limits n_is=10
tc_manual ../manual/tc1.in


group group2 80
tc 1
tc 2
include_group group1
tc g2-1 gen_rand maxn=50
tc g2-2 gen_rand maxn=80
tc g2-3 gen_rand maxn=100
tc g2-4 gen_rand maxn=100
tc g2-5 gen_rand maxn=100
tc g2-6 gen_rand maxn=100
tc g2-7 gen_rand maxn=100
tc g2-8 gen_rand maxn=100



