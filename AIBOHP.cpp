#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
	int t, n, i, j, gap;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		n=s.length();
		int dp[n][n];
		memset(dp, 0, sizeof(dp));
		for(gap=1; gap<n; gap++){
			for(i=0, j=gap; j<n; i++, j++){
				if(s[i]==s[j])
					dp[i][j]=dp[i+1][j-1];
				else
					dp[i][j]=1+min(dp[i+1][j], dp[i][j-1]);
			}
		}
		cout<<dp[0][n-1]<<"\n";
	}
	return 0;
}
