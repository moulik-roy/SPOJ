#include <iostream>
#include <string>
using namespace std;

int main(){
	int T, t, N, i, j, K;
	string S;
	cin>>T;
	for(t=1; t<=T; t++){
		cin>>N>>S;
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
		cout<<"Test case #"<<t<<"\n";
		for(i=1; i<N; i++){
			if(lps[i]>0 && (i+1)%(i+1-lps[i])==0){
				K=(i+1)/(i+1-lps[i]);
				cout<<i+1<<" "<<K<<"\n";
			}
		}
		cout<<"\n";
	}
	return 0;
}