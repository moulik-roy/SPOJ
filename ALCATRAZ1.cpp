#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, i, sum;
	string s;
	cin>>T;
	while(T--){
		cin>>s;
		for(i=0, sum=0; i<s.length(); i++)
			sum=sum+(s[i]-'0');
		cout<<sum<<"\n";
	}
	return 0;
}