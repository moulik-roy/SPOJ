#include <iostream>
using namespace std;

int main(){
	long long int t, k, n;
	cin>>t;
	while(t--){
		cin>>k;
		n=192+(k-1)*250;
		cout<<n<<"\n";
	}
	return 0;
}