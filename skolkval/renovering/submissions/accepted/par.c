#include <stdio.h>

int main() {
	int x[101],y[101],N,M,i,j,a,b;
	scanf("%d %d", &N,&M);
	for(i=0;i<=100;i++) x[i]=y[i]=0;
	for(i=0;i<N;i++) {scanf("%d", &j); x[j]++; }
	for(i=0;i<M;i++) {scanf("%d", &j); y[j]++; }
	for(a=100;a>0;a--) {
		b=a;
		while(y[a]>0 && b>0){
			if(x[b]>0) {
				x[b]--;
				y[a]--;
				N--;
			}
			else b--;
		}
	}
	printf("%d\n", N);
	for(i=1;i<=100;i++) for(j=0;j<x[i];j++) printf("%d ", i);
	printf("\n");
	return 0;
}
