#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T, t, N, S, i, sum;
	cin>>T;
	for(t=1; t<=T; t++){
		cin>>S>>N;
		int stamps[N];
		for(i=0, sum=0; i<N; i++){
			cin>>stamps[i];
			sum+=stamps[i];
		}
		cout<<"Scenario #"<<t<<":\n";
		if(sum<S)
			cout<<"impossible\n";
		else if(sum==S)
			cout<<N<<"\n";
		else{
			sort(stamps, stamps+N, greater<int>());
			for(i=0, sum=0; i<N && sum<S; i++)
				sum+=stamps[i];
			cout<<i<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}