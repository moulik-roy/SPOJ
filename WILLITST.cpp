#include <iostream>
using namespace std;

int main(){
	long long int n;
	cin>>n;
	if((n&(n-1))==0)
		cout<<"TAK\n";
	else
		cout<<"NIE\n"; 
	return 0;
}