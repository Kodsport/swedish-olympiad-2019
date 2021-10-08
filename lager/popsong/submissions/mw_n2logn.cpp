// O(n^2 log n)
#include <bits/stdc++.h>
#define MAXN 20005

using namespace std;

char input[MAXN];
int dp[MAXN][MAXN];

int main(){
	scanf("%s", input);
	int len=strlen(input);
	for(int i=0; 2*i < len; ++i)
		swap(input[i], input[len-1-i]);
	int ans=0;
	for(int width=1; width <= len/2; ++width){
		for(int i=len-1; i >= 0; --i){
			dp[i][1]=min(len-i, width);
			if(i+width >= len || input[i] != input[i+width]){
				for(int j=2; i+(j-1)*width <= len; ++j){
					dp[i][j]=0;
				}
				continue;
			}
			for(int j=2; i+(j-1)*width <= len; ++j){
				dp[i][j]=min(dp[i+1][2]+1, dp[i+width][j-1]);
				if(i+j*width <= len)
					ans=max(ans, dp[i][j]*j);
			}
		}
	}
	printf("%d\n", ans);
}
