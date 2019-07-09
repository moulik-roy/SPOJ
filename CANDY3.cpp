#include <iostream>
using namespace std;

int main(){
	long int T, N, i, candies, sum;
	cin>>T;
	while(T--){
		cin>>N;
		for(i=0, sum=0; i<N; i++){
			cin>>candies;
			sum=(sum+candies)%N;
		}
		if(sum%N==0)
		    cout<<"YES\n";
		else
		    cout<<"NO\n";
	}
	return 0;
}
