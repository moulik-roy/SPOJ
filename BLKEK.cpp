#include <iostream>
#include <string>
using namespace std;

int main(){
	int t, n, m, i, j;
	string s, sub="KEK";
	m=sub.length();
	cin>>t;
	while(t--){
		cin>>s;
		n=s.length();
		int dp[n+1][m+1]={0};
		for(i=0; i<=n; i++){
			for(j=0; j<=m; j++){
				if(j==0)
					dp[i][j]=1;
				else if(i==0)
					dp[i][j]=0;
				else if(s[i-1]==sub[j-1])
					dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		cout<<dp[n][m]<<"\n";
	}
	return 0;
}
