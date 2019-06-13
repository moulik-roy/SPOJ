#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t, m, n, i, j, vertical_pieces, horizontal_pieces, min_cost;
	cin>>t;
	while(t--){
		cin>>m>>n;
		int x[m-1], y[n-1];
		for(i=0; i<m-1; i++)
			cin>>x[i];
		for(i=0; i<n-1; i++)
			cin>>y[i];
		sort(x, x+m-1, greater<int>());
		sort(y, y+n-1, greater<int>());
		i=0;	j=0;	vertical_pieces=1;	horizontal_pieces=1;	min_cost=0;
		while(i<m-1 && j<n-1){
			if(x[i]>y[j]){
				min_cost+=(x[i++]*horizontal_pieces);
				vertical_pieces++;
			}
			else{
				min_cost+=(y[j++]*vertical_pieces);
				horizontal_pieces++;
			}
		}
		while(i<m-1)
			min_cost+=(x[i++]*horizontal_pieces);
		while(j<n-1)
			min_cost+=(y[j++]*vertical_pieces);
		cout<<min_cost<<"\n";
	}
	return 0;
}