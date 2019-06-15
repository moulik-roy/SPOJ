#include <iostream>
#include <cstring>
#define MOD 1000000
using namespace std;

int dp[1001][1001];

void Catalan(){
	int i, j;
	for(i=0; i<=1000; i++){
		for(j=0; j<=i; j++){
			if(j==0)
				dp[i][j]=1;
			else
				dp[i][j]=(dp[i][j-1]+dp[i-1][j])%MOD;
		}
	}
}

int main(){
	int N;
	memset(dp, 0, sizeof(dp));
	Catalan();
	while(cin>>N && N!=0)
		cout<<dp[N][N]<<"\n";
	return 0;
}