#include <iostream>
using namespace std;

int main(){
	long int T, N, i, Z;
	cin>>T;
	while(T--){
		cin>>N;
		for(i=5, Z=0; N/i>0; i*=5)
			Z=Z+(N/i);
		cout<<Z<<"\n";
	}
	return 0;
}