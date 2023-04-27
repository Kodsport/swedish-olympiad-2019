#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution sl.cpp

compile gen.py
compile gen_23.py

G1MAX=1000
G2MIN=1000
G2MAX=1000000000

SMALL_RANGE=4,$G1MAX
RANGE=$G2MIN,$G2MAX

samplegroup
limits max=$G2MAX
sample 1
sample 2
sample 3

group group1 30
limits max=$G1MAX
tc 1
tc 2
tc_manual ../manual_tests/small1.in
tc_manual ../manual_tests/small2.in
tc_manual ../manual_tests/small3.in
tc_manual ../manual_tests/small4.in
tc twothree-0 gen_23 index=0
tc twothree-1 gen_23 index=1
tc twothree-2 gen_23 index=2
tc twothree-3 gen_23 index=3
tc twothree-4 gen_23 index=4
tc twothree-5 gen_23 index=5
tc twothree-6 gen_23 index=6
tc twothree-7 gen_23 index=7
tc small_med_dn0 gen n=2 m=$SMALL_RANGE xmode=diff ymode=next
tc small_med_dn1 gen n=3 m=$SMALL_RANGE xmode=diff ymode=next edge=1
tc small_med_nn0 gen n=3 m=$SMALL_RANGE xmode=next ymode=next
tc med_small_nn1 gen n=$SMALL_RANGE m=2 xmode=next ymode=next edge=1
tc small_med_dd0 gen n=4 m=$SMALL_RANGE xmode=diff ymode=diff
tc small_med_dd1 gen n=5 m=$SMALL_RANGE xmode=diff ymode=diff edge=1
tc small_med_cn0 gen n=3 m=$SMALL_RANGE xmode=close ymode=next
tc small_med_cn1 gen n=4 m=$SMALL_RANGE xmode=close ymode=next edge=1
tc med_small_dd0 gen n=$SMALL_RANGE m=7 xmode=diff ymode=diff
tc med_small_dd1 gen n=$SMALL_RANGE m=4 xmode=diff ymode=diff edge=1
tc med_small_dn0 gen n=$SMALL_RANGE m=3 xmode=diff ymode=next
tc med_small_dn1 gen n=$SMALL_RANGE m=4 xmode=diff ymode=next edge=1
tc med_small_cn0 gen n=$SMALL_RANGE m=4 xmode=close ymode=next
tc med_small_cn1 gen n=$SMALL_RANGE m=2 xmode=close ymode=next edge=1
tc small_med_ds0 gen n=4 m=$SMALL_RANGE xmode=diff ymode=same
tc small_med_ds1 gen n=3 m=$SMALL_RANGE xmode=diff ymode=same edge=1
tc small_med_ns0 gen n=3 m=$SMALL_RANGE xmode=next ymode=same
tc small_med_ns1 gen n=3 m=$SMALL_RANGE xmode=next ymode=same edge=1
tc small_med_sc0 gen n=4 m=$SMALL_RANGE xmode=same ymode=close
tc small_med_sc1 gen n=2 m=$SMALL_RANGE xmode=same ymode=close edge=1
tc med_small_sd0 gen n=$SMALL_RANGE m=4 xmode=same ymode=diff
tc med_small_sd1 gen n=$SMALL_RANGE m=3 xmode=same ymode=diff edge=1
tc med_small_ns0 gen n=$SMALL_RANGE m=3 xmode=next ymode=same
tc med_small_ns1 gen n=$SMALL_RANGE m=4 xmode=next ymode=same edge=1
tc med_small_cs0 gen n=$SMALL_RANGE m=3 xmode=close ymode=same
tc med_small_cs1 gen n=$SMALL_RANGE m=4 xmode=close ymode=same edge=1
tc med_dd0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=diff ymode=diff
tc med_dd1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=diff ymode=diff edge=1
tc med_dd2 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=diff ymode=diff
tc med_dd3 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=diff ymode=diff edge=1
tc med_ds0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=diff ymode=same
tc med_ds1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=diff ymode=same edge=1
tc med_sd0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=same ymode=diff
tc med_sd1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=same ymode=diff edge=1
tc med_dn0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=diff ymode=next
tc med_dn1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=diff ymode=next edge=1
tc med_nd0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=next ymode=diff
tc med_nd1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=next ymode=diff edge=1
tc med_nn0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=next ymode=next
tc med_nn1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=next ymode=next edge=1
tc med_ns0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=next ymode=same
tc med_ns1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=next ymode=same edge=1
tc med_sn0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=same ymode=next
tc med_sn1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=same ymode=next edge=1
tc med_cc0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=close ymode=close
tc med_cc1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=close ymode=close edge=1
tc med_cs0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=close ymode=same
tc med_cs1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=close ymode=same edge=1
tc med_sc0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=same ymode=close
tc med_sc1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=same ymode=close edge=1
tc med_cn0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=close ymode=next
tc med_cn1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=close ymode=next edge=1
tc med_nc0 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=next ymode=close
tc med_nc1 gen n=$SMALL_RANGE m=$SMALL_RANGE xmode=next ymode=close edge=1

