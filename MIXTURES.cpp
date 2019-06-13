#include <iostream>
#include <cstring>
using namespace std;

int sum[100][100], dp[100][100];

int mixtures(int i, int j){
	if(i>=j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int k, temp;
	for(k=i; k<=j; k++){
		temp=mixtures(i, k)+mixtures(k+1, j)+(sum[i][k]*sum[k+1][j]);
		if(dp[i][j]==-1 || dp[i][j]>temp)
			dp[i][j]=temp;
	}
	return dp[i][j];
}

 int main(){
 	int n, i, j;
 	while(cin>>n){
 		int color[n];
 		memset(dp, -1, sizeof(dp));
 		for(i=0; i<n; i++)
 			cin>>color[i];
 		for(i=0; i<n; i++){
 			for(j=i+1, sum[i][i]=color[i]; j<n; j++)
 				sum[i][j]=(sum[i][j-1]+color[j])%100;
 		}
 		cout<<mixtures(0, n-1)<<"\n";
 	}
 	return 0;
 }