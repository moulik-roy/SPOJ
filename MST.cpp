#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

long int PrimsMST(vector <pair<long int, long int>> graph[], long int N){
	long int i, u, v, w, mst_cost;
	vector <long int> dist(N+1, -1), visited(N+1, 0);
	priority_queue <pair <long int, long int>, vector <pair<long int, long int>>, greater <pair<long int, long int>>> q;
	dist[1]=0;
	q.push(make_pair(dist[1], 1));
	while(!q.empty()){
		u=q.top().second;
		visited[u]=1;
		q.pop();
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			w=graph[u][i].second;
			if((dist[v]==-1 || dist[v]>w) && !visited[v]){
				dist[v]=w;
				q.push(make_pair(dist[v], v));
			}
		}
	}
	for(i=1, mst_cost=0; i<=N; i++)
		mst_cost+=dist[i];
	return mst_cost;
}

int main(){
	long int N, M, i, j, k, mst_cost;
	cin>>N>>M;
	vector <pair<long int, long int>> graph[N+1];
	while(M--){
		cin>>i>>j>>k;
		graph[i].push_back(make_pair(j, k));
		graph[j].push_back(make_pair(i, k));
	}
	mst_cost=PrimsMST(graph, N);
	cout<<mst_cost<<"\n";
	return 0;
}