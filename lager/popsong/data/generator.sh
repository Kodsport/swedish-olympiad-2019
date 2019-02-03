#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution sl.cpp opt

compile gen_almost_one_char.py
compile gen_alphabet.py
compile gen_increasing.py
compile gen_mixed_solution.py
compile gen_multi_increasing.py
compile gen_one_char.py
compile gen_random.py
compile gen_repeat.py
compile gen_segment.py
compile gen_weighted_random.py
compile gen_sparse.py
compile gen_johan.py
compile gen_abba.py

samplegroup
limits n=1000
sample 1
sample 2
sample 3

# group group1 10
# N=100
# limits n=$N
# tc rand-2 gen_random n=2
# tc rand-10 gen_random n=10
# tc rand-50 gen_random n=50
# tc rand-90 gen_random n=90
# tc g1-rand-1 gen_random n=$N
# tc g1-onechar-100 gen_one_char n=$N
# tc g1-almost_one_char-10 gen_almost_one_char n=10
# tc g1-almost_one_char-50 gen_almost_one_char n=50
# tc g1-almost_one_char gen_almost_one_char n=$N
# tc g1-alphabet-100 gen_alphabet n=$N
# tc g1-increasing-1 gen_increasing n=$N mod=10 d=0
# tc g1-increasing-2 gen_increasing n=$N mod=10 d=1
# tc g1-increasing-3 gen_increasing n=$N mod=30 d=0
# tc g1-repeat-1 gen_repeat n=$N r=10
# tc g1-repeat-2 gen_repeat n=$N r=40
# tc g1-segment-1 gen_segment n=$N
# tc g1-segment-2 gen_segment n=$N
# tc g1-mixed-1 gen_mixed_solution n=$N
# tc g1-mixed-2 gen_mixed_solution n=$N
# tc g1-weighted-1 gen_mixed_solution n=$N
# tc g1-weighted-2 gen_mixed_solution n=$N
# tc g1-multi-1 gen_multi_increasing n=$N
# tc g1-multi-2 gen_multi_increasing n=$N
# tc g1-abba gen_abba n=$N

group group1 30
N=400
limits n=$N
tc g2-rand-200 gen_random n=200
tc g2-rand-400 gen_random n=400
tc g2-rand-1 gen_random n=$N
tc g2-onechar gen_one_char n=$N
tc g2-almost_one_char-200 gen_almost_one_char n=200
tc g2-almost_one_char-400 gen_almost_one_char n=400
tc g2-almost_one_char gen_almost_one_char n=$N
tc g2-alphabet gen_alphabet n=$N
tc g2-increasing-1 gen_increasing n=$N mod=22 d=0
tc g2-increasing-2 gen_increasing n=$N mod=22 d=1
tc g2-increasing-3 gen_increasing n=$N mod=50 d=0
tc g2-repeat-1 gen_repeat n=$N r=10
tc g2-repeat-2 gen_repeat n=$N r=40
tc g2-repeat-3 gen_repeat n=$N r=100
tc g2-segment-1 gen_segment n=$N
tc g2-segment-2 gen_segment n=$N
tc g2-mixed-1 gen_mixed_solution n=$N
tc g2-mixed-2 gen_mixed_solution n=$N
tc g2-weighted-1 gen_mixed_solution n=$N
tc g2-weighted-2 gen_mixed_solution n=$N
tc g2-multi-1 gen_multi_increasing n=$N
tc g2-multi-2 gen_multi_increasing n=$N
tc g2-johan-1 gen_johan n=$N before=0 after=0
tc g2-johan-2 gen_johan n=$N before=40 after=20
tc g2-abba gen_abba n=$N

