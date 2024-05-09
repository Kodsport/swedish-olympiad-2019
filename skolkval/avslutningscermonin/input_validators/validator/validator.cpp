#include "validator.h"

void run() {
    string people = Line();
	if(!Arg("sample", 0)){
		assert(people.size()>0 && people.size()<=(int)Arg("maxn"));
		int numletters = Arg("maxletter");
		for (auto c : people)
		{
			assert(c>='A');
			assert(c-'A'<numletters);
		}
	}

    int k = Int(1, Arg("k_is"));
    Endl();
    Eof();
}