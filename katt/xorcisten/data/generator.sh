#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution ng_100.cpp opt

samplegroup
limits nq=500 aexp=30
sample 1

# Unfortunately, while the jury archive does provide the generators for all
# test cases, it does not *not* provide the parameters to them... So, manually
# include everything instead.

if [ ! -d ../manual-tests ]; then
	cd ../
	tar xvjf manual-tests.tar.bz2
	cd data/
fi

group group1 13
limits nq=500 aexp=9
tc 1
for A in {02..35}; do
	tc_manual ../manual-tests/$A
done

group group2 37
limits nq=1000 aexp=30
include_group group1
for A in {36..55}; do
	tc_manual ../manual-tests/$A
done

group group3 38
limits nq=1e5 aexp=30
include_group group2
for A in {56..81}; do
	tc_manual ../manual-tests/$A
done

group group4 12
limits nq=1e6 aexp=30
include_group group3
for A in {82..97}; do
	tc_manual ../manual-tests/$A
done
