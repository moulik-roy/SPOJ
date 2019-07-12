#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int P, t, n, k, i, j, count;
	cin>>P;
	while(P--){
		cin>>t>>n>>k;
		int dp[n+1][k+1][2];
		memset(dp, 0, sizeof(dp));
		dp[1][0][0]=dp[1][0][1]=1;
		for(i=2; i<=n; i++){
			for(j=0; j<=k; j++){
				dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
				dp[i][j][1]=dp[i-1][j][0]+((j>0)?dp[i-1][j-1][1]:0);
			}
		}
		count=dp[n][k][0]+dp[n][k][1];
		cout<<t<<" "<<count<<"\n";
	}
	return 0;
}