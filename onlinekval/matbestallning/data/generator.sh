#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fe.cpp opt

compile gen_random.py pypy
compile gen_k_equals_n_possible.py
compile gen_all_early.py

MAXN=200000

samplegroup
limits nMax=$MAXN mMax=$MAXN
sample 1
sample 2
sample 3
sample 4


group group1 10
limits nMax=$MAXN mMax=$MAXN allSame=1
tc allSame0 gen_random n=5 m=5 allXSame=true possible=true
tc allSame1 gen_random n=$MAXN m=$MAXN allXSame=true
tc allSame2 gen_random n=$MAXN m=$((MAXN / 2)) allXSame=true possible=true
tc allSame3 gen_random n=$((MAXN / 2)) m=$MAXN allXSame=true possible=true
tc allSame4 gen_random n=$MAXN m=$MAXN allXSame=true distinctPrices=1
tc allSame5 gen_random n=$MAXN m=$MAXN allXSame=true distinctPrices=10
tc allSame6 gen_random n=$MAXN m=$MAXN allXSame=true distinctPrices=20
tc allSamePossible1 gen_random n=$MAXN m=$MAXN allXSame=true possible=true
tc allSamePossible2 gen_random n=$MAXN m=$MAXN allXSame=true possible=true
tc allSameImpossible1 gen_random n=$MAXN m=$MAXN allXSame=true possible=false
tc allSameImpossible2 gen_random n=$MAXN m=$MAXN allXSame=true possible=false
tc allSmallest1 gen_all_early n=$MAXN m=$MAXN k=$((MAXN * 180 / 200)) choices=1
tc allSmallest2 gen_all_early n=$MAXN m=$MAXN k=$((MAXN * 198 / 200)) choices=1


group group2 20
limits nMax=$MAXN mMax=$MAXN kEqualsN=1
tc kEqualsN1 gen_random n=$MAXN m=$MAXN k=$MAXN
tc kEqualsN2 gen_random n=$MAXN m=$MAXN k=$MAXN
tc kEqualsN3 gen_random n=$MAXN m=$MAXN k=$MAXN distinctPrices=1
tc kEqualsN4 gen_random n=$MAXN m=$MAXN k=$MAXN distinctPrices=2
tc kEqualsNPossible1 gen_k_equals_n_possible n=$MAXN m=$MAXN
tc kEqualsNPossible2 gen_k_equals_n_possible n=$MAXN m=$MAXN
tc kEqualsNPossible3 gen_k_equals_n_possible n=$MAXN m=$MAXN
tc kEqualsNPossible4 gen_k_equals_n_possible n=$MAXN m=$MAXN
tc kEqualsAllSmallest1 gen_all_early n=$MAXN m=$MAXN k=$MAXN choices=1
tc kEqualsAllSmallest2 gen_all_early n=$MAXN m=$MAXN k=$MAXN choices=110000 cover=$((MAXN / 2))
tc kEqualsAllSmallest3 gen_all_early n=$MAXN m=$MAXN k=$MAXN choices=100000 cover=$((MAXN * 100 / 200))
tc kEqualsAllSmallest4 gen_all_early n=$MAXN m=$MAXN k=$MAXN choices=60000 cover=$((MAXN * 140 / 200))
tc kEqualsAllSmallest5 gen_all_early n=$MAXN m=$MAXN k=$MAXN choices=90000 cover=$((MAXN * 90 / 200))
tc kEqualsAllSmallest6 gen_all_early n=$MAXN m=$MAXN k=$MAXN choices=70000 cover=$((MAXN * 130 / 200))
tc kEqualsAllSmallest7 gen_all_early n=$MAXN m=$MAXN k=$MAXN choices=90000 cover=$((MAXN * 100 / 200))
tc kEqualsAllSmallest8 gen_all_early n=$MAXN m=$MAXN k=$MAXN choices=50000 cover=$((MAXN * 150 / 200))


group group3 16
limits nMax=15 mMax=15
tc small1 gen_random n=15 m=15
tc small2 gen_random n=15 m=15
tc small3 gen_random n=15 m=15
tc small4 gen_random n=15 m=15 k=12
tc small5 gen_random n=15 m=15 k=13
tc smallPossible1 gen_random n=15 m=15 possible=true
tc smallPossible2 gen_random n=15 m=15 possible=true
tc smallPossible3 gen_random n=15 m=15 possible=true
tc smallImpossible1 gen_random n=15 m=15 possible=false
tc smallImpossible2 gen_random n=15 m=15 possible=false
tc smallImpossible3 gen_random n=15 m=15 possible=false
tc smallDistinct1 gen_random n=15 m=15 distinctPrices=1
tc smallDistinct2 gen_random n=15 m=15 distinctPrices=2
tc smallDistinct3 gen_random n=15 m=15 distinctPrices=3
tc smallDistinct4 gen_random n=15 m=15 distinctPrices=1 possible=true
tc smallDistinct5 gen_random n=15 m=15 distinctPrices=3 possible=true
tc smallDistinct6 gen_random n=15 m=15 distinctPrices=1 possible=false
tc smallDistinct7 gen_random n=15 m=15 distinctPrices=3 possible=false
tc smallAllSmallest1 gen_all_early n=15 m=15 k=12 choices=1
tc smallAllSmallest2 gen_all_early n=15 m=15 k=13 choices=2
tc smallAllSmallest3 gen_all_early n=15 m=15 k=11 choices=3
tc smallAllSmallest4 gen_all_early n=15 m=15 k=14 choices=4


