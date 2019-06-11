#include <iostream>
using namespace std;

int lastDigit(long int a, long int b){
	if(b==0)
		return 1;
	int d=a%10;
	if(d==0 || d==1 || d==5 || d==6 || b==1)
		return d;
	d=lastDigit(a, b/2);
	d=(d*d)%10;
	if((b&1L)==1)
		d=(d*(a%10))%10;
	return d;
}

int main(){
	long int t, a, b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<lastDigit(a, b)<<"\n";
	}
	return 0;
}
