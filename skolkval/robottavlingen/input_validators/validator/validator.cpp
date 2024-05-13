#include "validator.h"

void run(){
    int n;
    n = Int(3, 10); Space();
    int n_is = Arg("n_is", -1);
    if(n_is!=-1)assert(n_is==n);
    assert((int)Arg("lo", 3)<=n && (int)Arg("hi", 10)>=n);

    for(int i = 0; i<n; i++){
        if(i) Space();
        Int(1, 5); 
    }
    Endl();
    for(int i = 0; i<n; i++){
        if(i) Space();
        Int(1, 5); 
    }
    Endl();
    Eof();
}