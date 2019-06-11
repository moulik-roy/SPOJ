#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
	int t, N, T, i, j, k, min_risk;
	cin>>t;
	while(t--){
		cin>>N>>T;
		vector <vector<int>> time(N, vector<int>(N)), risk(N, vector<int>(N)), dp(N, vector<int>(T+1, INT_MAX));
		for(i=0; i<N; i++){
			for(j=0; j<N; j++)
				cin>>time[i][j];
		}
		for(i=0; i<N; i++){
			for(j=0; j<N; j++)
				cin>>risk[i][j];
		}
		for(i=0; i<=T; i++)
			dp[0][i]=0;
		for(i=1; i<=T; i++){
			for(j=0; j<N; j++){
				min_risk=INT_MAX;
				for(k=0; k<N; k++){
					if(time[k][j]<=i && dp[k][i-time[k][j]]!=INT_MAX)
						min_risk=min(min_risk, dp[k][i-time[k][j]]+risk[k][j]);
				}
				dp[j][i]=min(dp[j][i-1], min_risk);
			}
		}
		if(dp[N-1][T]==INT_MAX)
			cout<<"-1\n";
		else{
			for(i=T; i>0; i--){
				if(dp[N-1][i]!=dp[N-1][T])
					break;
			}
			cout<<dp[N-1][T]<<" "<<i+1<<"\n";
		}
	}
	return 0;
}