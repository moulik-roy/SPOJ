#include <iostream>
#include <string>
using namespace std;

int main(){
	int k, N, i, c;
	string s;
	k=1;
	while(cin>>s && s[0]!='-'){
		for(i=0, c=0, N=0; i<s.length(); i++){
			if(s[i]=='{')
				c++;
			else if(s[i]=='}' && c>0)
				c--;
			else{
				c++;
				N++;
			}
		}
		N=N+(c/2);
		cout<<k++<<". "<<N<<"\n";
	}
	return 0;
}
