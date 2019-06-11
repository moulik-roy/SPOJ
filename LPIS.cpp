#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, i, d, max_length, hash[1000001]={0};
	cin>>n;
	int dp[n]={0};
	for(i=0; i<n; i++){
		cin>>d;
		dp[i]=1+hash[d-1];
		hash[d]=dp[i];
	}
	max_length=*max_element(dp, dp+n);
	cout<<max_length<<"\n";
	return 0;
}
