#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution sl.cpp

compile gen_random_or_roughlyLinearPrices.py

MAXN=100000
MAXM=10
MAXK=$MAXN
PIMAX=10000
DAYS=500000

samplegroup
limits nMax=$MAXN mMax=$MAXM kMax=$MAXK piMax=$PIMAX days=$DAYS
sample 1
sample 2
sample 3
sample 4


group group1 15
limits nMax=4 mMax=4 kMax=4 days=7 piMax=$PIMAX
#tc name input_generator inputs_to_generator
tc small0rand gen_random_or_roughlyLinearPrices N=4 M=2 K=3 piMax=$PIMAX days=7 mode=random
tc small1rand gen_random_or_roughlyLinearPrices N=4 M=4 K=3 piMax=$PIMAX days=7 mode=random
tc small2rand gen_random_or_roughlyLinearPrices N=4 M=4 K=4 piMax=$PIMAX days=7 mode=random
tc small3rand gen_random_or_roughlyLinearPrices N=4 M=2 K=4 piMax=$PIMAX days=7 mode=random
tc small4rand gen_random_or_roughlyLinearPrices N=4 M=3 K=1 piMax=$PIMAX days=7 mode=random
tc small5rand gen_random_or_roughlyLinearPrices N=4 M=3 K=2 piMax=$PIMAX days=7 mode=random
tc small6rand gen_random_or_roughlyLinearPrices N=4 M=3 K=0 piMax=$PIMAX days=7 mode=random
tc small7rand gen_random_or_roughlyLinearPrices N=4 M=4 K=2 piMax=$PIMAX days=7 mode=random
tc small0semirand gen_random_or_roughlyLinearPrices N=4 M=2 K=3 piMax=$PIMAX days=7 mode=rlinear
tc small1semirand gen_random_or_roughlyLinearPrices N=4 M=4 K=3 piMax=$PIMAX days=7 mode=rlinear
tc small2semirand gen_random_or_roughlyLinearPrices N=4 M=4 K=4 piMax=$PIMAX days=7 mode=rlinear
tc small3semirand gen_random_or_roughlyLinearPrices N=4 M=2 K=4 piMax=$PIMAX days=7 mode=rlinear
tc small4semirand gen_random_or_roughlyLinearPrices N=4 M=3 K=1 piMax=$PIMAX days=7 mode=rlinear
tc small5semirand gen_random_or_roughlyLinearPrices N=4 M=3 K=2 piMax=$PIMAX days=7 mode=rlinear
tc small6semirand gen_random_or_roughlyLinearPrices N=4 M=3 K=0 piMax=$PIMAX days=7 mode=rlinear
tc small7semirand gen_random_or_roughlyLinearPrices N=4 M=4 K=2 piMax=$PIMAX days=7 mode=rlinear
tc smallBreakNh gen_random_or_roughlyLinearPrices N=4 M=4 K=4 piMax=100000 days=7 mode=rlinear seed=39


group group2 9
limits nMax=300 mMax=$MAXM kMax=300 piMax=$PIMAX days=1000
#tc name input_generator inputs_to_generator
include_group group1
tc med0randsmalldi gen_random_or_roughlyLinearPrices N=300 M=$MAXM K=210 piMax=$PIMAX days=1000 mode=random
tc med1randsmalldi gen_random_or_roughlyLinearPrices N=290 M=$MAXM K=200 piMax=$PIMAX days=1000 mode=random
tc med2randsmalldi gen_random_or_roughlyLinearPrices N=280 M=$MAXM K=210 piMax=$PIMAX days=1000 mode=random
tc med3randsmalldi gen_random_or_roughlyLinearPrices N=270 M=$MAXM K=200 piMax=$PIMAX days=1000 mode=random
tc med4randsmalldi gen_random_or_roughlyLinearPrices N=300 M=$MAXM K=100 piMax=$PIMAX days=1000 mode=random
tc med5randsmalldi gen_random_or_roughlyLinearPrices N=290 M=$MAXM K=110 piMax=$PIMAX days=1000 mode=random
tc med6randsmalldi gen_random_or_roughlyLinearPrices N=280 M=$MAXM K=100 piMax=$PIMAX days=1000 mode=random
tc med7randsmalldi gen_random_or_roughlyLinearPrices N=270 M=$MAXM K=110 piMax=$PIMAX days=1000 mode=random
tc med0semirandsmalldi gen_random_or_roughlyLinearPrices N=300 M=$MAXM K=200 piMax=$PIMAX days=1000 mode=rlinear
tc med1semirandsmalldi gen_random_or_roughlyLinearPrices N=290 M=$MAXM K=210 piMax=$PIMAX days=1000 mode=rlinear
tc med2semirandsmalldi gen_random_or_roughlyLinearPrices N=280 M=$MAXM K=210 piMax=$PIMAX days=1000 mode=rlinear
tc med3semirandsmalldi gen_random_or_roughlyLinearPrices N=270 M=$MAXM K=200 piMax=$PIMAX days=1000 mode=rlinear
tc med4semirandsmalldi gen_random_or_roughlyLinearPrices N=300 M=$MAXM K=100 piMax=$PIMAX days=1000 mode=rlinear
tc med5semirandsmalldi gen_random_or_roughlyLinearPrices N=290 M=$MAXM K=100 piMax=$PIMAX days=1000 mode=rlinear
tc med6semirandsmalldi gen_random_or_roughlyLinearPrices N=280 M=$MAXM K=110 piMax=$PIMAX days=1000 mode=rlinear
tc med7semirandsmalldi gen_random_or_roughlyLinearPrices N=270 M=$MAXM K=110 piMax=$PIMAX days=1000 mode=rlinear


