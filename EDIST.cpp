#include <iostream>
#include <string>
using namespace std;

int main(){
	int T, i, j;
	string A, B;
	cin>>T;
	while(T--){
		cin>>A>>B;
		int dp[A.length()+1][B.length()+1];
		for(i=0; i<=A.length(); i++){
			for(j=0; j<=B.length(); j++){
				if(i==0)
					dp[i][j]=j;
				else if(j==0)
					dp[i][j]=i;
				else if(A[i-1]==B[j-1])
					dp[i][j]=dp[i-1][j-1];
				else
					dp[i][j]=1+min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
			}
		}
		cout<<dp[A.length()][B.length()]<<"\n";
	}
	return 0;
}