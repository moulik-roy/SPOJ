#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

int main(){
	int t, n, i, k, pos, min_value, sum, cost1, cost2, min_cost;
	t=1;
	while(cin>>n && n!=0){
		int arr[n], arr_sorted[n], visited[n];
		memset(visited, 0, sizeof(visited));
		unordered_map <int, int> position;
		for(i=0; i<n; i++){
			cin>>arr[i];
			arr_sorted[i]=arr[i];
		}
		sort(arr_sorted, arr_sorted+n);
		for(i=0; i<n; i++)
			position[arr_sorted[i]]=i;
		for(i=0, min_cost=0; i<n; i++){
			if(!visited[i]){
				if(position[arr[i]]==i){
					visited[i]=1;
					continue;
				}
				for(k=0, pos=i, min_value=arr[i], sum=0; !visited[pos]; k++){
					visited[pos]=1;
					pos=position[arr[pos]];
					sum+=arr[pos];
					min_value=min(min_value, arr[pos]);
				}
				cost1=(sum-min_value)+(k-1)*min_value;
				cost2=2*(min_value+arr_sorted[0])+(sum-min_value)+(k-1)*arr_sorted[0];
				min_cost+=min(cost1, cost2);
			}
		}
		cout<<"Case "<<t++<<": "<<min_cost<<"\n\n";
	}
	return 0;
}