#include "validator.h"

void run(){
    int n = Int(Arg("lo", 3), Arg("hi", 10));
    Endl();

    SpacedInts(n, 1, 5);
    SpacedInts(n, 1, 5);
    Eof();
}