#include <iostream>
using namespace std;

int main(){
    int budget, n, i, j, max_fun, sum_entry_fee;
    while(cin>>budget>>n && budget+n!=0){
    	int party_cost[n], party_fun[n], dp[n+1][budget+1];
    	for(i=0; i<n; i++)
    		cin>>party_cost[i]>>party_fun[i];
    	for(i=0; i<=n; i++){
    		for(j=0; j<=budget; j++){
    			if(i==0 || j==0)
    				dp[i][j]=0;
    			else if(party_cost[i-1]<=j)
    				dp[i][j]=max(dp[i-1][j], dp[i-1][j-party_cost[i-1]]+party_fun[i-1]);
    			else
    				dp[i][j]=dp[i-1][j];
    		}
    	}
    	for(i=0; i<=budget; i++){
    		if(dp[n][i]==dp[n][budget])
    			break;
    	}
    	cout<<i<<" "<<dp[n][budget]<<"\n";
    }
    return 0;
}
