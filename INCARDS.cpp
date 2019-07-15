#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

long int dijkstra(vector <pair<long int, long int>> graph[], long int V){
	long int i, u, v, w, sum_cost;
	vector <long int> dist(V+1, -1);
	priority_queue <pair <long int, long int>, vector <pair<long int, long int>>, greater <pair<long int, long int>>> q;
	bool visited[V+1];
	memset(visited, false, sizeof(visited));
	dist[1]=0;
	q.push(make_pair(0, 1));
	while(!q.empty()){
		u=q.top().second;
		visited[u]=true;
		q.pop();
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			w=graph[u][i].second;
			if((dist[v]==-1 || dist[v]>dist[u]+w) && !visited[v]){
				dist[v]=dist[u]+w;
				q.push(make_pair(dist[v], v));
			}
		}
	}
	for(i=1, sum_cost=0; i<=V; i++)
		sum_cost+=dist[i];
	return sum_cost;
}

int main(){
	long int N, P, Q, i, u, v, w, min_amount;
	cin>>N;
	while(N--){
		cin>>P>>Q;
		vector <pair<long int, long int>> graph[P+1], graph_inv[P+1];
		for(i=0; i<Q; i++){
			cin>>u>>v>>w;
			graph[u].push_back(make_pair(v, w));
			graph_inv[v].push_back(make_pair(u, w));
		}
		min_amount=dijkstra(graph, P)+dijkstra(graph_inv, P);
		cout<<min_amount<<"\n";
	}
	return 0;
}
