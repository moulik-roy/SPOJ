#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
	long long int n, i;
	string s;
	while(cin>>s && s[0]!='0'){
		n=s.length();
		long long int dp[n+1];
		memset(dp, 0, sizeof(dp));
		dp[0]=1;	dp[1]=1;
		for(i=2; i<=n; i++){
			if(s[i-1]>'0')
				dp[i]=dp[i-1];
			if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7'))
				dp[i]+=dp[i-2];
		}
		cout<<dp[n]<<"\n";
	}
	return 0;
}