group group3 23
limits nMax=300 mMax=$MAXM kMax=300 piMax=$PIMAX days=$DAYS
#tc name input_generator inputs_to_generator
include_group group2
tc med0rand gen_random_or_roughlyLinearPrices N=300 M=$MAXM K=200 piMax=$PIMAX days=$DAYS mode=random
tc med1rand gen_random_or_roughlyLinearPrices N=290 M=$MAXM K=200 piMax=$PIMAX days=$DAYS mode=random
tc med2rand gen_random_or_roughlyLinearPrices N=280 M=$MAXM K=210 piMax=$PIMAX days=$DAYS mode=random
tc med3rand gen_random_or_roughlyLinearPrices N=270 M=$MAXM K=210 piMax=$PIMAX days=$DAYS mode=random
tc med4rand gen_random_or_roughlyLinearPrices N=290 M=$MAXM K=100 piMax=$PIMAX days=$DAYS mode=random
tc med5rand gen_random_or_roughlyLinearPrices N=280 M=$MAXM K=100 piMax=$PIMAX days=$DAYS mode=random
tc med6rand gen_random_or_roughlyLinearPrices N=270 M=$MAXM K=110 piMax=$PIMAX days=$DAYS mode=random
tc med7rand gen_random_or_roughlyLinearPrices N=300 M=$MAXM K=110 piMax=$PIMAX days=$DAYS mode=random
tc med0semirand gen_random_or_roughlyLinearPrices N=300 M=$MAXM K=200 piMax=$PIMAX days=$DAYS mode=rlinear
tc med1semirand gen_random_or_roughlyLinearPrices N=270 M=$MAXM K=210 piMax=$PIMAX days=$DAYS mode=rlinear
tc med2semirand gen_random_or_roughlyLinearPrices N=290 M=$MAXM K=210 piMax=$PIMAX days=$DAYS mode=rlinear
tc med3semirand gen_random_or_roughlyLinearPrices N=280 M=$MAXM K=200 piMax=$PIMAX days=$DAYS mode=rlinear
tc med4semirand gen_random_or_roughlyLinearPrices N=290 M=$MAXM K=100 piMax=$PIMAX days=$DAYS mode=rlinear
tc med5semirand gen_random_or_roughlyLinearPrices N=280 M=$MAXM K=110 piMax=$PIMAX days=$DAYS mode=rlinear
tc med6semirand gen_random_or_roughlyLinearPrices N=270 M=$MAXM K=110 piMax=$PIMAX days=$DAYS mode=rlinear
tc med7semirand gen_random_or_roughlyLinearPrices N=300 M=$MAXM K=100 piMax=$PIMAX days=$DAYS mode=rlinear


group group4 28
limits nMax=$MAXN mMax=$MAXM kMax=0 piMax=$PIMAX days=$DAYS
#tc name input_generator inputs_to_generator
tc med0randk0 gen_random_or_roughlyLinearPrices N=10000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=random
tc med1randk0 gen_random_or_roughlyLinearPrices N=13000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=random
tc med2randk0 gen_random_or_roughlyLinearPrices N=14000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=random
tc med3randk0 gen_random_or_roughlyLinearPrices N=16000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=random
tc large0randk0 gen_random_or_roughlyLinearPrices N=99000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=random
tc large1randk0 gen_random_or_roughlyLinearPrices N=98000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=random
tc large2randk0 gen_random_or_roughlyLinearPrices N=96000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=random
tc large3randk0 gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=random
tc med0semirandk0 gen_random_or_roughlyLinearPrices N=10000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=rlinear
tc med1semirandk0 gen_random_or_roughlyLinearPrices N=13000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=rlinear
tc med2semirandk0 gen_random_or_roughlyLinearPrices N=14000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=rlinear
tc med3semirandk0 gen_random_or_roughlyLinearPrices N=16000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=rlinear
tc large0semirandk0 gen_random_or_roughlyLinearPrices N=99000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=rlinear
tc large1semirandk0 gen_random_or_roughlyLinearPrices N=98000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=rlinear
tc large2semirandk0 gen_random_or_roughlyLinearPrices N=96000 M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=rlinear
tc large3semirandk0 gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=0 piMax=$PIMAX days=$DAYS mode=rlinear


