#include <iostream>
using namespace std;

int main(){
	int T, h, w, i, j, m, max_stones;
	cin>>T;
	while(T--){
		cin>>h>>w;
		int dp[h][w];
		for(i=0; i<h; i++){
			for(j=0; j<w; j++){
				cin>>m;
				dp[i][j]=m;
			}
		}
		for(i=h-2; i>=0; i--){
			for(j=0; j<w; j++){
				if(j==0)
					m=max(dp[i+1][j], dp[i+1][j+1]);
				else if(j==w-1)
					m=max(dp[i+1][j-1], dp[i+1][j]);
				else
					m=max(dp[i+1][j-1], max(dp[i+1][j], dp[i+1][j+1]));
				dp[i][j]=dp[i][j]+m;
			}
		}
		for(i=0, max_stones=0; i<w; i++){
			if(max_stones<dp[0][i])
				max_stones=dp[0][i];
		}
		cout<<max_stones<<"\n";
	}
	return 0;
}