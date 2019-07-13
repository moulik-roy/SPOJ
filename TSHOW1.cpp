#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
	long int N, k, i, num_digits, rem;
	string amusing_number;
	cin>>N;
	while(N--){
		cin>>k;
		num_digits=ceil(log2(ceil(k/2.0)+1));
		k=k-(1L<<num_digits)+2;
		k=(k==0)?0:(k-1);
		amusing_number="";
		while(num_digits--){
			rem=k%2;
			if(rem==0)
				amusing_number="5"+amusing_number;
			else
				amusing_number="6"+amusing_number;
			k=k/2;
		}
		cout<<amusing_number<<"\n";
	}
	return 0;
}