#include "validator.h"

void run(){
    int lo = 1, hi = 100;
    int n_is = Arg("n_is", -1);
    if(n_is!=-1)lo=hi=n_is;
    Int(1, hi);
    Endl();
    Eof();
}