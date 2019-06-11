#include <iostream>
#include <string>
using namespace std;

int main(){
	int T, n, i, flag;
	string s;
	cin>>T;
	while(T--){
		cin>>s;
		n=s.length();
		for(i=0, flag=0; i<n/2; i++){
			if(s[i]!=s[n-i-1]){
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}