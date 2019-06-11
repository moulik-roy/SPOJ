#include <iostream>
using namespace std;

int main(){
	int T, E, F, N, i, w, W;
	cin>>T;
	while(T--){
		cin>>E>>F;
		W=F-E;
		cin>>N;
		int value[N], weight[N], dp[W+1];
		for(i=0; i<N; i++)
			cin>>value[i]>>weight[i];
		dp[0]=0;
		for(w=1; w<=W; w++){
			dp[w]=-1;
			for(i=0; i<N; i++){
				if(weight[i]<=w && dp[w-weight[i]]!=-1 && (dp[w]==-1 || dp[w]>dp[w-weight[i]]+value[i]))
					dp[w]=dp[w-weight[i]]+value[i];
			}
		}
		if(dp[W]==-1)
			cout<<"This is impossible.\n";
		else
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<".\n";
	}
	return 0;
}
