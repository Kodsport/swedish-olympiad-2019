#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution fe100.cpp

compile gen_rand.py

samplegroup
sample 1
sample 2

group group1 40
tc 1
tc g1-1 gen_rand nail_exists=1
tc g1-2 gen_rand nail_exists=1
tc g1-3 gen_rand nail_exists=1
tc g1-4 gen_rand nail_exists=1
tc g1-5 gen_rand nail_exists=1
tc g1-6 gen_rand nail_exists=1
tc g1-7 gen_rand nail_exists=1
tc g1-8 gen_rand nail_exists=1
tc g1-9 gen_rand nail_exists=1

group group2 60
tc 2
include_group group1
tc g2-1 gen_rand
tc g2-2 gen_rand
tc g2-3 gen_rand
tc g2-4 gen_rand
tc g2-5 gen_rand
tc g2-6 gen_rand
tc g2-7 gen_rand
tc g2-8 gen_rand
tc g2-9 gen_rand


