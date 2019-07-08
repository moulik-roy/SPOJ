#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector <int> dijkstra(vector <pair<int, int>> graph[], int N, int src){
	int i, u, v, w;
	vector <int> dist(N+1, -1), visited(N+1, 0);
	priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair<int, int>>> q;
	dist[src]=0;
	q.push(make_pair(dist[src], src));
	while(!q.empty()){
		u=q.top().second;
		q.pop();
		visited[u]=1;
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			w=graph[u][i].second;
			if((dist[v]==-1 || dist[v]>dist[u]+w) && !visited[v]){
				dist[v]=dist[u]+w;
				q.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int main(){
	int N, E, T, M, a, b, t, i, count;
	cin>>N>>E>>T>>M;
	vector <pair<int, int>> graph[N+1];
	vector <int> dist;
	for(i=0; i<M; i++){
		cin>>a>>b>>t;
		graph[b].push_back(make_pair(a, t));
	}
	dist=dijkstra(graph, N, E);
	for(i=1, count=0; i<=N; i++){
		if(dist[i]!=-1 && dist[i]<=T)
			count++;
	}
	cout<<count<<"\n";
	return 0;
}