group group4 23
limits nMax=$MAXN mMax=$MAXN easyPrices=1
tc easyPrices0 gen_all_early n=$MAXN m=$MAXN k=193727 choices=$((MAXN / 2)) cover=$((MAXN / 2)) easyPrices=true
tc easyPrices1 gen_random n=2 m=2 easyPrices=true
tc easyPrices2 gen_random n=$MAXN m=$MAXN k=100 easyPrices=true
tc easyPrices3 gen_random n=$MAXN m=$MAXN k=$((MAXN * 9 / 10)) easyPrices=true
tc easyPrices4 gen_random n=$MAXN m=$MAXN easyPrices=true
tc easyPrices5 gen_random n=$MAXN m=$MAXN easyPrices=true
tc easyPrices6 gen_random n=$MAXN m=$MAXN easyPrices=true
tc easyPricesPossible1 gen_random n=$MAXN m=$MAXN possible=true easyPrices=true
tc easyPricesPossible2 gen_random n=$MAXN m=$MAXN possible=true easyPrices=true
tc easyPricesImpossible1 gen_random n=$MAXN m=$MAXN possible=false easyPrices=true
tc easyPricesImpossible2 gen_random n=$MAXN m=$MAXN possible=false easyPrices=true
tc easyPricesAllSmallest1 gen_all_early n=$MAXN m=$MAXN k=$((MAXN * 190 / 200)) choices=5 easyPrices=true
tc easyPricesAllSmallest2 gen_all_early n=$MAXN m=$MAXN k=$((MAXN * 192 / 200)) choices=10 cover=$((MAXN * 15 / 20)) easyPrices=true
tc easyPricesAllSmallest3 gen_all_early n=$MAXN m=$MAXN k=$((MAXN * 194 / 200)) choices=1500 cover=$((MAXN * 16 / 20)) easyPrices=true
tc easyPricesAllSmallest4 gen_all_early n=$MAXN m=$MAXN k=$((MAXN * 191 / 200)) choices=8000 cover=$((MAXN * 17 / 20)) easyPrices=true


group group5 31
limits nMax=$MAXN mMax=$MAXN
include_group group1
include_group group2
include_group group3
include_group group4
tc large1 gen_random n=2 m=2
tc large2 gen_random n=$MAXN m=$MAXN
tc large3 gen_random n=$MAXN m=$MAXN k=10
tc largePossible1 gen_random n=$MAXN m=$MAXN possible=true
tc largePossible2 gen_random n=$MAXN m=$MAXN possible=true
tc largePossible3 gen_random n=$MAXN m=$MAXN possible=true
tc largeImpossible1 gen_random n=$MAXN m=$MAXN possible=false
tc largeImpossible2 gen_random n=$MAXN m=$MAXN possible=false
tc largeImpossible3 gen_random n=$MAXN m=$MAXN possible=false
tc largeDistinct1 gen_random n=$MAXN m=$MAXN distinctPrices=1
tc largeDistinct2 gen_random n=$MAXN m=$MAXN distinctPrices=10
tc largeDistinct3 gen_random n=$MAXN m=$MAXN distinctPrices=1 possible=true
tc largeDistinct4 gen_random n=$MAXN m=$MAXN distinctPrices=10 possible=true
tc largeAllSmallest1 gen_all_early n=$MAXN m=$MAXN k=$((MAXN * 190 / 200)) choices=5
tc largeAllSmallest2 gen_all_early n=$MAXN m=$MAXN k=$((MAXN * 192 / 200)) choices=10 cover=$((MAXN * 150 / 200))
tc largeAllSmallest3 gen_all_early n=$MAXN m=$MAXN k=$((MAXN * 194 / 200)) choices=1500 cover=$((MAXN * 160 / 200))
tc largeAllSmallest4 gen_all_early n=$MAXN m=$MAXN k=$((MAXN * 191 / 200)) choices=8000 cover=$((MAXN * 170 / 200))
