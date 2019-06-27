#include <iostream>
#include <string>
using namespace std;

int main(){
	int K, N, i, j;
	string S;
	while(cin>>K>>S && K!=-1 && S.compare("*")!=0){
		N=S.length();
		if(K<N)
			cout<<"0\n";
		else if(K==N)
			cout<<"1\n";
		else{
			int lps[N];
			lps[0]=0;	i=1;	j=0;
			while(i<N){
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
			cout<<1+(K-N)/(N-lps[N-1])<<"\n";
		}
	}
	return 0;
}