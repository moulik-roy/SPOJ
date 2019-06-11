#include <iostream>
#include <string>
using namespace std;

int main(){
	int t, n;
	string s[6]={"Anjan", "Sufian", "Alim", "Shipu", "Sohel", "Sumon"};
	t=1;
	while(cin>>n && n!=0){
		n=(n-1)%6;
		cout<<"Case "<<t++<<": "<<s[n]<<"\n";
	}
	return 0;
}
