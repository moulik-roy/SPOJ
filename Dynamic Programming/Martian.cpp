#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, i, j, y, b;
	while(cin>>n>>m && n+m!=0){
		int Y[n][m], B[n][m], dp[n][m];
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				cin>>Y[i][j];
				if(j>0)
					Y[i][j]+=Y[i][j-1];
			}
		}
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				cin>>B[i][j];
				if(i>0)
					B[i][j]+=B[i-1][j];
			}
		}
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				y=Y[i][j];
				b=B[i][j];
				if(i>0)
					y+=dp[i-1][j];
				if(j>0)
					b+=dp[i][j-1];
				dp[i][j]=max(y, b);
			}
		}
		cout<<dp[n-1][m-1]<<"\n";
	}
	return 0;
}
