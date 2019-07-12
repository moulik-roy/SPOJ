#include <iostream>
using namespace std;

int main(){
	int S, N, i, j;
	cin>>S>>N;
	int size[N], value[N], dp[N+1][S+1];
	for(i=0; i<N; i++)
		cin>>size[i]>>value[i];
	for(i=0; i<=N; i++){
		for(j=0; j<=S; j++){
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(size[i-1]<=j)
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-size[i-1]]+value[i-1]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[N][S]<<"\n";
	return 0;
}