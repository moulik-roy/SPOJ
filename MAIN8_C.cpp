#include <iostream>
using namespace std;

bool distributeCandies(int candies[], int n, int candies_person, int K){
	int i, c;
	for(i=0, c=0; i<n; i++)
		c+=(candies[i]/candies_person);
	if(c<K)
		return false;
	else
		return true;
}

int main(){
	int T, N, K, i, max_candies, low, high, mid;
	cin>>T;
	while(T--){
		cin>>N>>K;
		int candies[N];
		for(i=0, max_candies=0; i<N; i++){
			cin>>candies[i];
			max_candies=max(max_candies, candies[i]);
		}
		low=0;	high=max_candies;
		while(low<high){
			mid=low+(high-low+1)/2;
			if(distributeCandies(candies, N, mid, K))
				low=mid;
			else
				high=mid-1;
		}
		cout<<low<<"\n";
	}
	return 0;
}