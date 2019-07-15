#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int main(){
	int T, n, k, i, j, prev_diff;
	cin>>T;
	while(T--){
		cin>>n>>k;
		int stock_price[n], dp[k+1][n];
		memset(dp, 0, sizeof(dp));
		for(i=0; i<n; i++)
			cin>>stock_price[i];
		for(i=1; i<=k; i++){
			prev_diff=INT_MIN;
			for(j=1; j<n; j++){
				prev_diff=max(prev_diff, dp[i-1][j-1]-stock_price[j-1]);
				dp[i][j]=max(dp[i][j-1], stock_price[j]+prev_diff);
			}
		}
		cout<<dp[k][n-1]<<"\n";
	}
	return 0;
}