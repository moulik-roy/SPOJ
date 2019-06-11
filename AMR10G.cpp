#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long int T, N, K, i, min_difference;
	cin>>T;
	while(T--){
		cin>>N>>K;
		long int height[N];
		for(i=0; i<N; i++)
			cin>>height[i];
		if(K==1)
			min_difference=0;
		else{
			sort(height, height+N);
			min_difference=height[K-1]-height[0];
			for(i=K; i<N; i++)
				min_difference=min(min_difference, height[i]-height[i-K+1]);
		}
		cout<<min_difference<<"\n";
	}
	return 0;
}