group group2 25
limits min=$G2MIN max=$G2MAX
tc large_dd0 gen n=$RANGE m=$RANGE xmode=diff ymode=diff
tc large_dd1 gen n=$RANGE m=$RANGE xmode=diff ymode=diff edge=1
tc large_dd2 gen n=$RANGE m=$RANGE xmode=diff ymode=diff
tc large_dd3 gen n=$RANGE m=$RANGE xmode=diff ymode=diff edge=1
tc large_ds0 gen n=$RANGE m=$RANGE xmode=diff ymode=same
tc large_ds1 gen n=$RANGE m=$RANGE xmode=diff ymode=same edge=1
tc large_sd0 gen n=$RANGE m=$RANGE xmode=same ymode=diff
tc large_sd1 gen n=$RANGE m=$RANGE xmode=same ymode=diff edge=1
tc large_dn0 gen n=$RANGE m=$RANGE xmode=diff ymode=next
tc large_dn1 gen n=$RANGE m=$RANGE xmode=diff ymode=next edge=1
tc large_nd0 gen n=$RANGE m=$RANGE xmode=next ymode=diff
tc large_nd1 gen n=$RANGE m=$RANGE xmode=next ymode=diff edge=1
tc large_nn0 gen n=$RANGE m=$RANGE xmode=next ymode=next
tc large_nn1 gen n=$RANGE m=$RANGE xmode=next ymode=next edge=1
tc large_ns0 gen n=$RANGE m=$RANGE xmode=next ymode=same
tc large_ns1 gen n=$RANGE m=$RANGE xmode=next ymode=same edge=1
tc large_sn0 gen n=$RANGE m=$RANGE xmode=same ymode=next
tc large_sn1 gen n=$RANGE m=$RANGE xmode=same ymode=next edge=1
tc large_cc0 gen n=$RANGE m=$RANGE xmode=close ymode=close
tc large_cc1 gen n=$RANGE m=$RANGE xmode=close ymode=close edge=1
tc large_cs0 gen n=$RANGE m=$RANGE xmode=close ymode=same
tc large_cs1 gen n=$RANGE m=$RANGE xmode=close ymode=same edge=1
tc large_sc0 gen n=$RANGE m=$RANGE xmode=same ymode=close
tc large_sc1 gen n=$RANGE m=$RANGE xmode=same ymode=close edge=1
tc large_cn0 gen n=$RANGE m=$RANGE xmode=close ymode=next
tc large_cn1 gen n=$RANGE m=$RANGE xmode=close ymode=next edge=1
tc large_nc0 gen n=$RANGE m=$RANGE xmode=next ymode=close
tc large_nc1 gen n=$RANGE m=$RANGE xmode=next ymode=close edge=1
tc max_dd0 gen n=$G2MAX m=$G2MAX xmode=diff ymode=diff
tc max_dd1 gen n=$G2MAX m=$G2MAX xmode=diff ymode=diff edge=1
tc max_ds0 gen n=$G2MAX m=$G2MAX xmode=diff ymode=same
tc max_sd0 gen n=$G2MAX m=$G2MAX xmode=same ymode=diff edge=1
tc max_ns0 gen n=$G2MAX m=$G2MAX xmode=next ymode=same edge=1
tc max_sn0 gen n=$G2MAX m=$G2MAX xmode=same ymode=next

