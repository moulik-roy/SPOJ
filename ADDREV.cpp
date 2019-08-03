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
	int N, a, b, sum;
	cin>>N;
	while(N--){
		cin>>a>>b;
		sum=reverse(reverse(a)+reverse(b));
		cout<<sum<<"\n";
	}
	return 0;
}