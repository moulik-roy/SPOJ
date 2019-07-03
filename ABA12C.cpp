#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T, N, K, i, j;
	cin>>T;
	while(T--){
		cin>>N>>K;
		vector <int> price(K), dp(K+1, -1);
		for(i=0; i<K; i++)
			cin>>price[i];
		dp[0]=0;
		for(i=1; i<=K; i++){
			for(j=1; j<=i; j++){
				if(price[j-1]!=-1 && dp[i-j]!=-1){
					if(dp[i]==-1)
						dp[i]=dp[i-j]+price[j-1];
					else
						dp[i]=min(dp[i], dp[i-j]+price[j-1]);
				}
			}
		}
		cout<<dp[K]<<"\n";
	}
	return 0;
}
