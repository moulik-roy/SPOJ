#include <iostream>
#include <string>
using namespace std;

int main(){
	int t, N, i, j, count;
	string s;
	cin>>t;
	while(t--){
		cin>>N>>s;
		int dp[N];
		for(i=0; i<N; i++){
			count=(s[i]=='0')?-1:1;		dp[i]=0;
			for(j=i-1; j>=0; j--){
				if(count>0)
					dp[i]=max(dp[i], dp[j]+i-j);
				else
					dp[i]=max(dp[i], dp[j]);
				if(s[j]=='0')
					count--;
				else
					count++;
			}
			if(count>0)
				dp[i]=i+1;
		}
		cout<<dp[N-1]<<"\n";
	}
	return 0;
}