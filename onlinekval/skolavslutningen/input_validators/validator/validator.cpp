#include "validator.h"

void run() {
	int nMax = Arg("nMax");
	int mMax = Arg("mMax");
	int exactk = Arg("k", -1);
	int n = Int(1,nMax);
	Space();
	int m = Int(1,mMax);
	Space();
	int k = Int(1, 26);
	Endl();

	if(exactk!=-1) assert(k==exactk);

	set<char> classes;

	for(int i = 0; i<n;i++){
		for(int j = 0; j<m;j++){
			char c = Char();
			classes.insert(c);
			assert('A'<=c&&c<'A'+k);
		}
		Endl();	
	}
	assert(int(classes.size())==k); //At least one from each class
}
