#!/usr/bin/env bash

REQUIRE_SAMPLE_REUSE=0
PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution best_contestants.cpp # ../jury_sol.cpp

compile gen_blank.py
compile gen_random.py
compile gen_slope.py
compile gen_invrandom.py
compile gen_invrandom2.py
compile gen_blocks.py

samplegroup
limits t=0
sample 1

testcase() {
	NAME=$(printf "%02d" $1)
	group group$NAME 10
	limits t=$1
	tc "case$NAME" "${@:2}" tc=$1
}

testcase 1 gen_blank n=100 m=100 k=1000
testcase 2 gen_random n=100 m=100 k=500
testcase 3 gen_random n=200 m=1 k=30
testcase 4 gen_random n=1000 m=1000 k=40000
testcase 5 gen_slope n=100 m=100 k=20
testcase 6 gen_slope n=1000 m=1000 k=10000
testcase 7 gen_invrandom n=100 m=100 k=500
testcase 8 gen_invrandom2 n=100 m=100 k=500
testcase 9 gen_invrandom2 n=1000 m=1000 k=40000
testcase 10 gen_blocks n=100 m=100 k=100 blocks=50 # accidentally gets k=9

# Clamp final scores to 100
echo 'grading: custom' >> testdata.yaml
echo 'grading: default' >> secret/testdata.yaml
echo 'grading: default' >> sample/testdata.yaml
