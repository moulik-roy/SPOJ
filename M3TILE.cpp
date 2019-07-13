#include <iostream>
using namespace std;

int main(){
	int n, i, dp[32][2];
	dp[0][0]=1;		dp[1][0]=0;		dp[0][1]=0;		dp[1][1]=1;
	for(i=2; i<=30; i++){
		dp[i][0]=dp[i-2][0]+2*dp[i-1][1];
		dp[i][1]=dp[i-1][0]+dp[i-2][1];
	}
	while(cin>>n && n!=-1)
		cout<<dp[n][0]<<"\n";
	return 0;
}