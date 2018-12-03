#include <stdio.h>
#include <string.h>

int main() {
	char s[100],org[100];
	int map[100][100];
	int N,M,K,r,c,i,dr,dc;
	scanf("%d %d %s", &N,&M,s);
	K=strlen(s);
	for(r=0;r<N;r++) for(c=0;c<M;c++) map[r][c]=-1;
	r=c=0;
	dr=dc=1;
	for(i=0;i<K;i++) {
		if(map[r][c]==-1) map[r][c]=i;
		else i--;
		if(r+dr==N || r+dr<0) dr=-dr;
		if(c+dc==M || c+dc<0) dc=-dc;
		r+=dr;
		c+=dc;
	}
	i=0;
	for(r=0;r<N;r++) for(c=0;c<M;c++) 
		if(map[r][c]!=-1) org[map[r][c]]=s[i++];
	org[K]=0;
	printf("%s\n",org);
	return 0;
}
