#include <iostream>
using namespace std;

int main(){
	long int T, N, count;
	cin>>T;
	while(T--){
		cin>>N;
		if(N%2==0)
			count=(N*(N+2)*(2*N+1))/8;
		else
			count=(N*(N+2)*(2*N+1)-1)/8;
		cout<<count<<"\n";
	}
	return 0;
}