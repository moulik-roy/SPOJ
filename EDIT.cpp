#include <iostream>
#include <string>
using namespace std;

int main(){
	int i, c1, c2;
	string s;
	while(cin>>s){
		for(i=0, c1=0, c2=0; i<s.length(); i++){
			if(i%2==0){
				if(s[i]>='A' && s[i]<='Z')
					c1++;
				else
					c2++;
			}
			else{
				if(s[i]>='A' && s[i]<='Z')
					c2++;
				else
					c1++;
			}
		}
		cout<<min(c1, c2)<<"\n";
	}
	return 0;
}
