#include "validator.h"

void run() {
	int n = Int(1,200);
	Endl();

	bool easyWin = Arg("easyWin");

	int aScore = 0;
	int bScore = 0;
	int aSet = 0;
	int bSet = 0;
	int len = 0;
	while(true){
		char c = Char();
		assert(c == 'A' || c == 'B');
		len++;

		if(c=='A') aScore++;
		if(c=='B') bScore++;
		
		int winScore = (aSet+bSet==2)?15:25;
		if(aScore>=winScore&&aScore>=2+bScore){
			if(aScore>winScore) assert(!easyWin);
			aSet++;
			aScore=0;
			bScore=0;
		}
		if(bScore>=winScore&&bScore>=2+aScore){
			if(bScore>winScore) assert(!easyWin);
			bSet++;
			aScore=0;
			bScore=0;
		}
		if(aSet==2||bSet==2) break;
	}
	Endl();
	assert(len == n);
}
