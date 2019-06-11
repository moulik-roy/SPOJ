#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long int N, i, sum;
	while(cin>>N && N!=0){
		long int C[N], P[N];
		for(i=0; i<N; i++)
			cin>>C[i];
		for(i=0; i<N; i++)
			cin>>P[i];
		sort(C, C+N);
		sort(P, P+N, greater<long int>());
		for(i=0, sum=0; i<N; i++)
			sum=sum+(C[i]*P[i]);
		cout<<sum<<"\n";
	}
	return 0;
}