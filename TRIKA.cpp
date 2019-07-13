#include <iostream>
using namespace std;

int main(){
	int N, M, X, Y, i, j;
	cin>>N>>M>>X>>Y;
	int P[N][M], dp[N][M];
	for(i=0; i<N; i++){
		for(j=0; j<M; j++)
			cin>>P[i][j];
	}
	dp[X-1][Y-1]=P[X-1][Y-1];
	for(i=Y; i<M; i++)
		dp[X-1][i]=dp[X-1][i-1]-P[X-1][i];
	for(i=X; i<N; i++)
		dp[i][Y-1]=dp[i-1][Y-1]-P[i][Y-1];
	for(i=X; i<N; i++){
		for(j=Y; j<M; j++)
			dp[i][j]=max(dp[i-1][j], dp[i][j-1])-P[i][j];
	}
	if(dp[N-1][M-1]<0)
		cout<<"N\n";
	else
		cout<<"Y "<<dp[N-1][M-1]<<"\n";
	return 0;
}