#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int t, N, C, i, low, high, mid, prev, cows;
	cin>>t;
	while(t--){
		cin>>N>>C;
		vector <int> x(N, 0);
		for(int i=0; i<N; i++)
			cin>>x[i];
		sort(x.begin(), x.end());
		low=1;		high=x[N-1]-x[0];
		while(low<high){
			mid=low+(high-low+1)/2;
			for(i=1, prev=x[0], cows=1; i<N && cows<C; i++){
				if(x[i]-prev>=mid){
					cows++;
					prev=x[i];
				}
			}
			if(cows>=C)
				low=mid;
			else
				high=mid-1;
		}
		cout<<low<<"\n";
	}
	return 0;
}