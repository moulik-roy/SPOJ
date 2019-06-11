#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int N, i, j, length;
	cin>>N;
	int treat_value[N], dp[N][N];
	memset(dp, 0, sizeof(dp));
	for(i=0; i<N; i++)
		cin>>treat_value[i];
	for(i=0; i<N; i++)
		dp[i][i]=N*treat_value[i];
	for(length=1; length<N; length++){
		for(i=0, j=length; j<N; i++, j++)
			dp[i][j]=max(dp[i+1][j]+(N-length)*treat_value[i], dp[i][j-1]+(N-length)*treat_value[j]);
	}
	cout<<dp[0][N-1]<<"\n";
	return 0;
}