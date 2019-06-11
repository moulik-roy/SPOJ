#include <iostream>
using namespace std;

int reverse(int n){
	int r=0;
	while(n!=0){
		r=(r*10)+(n%10);
		n=n/10;
	}
	return r;
}

int main(){
	int t, a, b, sum;
	cin>>t;
	while(t--){
		cin>>a>>b;
		sum=reverse(reverse(a)+reverse(b));
		cout<<sum<<"\n";
	}
	return 0;
}