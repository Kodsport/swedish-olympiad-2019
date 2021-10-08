// O(n^2)
#include <bits/stdc++.h>
#define MAXN 20005

using namespace std;

char input[MAXN];
int firstLink[MAXN], lastLink[MAXN], Next[MAXN], nEquidistant[MAXN];
int Left[MAXN], Right[MAXN];
bool added[MAXN];

int main(){
	scanf("%s", input);
	int len=strlen(input);
	for(int i=0; 2*i < len; ++i)
		swap(input[i], input[len-1-i]);	
	int ans=0;
	for(int i=1; i < len; ++i){
		for(int j=len-1; j >= 0; --j){
			if(j+i >= len)
				nEquidistant[j]=1;
			else if(input[j] == input[j+i])
				nEquidistant[j]=nEquidistant[i+j]+1;
			else
				nEquidistant[j]=1;
		}
		int startGood=0, minLength=len;
		for(int j=0; j <= len; ++j){
			firstLink[j]=-1;
			lastLink[j]=-1;
		}
		for(int j=0; j < len; ++j){
			added[j]=0;
			if(nEquidistant[j] == 1)
				continue;
			if(firstLink[nEquidistant[j]] == -1)
				firstLink[nEquidistant[j]]=j;
			else
				Next[lastLink[nEquidistant[j]]]=j;
			lastLink[nEquidistant[j]]=j;
			Next[j]=-1;
		}
		for(int j=len; j >= 2; --j){
			for(int k=firstLink[j]; k != -1; k=Next[k]){
				int add=k, l, r;
				l=add;
				r=add;
				if(add && added[add-1]){
					l=Left[add-1];
				}
				if(add < len-1 && added[add+1]){
					r=Right[add+1];
				}
				Left[r]=l;
				Right[l]=r;
				added[add]=1;
				bool addJ=0;
				if(l+i*j > len){
					--j;
					addJ=1;
				}
				if(j > 1)
				{
					int inRow=min(r+1-l, i);
					ans=max(ans, inRow*j);
				}
				j += addJ;
			}
		}
	}
	printf("%d\n", ans);
}
