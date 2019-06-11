#include <iostream>
using namespace std;

int main(){
	int N, a, r;
	cin>>N;
	while(N--){
		cin>>a;
		if((a&1)==0){
			r=0;
			while(a>0){
				r=r<<1;
				r=r|(a&1);
				a=a>>1;
			}
			a=r;
		}
		cout<<a<<"\n";
	}
	return 0;
}