#include <iostream>
using namespace std;

int main(){
	long int T, N, count;
	cin>>T;
	while(T--){
		cin>>N;
		count=(N*(N+2)*(2*N+1))/8;
		cout<<count<<"\n";
	}
	return 0;
}