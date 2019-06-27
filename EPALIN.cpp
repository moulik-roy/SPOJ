#include <iostream>
#include <string>
using namespace std;

int KMP(string S){
	int i, j, lps[S.length()];
	lps[0]=0;	i=1;	j=0;
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
	return lps[S.length()-1];
}

int main(){
	int N, i;
	string S, reverse;
	while(cin>>S){
		N=S.length();
		reverse="";
		for(i=N-1; i>=0; i--)
			reverse+=S[i];
		if(reverse.compare(S)!=0){
			for(i=N-KMP(reverse+"#"+S)-1; i>=0; i--)
				S+=S[i];
		}
		cout<<S<<"\n";
	}
	return 0;
}