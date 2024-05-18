#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution fe_100.cpp

compile gen_random.py

samplegroup
limits lo=3 hi=10
sample 1
sample 2

group 1_smallN_maxOnly 20
limits lo=3 hi=3
output_validator_flags maxOnly=yes
tc 1-g1 gen_random lo=3 hi=3
tc 2-g1 gen_random lo=3 hi=3
tc 3-g1 gen_random lo=3 hi=3
tc 4-g1 gen_random lo=3 hi=3
tc_manual ../manual-tests/g1.in

group 2_largeN_maxOnly 20
limits lo=5 hi=10
output_validator_flags maxOnly=yes
tc 1-g2 gen_random lo=5 hi=10
tc 2-g2 gen_random lo=5 hi=10
tc 3-g2 gen_random lo=5 hi=10
tc 4-g2 gen_random lo=5 hi=10
tc_manual ../manual-tests/g2.in

group 3_smallN 20
limits lo=3 hi=3
tc 1-g3 gen_random lo=3 hi=3
tc 2-g3 gen_random lo=3 hi=3
tc 3-g3 gen_random lo=3 hi=3
tc 4-g3 gen_random lo=3 hi=3
tc_manual ../manual-tests/g3.in
tc 1

group 4_largeN 40
limits lo=5 hi=10
tc 1-g4 gen_random lo=5 hi=10
tc 2-g4 gen_random lo=5 hi=10
tc 3-g4 gen_random lo=5 hi=10
tc 4-g4 gen_random lo=5 hi=10
tc_manual ../manual-tests/g4.in
tc_manual ../manual-tests/g5.in
tc 2
