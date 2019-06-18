#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int x, k, i, j;
	cin>>x>>k;
	int v[k], dp[x+1];
	memset(dp, 0, sizeof(dp));
	for(i=0; i<k; i++){
		cin>>v[i];
		if(i>0)
			v[i]+=v[i-1];
	}
	for(i=0, dp[0]=1; i<k; i++){
		for(j=v[i]; j<=x; j++)
			dp[j]=dp[j]|dp[j-v[i]];
	}
	if(dp[x]==1)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}