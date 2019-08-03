#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int N, i, C, R, max_length;
	string S, T;
	cin>>N>>T;
	S="@#";
	for(i=0; i<N; i++){
		S+=T[i];
		S+="#";
	}
	S+="$";
	vector <int> lps(S.length(), 0);
	for(i=1, C=0, R=0, max_length=0; i<S.length()-1; i++){
		if(i<R)
			lps[i]=min(R-i, lps[2*C-i]);
		while(S[i+lps[i]+1]==S[i-(lps[i]+1)])
			lps[i]++;
		if(i+lps[i]>R){
			C=i;
			R=i+lps[i];
		}
		max_length=max(max_length, lps[i]);
	}
	cout<<max_length<<"\n";
	return 0;
}