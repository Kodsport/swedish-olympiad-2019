#!/bin/bash
REQUIRE_SAMPLE_REUSE=0
. ../../testdata_tools/gen.sh

use_solution fe_100.cpp

compile gen_rand.py

samplegroup
limits sample=1
sample 1
sample 2

group group1 20
limits k_is=1 maxn=15 maxletter=3
tc g1-1 gen_rand n=5 k=1 alpha=3
tc g1-3 gen_rand n=10 k=1 alpha=3
tc g1-4 gen_rand n=12 k=1 alpha=3
tc g1-5 gen_rand n=15 k=1 alpha=3
tc g1-6 gen_rand n=15 k=1 alpha=3
tc g1-7 gen_rand n=15 k=1 alpha=3


group group2 40
limits k_is=2 maxn=30 maxletter=2
tc g2-1 gen_rand n=5 k=2 alpha=2
tc g2-2 gen_rand n=10 k=2 alpha=2
tc g2-3 gen_rand n=20 k=2 alpha=2
tc g2-4 gen_rand n=28 k=2 alpha=2
tc g2-5 gen_rand n=30 k=2 alpha=2
tc g2-6 gen_rand n=30 k=2 alpha=2


group group3 40
limits k_is=2 maxn=30 maxletter=4
tc g3-1 gen_rand n=8 k=2 alpha=4
tc g3-2 gen_rand n=10 k=2 alpha=4
tc g3-3 gen_rand n=22 k=2 alpha=4
tc g3-4 gen_rand n=27 k=2 alpha=4
tc g3-5 gen_rand n=29 k=2 alpha=4
tc g3-6 gen_rand n=30 k=2 alpha=4