group group3 15
limits max=$G2MAX nosame=1
tc 1
tc small1
tc small3
tc small4
tc twothree-0
tc twothree-1
tc twothree-2
tc twothree-3
tc twothree-4
tc twothree-5
tc twothree-6
tc twothree-7
tc med_dd0
tc med_dd1
tc med_dd2
tc med_dd3
tc med_dn0
tc med_dn1
tc med_nd0
tc med_nd1
tc med_nn0
tc med_nn1
tc med_cc0
tc med_cc1
tc med_cn0
tc med_cn1
tc med_nc0
tc med_nc1
tc large_dd0
tc large_dd1
tc large_dd2
tc large_dd3
tc large_dn0
tc large_dn1
tc large_nd0
tc large_nd1
tc large_nn0
tc large_nn1
tc large_cc0
tc large_cc1
tc large_cn0
tc large_cn1
tc large_nc0
tc large_nc1
tc max_dd0
tc max_dd1
tc_manual ../manual_tests/randkill5.in
tc small_med_dn0
tc small_med_dn1
tc small_med_nn0
tc small_med_dd0
tc small_med_dd1
tc small_med_cn0
tc small_med_cn1
tc med_small_nn1
tc med_small_dd0
tc med_small_dd1
tc med_small_dn0
tc med_small_dn1
tc med_small_cn0
tc med_small_cn1
tc small_large_nd0 gen n=4 m=$RANGE xmode=next ymode=diff
tc small_large_nd1 gen n=2 m=$RANGE xmode=next ymode=diff edge=1
tc small_large_cc0 gen n=3 m=$RANGE xmode=close ymode=close
tc small_large_cc1 gen n=4 m=$RANGE xmode=close ymode=close edge=1
tc small_large_dd2 gen n=4 m=$RANGE xmode=diff ymode=diff
tc small_large_dd3 gen n=4 m=$RANGE xmode=diff ymode=diff edge=1
tc small_large_nc0 gen n=2 m=$RANGE xmode=next ymode=close
tc small_large_nc1 gen n=3 m=$RANGE xmode=next ymode=close edge=1
tc large_small_dd2 gen n=$RANGE m=4 xmode=diff ymode=diff
tc large_small_dd3 gen n=$RANGE m=4 xmode=diff ymode=diff edge=1
tc large_small_nd0 gen n=$RANGE m=2 xmode=next ymode=diff
tc large_small_nd1 gen n=$RANGE m=3 xmode=next ymode=diff edge=1
tc large_small_cc0 gen n=$RANGE m=4 xmode=close ymode=close
tc large_small_cc1 gen n=$RANGE m=5 xmode=close ymode=close edge=1
tc large_small_nn0 gen n=$RANGE m=5 xmode=next ymode=next
tc small_large_nn1 gen n=5 m=$RANGE xmode=next ymode=next edge=1
tc large_small_nc0 gen n=$RANGE m=3 xmode=next ymode=close
tc large_small_nc1 gen n=$RANGE m=4 xmode=next ymode=close edge=1
tc max_dd0
tc max_dd1

group group4 30
limits max=$G2MAX
include_group group1
include_group group2
include_group group3
tc 3
tc_manual ../manual_tests/randkill1.in
tc_manual ../manual_tests/randkill2.in
tc_manual ../manual_tests/randkill3.in
tc_manual ../manual_tests/randkill4.in
tc small_large_sd0 gen n=3 m=$RANGE xmode=same ymode=diff
tc small_large_sd1 gen n=4 m=$RANGE xmode=same ymode=diff edge=1
tc small_large_sn0 gen n=4 m=$RANGE xmode=same ymode=next
tc small_large_sn1 gen n=3 m=$RANGE xmode=same ymode=next edge=1
tc small_large_cs0 gen n=4 m=$RANGE xmode=close ymode=same
tc small_large_cs1 gen n=4 m=$RANGE xmode=close ymode=same edge=1
tc large_small_ds0 gen n=$RANGE m=2 xmode=diff ymode=same
tc large_small_ds1 gen n=$RANGE m=3 xmode=diff ymode=same edge=1
tc large_small_sn0 gen n=$RANGE m=3 xmode=same ymode=next
tc large_small_sn1 gen n=$RANGE m=3 xmode=same ymode=next edge=1
tc large_small_sc0 gen n=$RANGE m=4 xmode=same ymode=close
tc large_small_sc1 gen n=$RANGE m=4 xmode=same ymode=close edge=1
