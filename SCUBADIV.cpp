#include <iostream>
#include <climits>
using namespace std;

int main(){
	int t, O, N, n, i, j, k;
	cin>>t;
	while(t--){
		cin>>O>>N>>n;
		int cylinder[n][3], dp[n+1][O+1][N+1];
		for(i=0; i<n; i++){
			for(j=0; j<3; j++)
				cin>>cylinder[i][j];
		}
		for(i=0; i<=n; i++){
			for(j=0; j<=O; j++){
				for(k=0; k<=N; k++){
					if(j==0 && k==0)
						dp[i][j][k]=0;
					else if(i==0 || dp[i-1][max(j-cylinder[i-1][0], 0)][max(k-cylinder[i-1][1], 0)]==INT_MAX)
						dp[i][j][k]=INT_MAX;
					else
						dp[i][j][k]=min(dp[i-1][j][k], dp[i-1][max(j-cylinder[i-1][0], 0)][max(k-cylinder[i-1][1], 0)]+cylinder[i-1][2]);
				}
			}
		}
		cout<<dp[n][O][N]<<"\n";
	}
	return 0;
}