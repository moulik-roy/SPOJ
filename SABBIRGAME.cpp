#include <iostream>
using namespace std;

int main(){
	long int T, n, i, sum, min_life_point;
	cin>>T;
	while(T--){
		cin>>n;
		long int a[n];
		for(i=0; i<n; i++)
			cin>>a[i];
		for(i=0, sum=0, min_life_point=1; i<n; i++){
			sum+=a[i];
			min_life_point=min(min_life_point, sum);
		}
		if(min_life_point>0)
			min_life_point=0;
		else
			min_life_point=-min_life_point+1;
		cout<<min_life_point<<"\n";
	}
}