group group2 30
N=4000
limits n=$N
include_group group1
tc g3-rand-1 gen_random n=$N
tc g3-rand-2 gen_random n=$N
tc g3-onechar gen_one_char n=$N
tc g3-almost_one_char-700 gen_almost_one_char n=1400
tc g3-almost_one_char-1000 gen_almost_one_char n=2000
tc g3-almost_one_char-1500 gen_almost_one_char n=3000
tc g3-almost_one_char gen_almost_one_char n=$N
tc g3-alphabet gen_alphabet n=$N
tc g3-increasing-1 gen_increasing n=$N mod=50 d=0
tc g3-increasing-2 gen_increasing n=$N mod=50 d=1
tc g3-increasing-3 gen_increasing n=$N mod=100 d=0
tc g3-repeat-1 gen_repeat n=$N r=3
tc g3-repeat-2 gen_repeat n=$N r=41
tc g3-repeat-3 gen_repeat n=$N r=150
tc g3-repeat-4 gen_repeat n=$N r=1000
tc g3-repeat-5 gen_repeat n=$N r=1400
tc g3-segment-1 gen_segment n=$N
tc g3-segment-2 gen_segment n=$N
tc g3-mixed-1 gen_mixed_solution n=$N
tc g3-mixed-2 gen_mixed_solution n=$N
tc g3-weighted-1 gen_mixed_solution n=$N
tc g3-weighted-2 gen_mixed_solution n=$N
tc g3-multi-1 gen_multi_increasing n=$N
tc g3-multi-2 gen_multi_increasing n=$N
tc g3-sparse-1 gen_sparse n=$N k=1
tc g3-sparse-2 gen_sparse n=$N k=2
tc g3-sparse-3 gen_sparse n=$N k=3
tc g3-sparse-4 gen_sparse n=$N k=3
tc g3-sparse-5 gen_sparse n=$N k=3
tc g3-sparse-6 gen_sparse n=$N k=3
tc g3-johan-1 gen_johan n=$N before=0 after=0
tc g3-johan-2 gen_johan n=$N before=40 after=20
tc g3-abba gen_abba n=$N

group group3 40
N=15000
limits n=$N
include_group group2
tc g4-rand-1 gen_random n=$N
tc g4-rand-2 gen_random n=$N
tc g4-rand-3 gen_random n=$((N - 1000))
tc g4-onechar gen_one_char n=$N
tc g4-almost_one_char-1 gen_almost_one_char n=$N
tc g4-almost_one_char-2 gen_almost_one_char n=10000
tc g4-almost_one_char-3 gen_almost_one_char n=13000
tc g4-almost_one_char-4 gen_almost_one_char n=14000
tc g4-almost_one_char-5 gen_almost_one_char n=14900
tc g4-alphabet gen_alphabet n=$N
tc g4-increasing-1 gen_increasing n=$N mod=100 d=0
tc g4-increasing-2 gen_increasing n=$N mod=100 d=1
tc g4-increasing-3 gen_increasing n=$N mod=500 d=0
tc g4-repeat-1 gen_repeat n=$N r=3
tc g4-repeat-2 gen_repeat n=$N r=40
tc g4-repeat-3 gen_repeat n=$N r=101
tc g4-repeat-4 gen_repeat n=$N r=700
tc g4-repeat-5 gen_repeat n=$N r=3000
tc g4-repeat-6 gen_repeat n=$N r=4500
tc g4-segment-1 gen_segment n=$N
tc g4-segment-2 gen_segment n=$N
tc g4-mixed-1 gen_mixed_solution n=$N
tc g4-mixed-2 gen_mixed_solution n=$N
tc g4-weighted-1 gen_mixed_solution n=$N
tc g4-weighted-2 gen_mixed_solution n=$N
tc g4-multi-1 gen_multi_increasing n=$N
tc g4-multi-2 gen_multi_increasing n=$N
tc g4-sparse-1 gen_sparse n=$N k=1
tc g4-sparse-2 gen_sparse n=$N k=2
tc g4-sparse-3 gen_sparse n=$N k=3
tc g4-sparse-4 gen_sparse n=$N k=3
tc g4-sparse-5 gen_sparse n=$N k=3
tc g4-sparse-6 gen_sparse n=$N k=3
tc g4-sparse-7 gen_sparse n=$N k=3
tc g4-sparse-8 gen_sparse n=$N k=3
tc g4-johan-1 gen_johan n=$N before=0 after=0
tc g4-johan-2 gen_johan n=$N before=711 after=932
tc g4-johan-3 gen_johan n=$N before=392 after=221
tc g4-abba gen_abba n=$N
