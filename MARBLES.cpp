#include <iostream>
using namespace std;

int main(){
	long long int T, n, k, i, count;
	cin>>T;
	while(T--){
		cin>>n>>k;
		k=min(k-1, n-k);
		for(i=1, count=1; i<=k; i++)
			count=count*(n-i)/i;
		cout<<count<<"\n";
	}
	return 0;
}