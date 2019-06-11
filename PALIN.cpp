#include <iostream>
#include <string>
using namespace std;
 
int main(){
	int t, n, i, j, c;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		n=s.length();
		for(i=0, c=0; i<n; i++){
			if(s[i]=='9')
				c++;
		}
		if(c==n){
			s="1";
			for(i=1; i<c; i++)
				s+="0";
			s+="1";
		}
		else{
			i=(n-1)/2;	j=n/2;
			while(i>=0 && j<n && s[i]==s[j]){
				i--;
				j++;
			}
			if(i<0 || s[i]<s[j]){
				c=1;
				i=(n-1)/2;
				while(c>0){
					j=s[i]-'0';
					j=j+c;
					c=j/10;
					j=j%10;
					s[i--]=(char)(j+'0');
				}
				
			}
			i=(n-1)/2;	j=n/2;
			while(i>=0 && j<n)
				s[j++]=s[i--];
		}
		cout<<s<<"\n";
	}
	return 0;
}