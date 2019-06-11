#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
	int n, t, i, j, k, min_toll;
	while(cin>>n>>t && n+t!=0){
		vector <vector<int>> time(n, vector<int>(n)), toll(n, vector<int>(n)), dp(n, vector<int>(t+1, INT_MAX));
		for(i=0; i<n; i++){
			for(j=0; j<n; j++)
				cin>>time[i][j];
		}
		for(i=0; i<n; i++){
			for(j=0; j<n; j++)
				cin>>toll[i][j];
		}
		for(i=0; i<=t; i++)
			dp[0][i]=0;
		for(i=1; i<=t; i++){
			for(j=0; j<n; j++){
				min_toll=INT_MAX;
				for(k=0; k<n; k++){
					if(time[k][j]<=i && dp[k][i-time[k][j]]!=INT_MAX)
						min_toll=min(min_toll, dp[k][i-time[k][j]]+toll[k][j]);
				}
				dp[j][i]=min(dp[j][i-1], min_toll);
			}
		}
		for(i=t; i>0; i--){
			if(dp[n-1][i]!=dp[n-1][t])
				break;
		}
		cout<<dp[n-1][t]<<" "<<i+1<<"\n";
	}
	return 0;
}