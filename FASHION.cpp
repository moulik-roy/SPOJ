#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t, N, i, max_sum;
	cin>>t;
	while(t--){
		cin>>N;
		int men_hotness[N], women_hotness[N];
		for(i=0; i<N; i++)
			cin>>men_hotness[i];
		for(i=0; i<N; i++)
			cin>>women_hotness[i];
		sort(men_hotness, men_hotness+N);
		sort(women_hotness, women_hotness+N);
		for(i=0, max_sum=0; i<N; i++)
			max_sum=max_sum+(men_hotness[i]*women_hotness[i]);
		cout<<max_sum<<"\n";
	}
	return 0;
}