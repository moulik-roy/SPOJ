#include <iostream>
using namespace std;

int main(){
	int N, M, i, start, sum, max_sum;
	cin>>N>>M;
	int hotel_value[N];
	for(i=0; i<N; i++)
		cin>>hotel_value[i];
	for(i=0, start=0, sum=0, max_sum=0; i<N; i++){
		sum+=hotel_value[i];
		while(sum>M && start<=i)
			sum-=hotel_value[start++];
		max_sum=max(max_sum, sum);
	}
	cout<<max_sum<<"\n";
	return 0;
}