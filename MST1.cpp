#include <iostream>
using namespace std;

int main(){
	int T, t, N, i, dp[20000002];
	dp[0]=dp[1]=0;
	for(i=2; i<20000001; i++){
		dp[i]=dp[i-1]+1;
		if(i%2==0)
			dp[i]=min(dp[i], dp[i/2]+1);
		if(i%3==0)
			dp[i]=min(dp[i], dp[i/3]+1);
	}
	cin>>T;
	for(t=1; t<=T; t++){
		cin>>N;
		cout<<"Case "<<t<<": "<<dp[N]<<"\n";
	}
	return 0;
}