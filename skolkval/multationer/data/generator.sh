#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution fe100.cpp

compile gen_rand.py

samplegroup
sample 1
sample 2
sample 3
sample 4

group group1 20
limits equal_len=1
tc 1
tc g1-1 gen_rand n_is=4 maxk=1
tc g1-2 gen_rand n_is=5 maxk=1
tc g1-3 gen_rand n_is=8 maxk=1
tc g1-4 gen_rand n_is=9 maxk=1
tc g1-5 gen_rand n_is=10 maxk=1
tc g1-6 gen_rand n_is=10 maxk=1
tc g1-7 gen_rand n_is=10 maxk=1


group group2 40
tc 1
tc 3
tc g2-1 gen_rand n_is=1 maxk=3 same_mult=1
tc g2-2 gen_rand n_is=2 maxk=3 same_mult=1
tc g2-3 gen_rand n_is=3 maxk=3 same_mult=1
tc g2-4 gen_rand n_is=3 maxk=3 same_mult=1
tc g2-5 gen_rand n_is=4 maxk=3 same_mult=1
tc g2-6 gen_rand n_is=5 maxk=3 same_mult=1
tc g2-7 gen_rand n_is=5 maxk=3 same_mult=1
tc g2-8 gen_rand n_is=7 maxk=3 same_mult=1
tc g2-9 gen_rand n_is=10 maxk=1 same_mult=1

group group3 40
tc 2
tc 4
include_group group1
include_group group2
tc g3-1 gen_rand n_is=1 maxk=3
tc g3-2 gen_rand n_is=1 maxk=3
tc g3-3 gen_rand n_is=2 maxk=3
tc g3-4 gen_rand n_is=3 maxk=3
tc g3-5 gen_rand n_is=3 maxk=3
tc g3-6 gen_rand n_is=4 maxk=3
tc g3-7 gen_rand n_is=5 maxk=3
tc g3-8 gen_rand n_is=7 maxk=3
tc g3-9 gen_rand n_is=10 maxk=1


