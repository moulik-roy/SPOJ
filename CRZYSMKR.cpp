#include <iostream>
using namespace std;

int main() {
	long long int T, N, M, r;
	cin>>T;
	while(T--){
		cin>>N;
		r=(8*(N%11))%11;
		M=(r==0)?r:(11-r);
		cout<<M<<"\n";
	}
	return 0;
}