#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;

void update(long int BIT[], long int N, long int index, long int val){
	while(index<=N){
		BIT[index]+=val;
		index=index+(index & (-index));
	}
}

long int get_sum(long int BIT[], long int index){
	long int sum=0;
	while(index>0){
		sum+=BIT[index];
		index=index-(index & (-index));
	}
	return sum;
}

int main(){
	long int T, t, N, M, K, i, no_crossings;
	cin>>T;
	for(t=1; t<=T; t++){
		cin>>N>>M>>K;
		pair <long int, long int> superhighways[K];
		long int BIT[M+1];
		memset(BIT, 0, sizeof(BIT));
		for(i=0; i<K; i++)
			cin>>superhighways[i].first>>superhighways[i].second;
		sort(superhighways, superhighways+K, greater<pair<long int, long int>>());
		for(i=0, no_crossings=0; i<K; i++){
			no_crossings+=get_sum(BIT, superhighways[i].second-1);
			update(BIT, M, superhighways[i].second, 1);
		}
		cout<<"Test case "<<t<<": "<<no_crossings<<"\n";
	}
	return 0;
}
