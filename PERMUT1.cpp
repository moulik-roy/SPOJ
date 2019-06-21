#include <iostream>
using namespace std;

int dp[14][100];

void count(){
	int i, j, k;
	for(i=0; i<=12; i++){
		for(j=0; j<=98; j++){
			if(i==0)
				dp[i][j]=0;
			else if(j==0)
				dp[i][j]=1;
			else{
				for(k=0, dp[i][j]=0; k<i && j-k>=0; k++)
					dp[i][j]+=dp[i-1][j-k];
			}
		}
	}
}

int main(){
	int d, n, k;
	count();
	cin>>d;
	while(d--){
		cin>>n>>k;
		cout<<dp[n][k]<<"\n";;
	}
	return 0;
}