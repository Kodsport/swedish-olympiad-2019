#include "validator.h"

void run() {
    string people = Line();
    bool is_sample = (bool)Arg("sample", 0);
    if(!is_sample){
        assert(people.size()>0 && people.size()<=(int)Arg("maxn"));
        int numletters = Arg("maxletter");
        set<char> occ;
        for (auto c : people)
        {
            assert(c>='A');
            assert(c-'A'<numletters);
            occ.insert(c);
        }
        assert(occ.size()==numletters);
    }

    int k_hi = 2;
    int k_lo = 1;
    if (!is_sample) k_hi=Arg("k_is"),k_lo=k_hi;
    Int(k_lo, k_hi);
    Endl();
    Eof();
}