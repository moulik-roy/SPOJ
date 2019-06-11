#include <cstdio>
using namespace std;

long int BGC(long int dp[], long int n){
	if(n<12)
		return n;
	if(dp[n]!=0)
		return dp[n];
	long int x=BGC(dp, n/2)+BGC(dp, n/3)+BGC(dp, n/4);
	if(n>x)
		dp[n]=n;
	else
		dp[n]=x;
	return dp[n];
}

int main(){
	long int n;
	while(scanf("%ld", &n)==1){
		long int dp[n+1]={0};
		printf("%ld\n", BGC(dp, n));
	}
	return 0;
}