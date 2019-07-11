#include <iostream>
using namespace std;

int main(){
	int K, N, i, j;
	cin>>K>>N;
	int v[N], w[N], dp[N+1][K+1];
	for(i=0; i<N; i++)
		cin>>v[i]>>w[i];
	for(i=0; i<=N; i++){
		for(j=0; j<=K; j++){
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(w[i-1]<=j)
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i-1]]+v[i-1]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[N][K]<<"\n";
	return 0;
}