#include <iostream>
#include <string>
using namespace std;

int main(){
	int N, i, j;
	string S;
	while(cin>>S && S.compare("*")!=0){
		int lps[S.length()];
		lps[0]=0;	i=1;	   j=0;
		while(i<S.length()){
			if(S[i]==S[j]){
				lps[i]=j+1;
				i++;
				j++;
			}
			else{
				if(j!=0)
					j=lps[j-1];
				else{
					lps[i]=0;
					i++;
				}
			}
		}
		if(S.length()%(S.length()-lps[S.length()-1])==0)
			N=S.length()/(S.length()-lps[S.length()-1]);
		else
			N=1;
		cout<<N<<"\n";
	}
	return 0;
}