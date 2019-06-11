#include <iostream>
#include <algorithm>
#define MOD 1000000000
using namespace std;

long int find(long int parent[], int i){
	if(parent[i]!=i)
		parent[i]=find(parent, parent[i]);
	return parent[i];
}

int main(){
	long int N, M, i, u, v, cost;
	cin>>N>>M;
	long int parent[N+1], count[N+1], sum[M];
	pair <long int, pair<long int, long int>> edges[M];
	for(i=1; i<=N; i++){
		parent[i]=i;
		count[i]=1;
	}
	for(i=0; i<M; i++)
		cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
	sort(edges, edges+M);
	for(i=1, sum[0]=edges[0].first; i<M; i++)
		sum[i]=sum[i-1]+edges[i].first;
	for(i=M-1, cost=0; i>=0; i--){
		u=find(parent, edges[i].second.first);
		v=find(parent, edges[i].second.second);
		if(u!=v){
			cost=(cost+(count[u]*count[v]*sum[i]))%MOD;
			parent[u]=v;
			count[v]+=count[u];
		}
	}
	cout<<cost<<"\n";
	return 0;
}