#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	string s;
	int n, x, y, z, p, winner;
	while(cin>>s && s.compare("00e0")!=0){
		x=s[0]-'0';
		y=s[1]-'0';
		z=s[3]-'0';
		n=10*x+y;
		while(z--)
			n=n*10;
		p=(int)log2(n);
		winner=2*(n-(1<<p))+1;
		cout<<winner<<"\n";
	}
	return 0;
}