group group5 15
limits nMax=$MAXN mMax=$MAXM kMax=$MAXK piMax=$PIMAX days=$DAYS simpleG=1
#tc name input_generator inputs_to_generator
tc med0randgispecial gen_random_or_roughlyLinearPrices N=10000 M=$MAXM K=5000 piMax=$PIMAX days=$DAYS mode=random compactGi=1
tc med1randgispecial gen_random_or_roughlyLinearPrices N=12000 M=$MAXM K=6000 piMax=$PIMAX days=$DAYS mode=random compactGi=1
tc med2randgispecial gen_random_or_roughlyLinearPrices N=14000 M=$MAXM K=6000 piMax=$PIMAX days=$DAYS mode=random compactGi=1
tc med3randgispecial gen_random_or_roughlyLinearPrices N=16000 M=$MAXM K=5000 piMax=$PIMAX days=$DAYS mode=random compactGi=1
tc large0randgispecial gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=51000 piMax=$PIMAX days=$DAYS mode=random compactGi=1
tc large1randgispecial gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=50000 piMax=$PIMAX days=$DAYS mode=random compactGi=1
tc large2randgispecial gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=56000 piMax=$PIMAX days=$DAYS mode=random compactGi=1
tc large3randgispecial gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=52000 piMax=$PIMAX days=$DAYS mode=random compactGi=1
tc med0semirandgispecial gen_random_or_roughlyLinearPrices N=10000 M=$MAXM K=5000 piMax=$PIMAX days=$DAYS mode=rlinear compactGi=1
tc med1semirandgispecial gen_random_or_roughlyLinearPrices N=12000 M=$MAXM K=6000 piMax=$PIMAX days=$DAYS mode=rlinear compactGi=1
tc med2semirandgispecial gen_random_or_roughlyLinearPrices N=14000 M=$MAXM K=6000 piMax=$PIMAX days=$DAYS mode=rlinear compactGi=1
tc med3semirandgispecial gen_random_or_roughlyLinearPrices N=16000 M=$MAXM K=5000 piMax=$PIMAX days=$DAYS mode=rlinear compactGi=1
tc large0semirandgispecial gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=51000 piMax=$PIMAX days=$DAYS mode=rlinear compactGi=1
tc large1semirandgispecial gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=50000 piMax=$PIMAX days=$DAYS mode=rlinear compactGi=1
tc large2semirandgispecial gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=56000 piMax=$PIMAX days=$DAYS mode=rlinear compactGi=1
tc large3semirandgispecial gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=52000 piMax=$PIMAX days=$DAYS mode=rlinear compactGi=1


group group6 10
limits nMax=$MAXN mMax=$MAXM kMax=$MAXK piMax=$PIMAX days=$DAYS
#tc name input_generator inputs_to_generator
include_group group3
include_group group4
include_group group5
tc large0rand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=50000 piMax=$PIMAX days=$DAYS mode=random
tc large1rand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=53000 piMax=$PIMAX days=$DAYS mode=random
tc large2rand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=52000 piMax=$PIMAX days=$DAYS mode=random
tc large3rand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=51000 piMax=$PIMAX days=$DAYS mode=random
tc large4rand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=10000 piMax=$PIMAX days=$DAYS mode=random
tc large5rand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=11000 piMax=$PIMAX days=$DAYS mode=random
tc large6rand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=13000 piMax=$PIMAX days=$DAYS mode=random
tc large7rand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=12000 piMax=$PIMAX days=$DAYS mode=random
tc large0semirand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=50000 piMax=$PIMAX days=$DAYS mode=rlinear
tc large1semirand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=51000 piMax=$PIMAX days=$DAYS mode=rlinear
tc large2semirand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=54000 piMax=$PIMAX days=$DAYS mode=rlinear
tc large3semirand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=56000 piMax=$PIMAX days=$DAYS mode=rlinear
tc large4semirand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=10000 piMax=$PIMAX days=$DAYS mode=rlinear
tc large5semirand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=12000 piMax=$PIMAX days=$DAYS mode=rlinear
tc large6semirand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=13000 piMax=$PIMAX days=$DAYS mode=rlinear
tc large7semirand gen_random_or_roughlyLinearPrices N=$MAXN M=$MAXM K=15000 piMax=$PIMAX days=$DAYS mode=rlinear
