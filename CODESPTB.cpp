#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void update(int BIT[], int N, int index, int val){
	while(index<=N){
		BIT[index]+=val;
		index=index+(index & (-index));
	}
}

int get_sum(int BIT[], int index){
	int sum=0;
	while(index>0){
		sum+=BIT[index];
		index=index-(index & (-index));
	}
	return sum;
}

int main(){
	int T, N, i, position, count;
	cin>>T;
	while(T--){
		cin>>N;
		int a[N], sorted[N], BIT[N+1];
		memset(BIT, 0, sizeof(BIT));
		for(i=0; i<N; i++){
			cin>>a[i];
			sorted[i]=a[i];
		}
		sort(sorted, sorted+N);
		for(i=0, count=0; i<N; i++){
			position=lower_bound(sorted, sorted+N, a[i])-sorted;
			count=count+get_sum(BIT, N)-get_sum(BIT, position+1);
			update(BIT, N, position+1, 1);
		}
		cout<<count<<"\n";
	} 
	return 0;
}