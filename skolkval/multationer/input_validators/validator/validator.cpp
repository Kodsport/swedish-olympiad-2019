#include "validator.h"

void run(){
    string start = Line();
    string goal = Line();
    if(Arg("equal_len", 0))assert(start.size()==goal.size());
    assert(start.size()<=goal.size());
    assert(10>=goal.size());
    assert(start.size()>=1);
    /*
    Endl();
    */
    Eof();
}