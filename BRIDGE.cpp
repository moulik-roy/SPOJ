#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	int t, n, i, j, max_bridges;
	cin>>t;
	while(t--){
		cin>>n;
		pair <int, int> bridge[n];
		int dp[n];
		for(i=0; i<n; i++)
			cin>>bridge[i].first;
		for(i=0; i<n; i++)
			cin>>bridge[i].second;
		sort(bridge, bridge+n);
		for(i=0, max_bridges=0; i<n; i++){
			dp[i]=1;
			for(j=0; j<i; j++){
				if(bridge[j].second<=bridge[i].second)
					dp[i]=max(dp[i], dp[j]+1);
			}
			max_bridges=max(max_bridges, dp[i]);
		}
		cout<<max_bridges<<"\n";
	}
	return 0;
}
