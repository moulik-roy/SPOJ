#include <iostream>
#include <string>
using namespace std;

int main(){
	long long int T, X, i, L, K, fibonacci[90];
	string s;
	fibonacci[0]=1;
	fibonacci[1]=2;
	for(i=2; i<90; i++)
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
	cin>>T;
	for(X=1; X<=T; X++){
		cin>>s;
		L=s.length();
		for(i=0, K=0; i<L; i++){
			if(s[i]=='1')
				K=K+fibonacci[L-i-1];
		}
		cout<<"Case "<<X<<": "<<K<<"\n";
	}
	return 0;
}