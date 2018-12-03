g++ -std=c++14 ../submissions/accepted/fe_100.cpp
for i in {1..5}
do ./a.out < ./secret/g$i/g$i.in > ./secret/g$i/g$i.ans;
done;

