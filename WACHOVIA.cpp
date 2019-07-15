#include <iostream>
using namespace std;

int main(){
	int N, K, M, i, j;
	cin>>N;
	while(N--){
		cin>>K>>M;
		int weight[M], value[M], dp[M+1][K+1];
		for(i=0; i<M; i++)
			cin>>weight[i]>>value[i];
		for(i=0; i<=M; i++){
			for(j=0; j<=K; j++){
				if(i==0 || j==0)
					dp[i][j]=0;
				else if(weight[i-1]<=j)
					dp[i][j]=max(dp[i-1][j], dp[i-1][j-weight[i-1]]+value[i-1]);
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		cout<<"Hey stupid robber, you can get "<<dp[M][K]<<".\n";
	}
	return 0;
}