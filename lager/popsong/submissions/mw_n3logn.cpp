// O(n^3 log n)
#include <bits/stdc++.h>
#define MAXN 10005

using namespace std;

char input[MAXN];

int main(){
	scanf("%s", input);
	int len=strlen(input);
	for(int i=0; 2*i < len; ++i)
		swap(input[i], input[len-1-i]);	
	int ans=0;
	int bestStart=0, bestLen=0, bestRowN=0, bestAgree=0;
	for(int start=0; start < len; ++start)
		for(int rowLen=1; rowLen <= len; ++rowLen){
			for(int rowN=2; start+rowN*rowLen <= len; ++rowN){
				int nAgree;
				for(nAgree=0; nAgree < rowLen; ++nAgree){
					char c=input[start+nAgree];
					bool ok=1;
					for(int i=1; i < rowN; ++i){
						if(input[start+nAgree+i*rowLen] != c){
							ok=0;
							break;
						}
					}
					if(!ok)
						break;
				}
				if(nAgree*rowN > ans){
					ans=nAgree*rowN;
					bestStart=start;
					bestLen=rowLen;
					bestRowN=rowN;
					bestAgree=nAgree;
				}
			}
		}
	printf("%d\n", ans);
}
