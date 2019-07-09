#include <iostream>
#include <string>
using namespace std;

int main(){
	int i, j, min_cost;
	string S, T;
	while(cin>>S && S.compare("#")!=0){
		cin>>T;
		int lcs[S.length()+1][T.length()+1];
		for(i=0; i<=S.length(); i++){
			for(j=0; j<=T.length(); j++){
				if(i==0 || j==0)
					lcs[i][j]=0;
				else if(S[i-1]==T[j-1])
					lcs[i][j]=lcs[i-1][j-1]+1;
				else
					lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
		min_cost=15*(S.length()-lcs[S.length()][T.length()])+30*(T.length()-lcs[S.length()][T.length()]);
		cout<<min_cost<<"\n";
	}
	return 0;
}