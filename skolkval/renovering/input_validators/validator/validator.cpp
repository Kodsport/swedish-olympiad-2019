#include "validator.h"

void run(){
    int n, m;
    n = Int(1, 15); Space();
    m = Int(1, 15); Endl();
    for(int i = 0; i<n; i++){
        if(i) Space();
        Int(1, 100); 
    }
    Endl();
    for(int i = 0; i<m; i++){
        if(i) Space();
        Int(1, 100); 
    }
    Endl();
    Eof();
}