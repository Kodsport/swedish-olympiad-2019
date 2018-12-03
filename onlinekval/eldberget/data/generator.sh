#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution fredrik.cpp

compile gen_random.py
compile gen_pillars.py
compile gen_bfs.py
compile gen_straight_paths.py
compile poster.py

samplegroup
limits k=-1 special=none
sample 1
sample 2
sample 3
sample 4

group group1 20
limits k=-1 special=pillars
tc poster poster


group group2 7
limits k=-1 special=right_down

tc rd-rand-1 gen_random r=2 c=100 k=100 fireRatio=0.5
tc rd-rand-2 gen_random r=100 c=100 k=200 fireRatio=0.9
tc rd-rand-3 gen_random seed=16 r=100 c=100 k=23 fireRatio=0.5
tc rd-rand-4 gen_random seed=1 r=80 c=100 k=116 fireRatio=0.9
tc rd-rand-5 gen_random seed=1 r=80 c=100 k=117 fireRatio=0.9
tc rd-bfs-11 gen_bfs r=100 c=90 k=10 radius=1 mode=rightDown
tc rd-bfs-12 gen_bfs r=90 c=100 k=100 radius=1 mode=rightDown
tc rd-bfs-21 gen_bfs r=100 c=100 k=17 radius=2 mode=rightDown
tc rd-bfs-31 gen_bfs r=100 c=100 k=30 radius=3 mode=rightDown
tc rd-bfs-51 gen_bfs r=100 c=100 k=15 radius=5 mode=rightDown


group group3 15
limits k=-1 special=pillars

tc pillar-empty gen_random r=100 c=100 k=0 fireRatio=0.0
tc pillar-rand-1 gen_pillars r=100 c=100 k=0 mode=random
tc pillar-assureFreePath-1 gen_pillars r=10 c=10 k=0 mode=assureFreePath
tc pillar-assureFreePath-2 gen_pillars r=80 c=100 k=0 mode=assureFreePath
tc pillar-assureFreePath-3 gen_pillars r=100 c=80 k=0 mode=assureFreePath
tc pillar-assureFreePath-4 gen_pillars r=100 c=100 k=0 mode=assureFreePath
tc pillar-assureFreePath-5 gen_pillars r=100 c=100 k=0 mode=assureFreePath


group group4 10
limits k=0 special=none

include_group group1

tc k0-empty gen_random r=100 c=100 k=0 fireRatio=0.0
tc k0-rand-1 gen_random r=10 c=10 k=0 fireRatio=0.3
tc k0-rand-2 gen_random r=80 c=100 k=0 fireRatio=0.4
tc k0-pillar-1 gen_pillars r=100 c=80 k=0 mode=random
tc k0-pillar-2 gen_pillars r=80 c=100 k=0 mode=assureFreePath
tc k0-straights-1 gen_straight_paths r=100 c=100 k=0
tc k0-bfs-1 gen_bfs r=90 c=100 k=0 radius=1 mode=normal
tc k0-bfs-2 gen_bfs r=100 c=90 k=0 radius=2 mode=normal
tc k0-bfs-3 gen_bfs r=100 c=100 k=0 radius=3 mode=normal
tc k0-bfs-4 gen_bfs r=100 c=100 k=0 radius=4 mode=normal
tc k0-bfs-5 gen_bfs r=100 c=100 k=0 radius=5 mode=normal


group group5 19
limits k=1 special=none

tc k1-empty gen_random r=100 c=100 k=1 fireRatio=0.0
tc k1-rand-1 gen_random r=10 c=10 k=1 fireRatio=0.3
tc k1-rand-2 gen_random r=80 c=100 k=1 fireRatio=0.4
tc k1-pillar-1 gen_pillars r=100 c=80 k=1 mode=random
tc k1-pillar-2 gen_pillars r=80 c=100 k=1 mode=assureFreePath
tc k1-straights-1 gen_straight_paths r=100 c=100 k=1
tc k1-bfs-1 gen_bfs r=90 c=100 k=1 radius=1 mode=normal
tc k1-bfs-2 gen_bfs r=100 c=90 k=1 radius=2 mode=normal
tc k1-bfs-3 gen_bfs r=100 c=100 k=1 radius=3 mode=normal
tc k1-bfs-4 gen_bfs r=100 c=100 k=1 radius=4 mode=normal
tc k1-bfs-5 gen_bfs r=100 c=100 k=1 radius=5 mode=normal


group group6 29
limits k=-1 special=none

include_group group2
include_group group3
include_group group4
include_group group5

tc full-rand-1 gen_random r=100 c=100 k=4 seed=1 fireRatio=0.4
tc full-rand-2 gen_random r=100 c=100 k=15 seed=1 fireRatio=0.5
tc full-rand-3 gen_random r=100 c=100 k=38 seed=1 fireRatio=0.6
tc full-pillar-3 gen_pillars r=100 c=80 k=20 mode=assureFreePath
tc full-pillar-4 gen_pillars r=100 c=100 k=50 mode=assureFreePath
tc full-bfs-11 gen_bfs r=90 c=100 k=2 radius=1 mode=normal
tc full-bfs-12 gen_bfs r=100 c=90 k=20 radius=1 mode=normal
tc full-bfs-13 gen_bfs r=100 c=100 k=100 radius=1 mode=normal
tc full-bfs-14 gen_bfs r=90 c=100 k=200 radius=1 mode=normal
tc full-bfs-21 gen_bfs r=100 c=100 k=6 radius=2 mode=normal
tc full-bfs-22 gen_bfs r=100 c=100 k=17 radius=2 mode=normal
tc full-bfs-31 gen_bfs r=100 c=100 k=5 radius=3 mode=normal
tc full-bfs-32 gen_bfs r=100 c=100 k=30 radius=3 mode=normal
tc full-bfs-41 gen_bfs r=100 c=100 k=15 radius=4 mode=normal
tc full-bfs-51 gen_bfs r=100 c=100 k=15 radius=5 mode=normal
