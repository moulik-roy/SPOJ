#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int dijkstra(vector <pair<int, int>> graph[], int N, int set[]){
	int i, u, v, w;
	vector <int> dist(N, -1), visited(N, 0);
	priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair<int, int>>> q; 
	for(i=0; i<N; i++){
		if(set[i]==1){
			dist[i]=0;
			q.push(make_pair(dist[i], i));
		}
	}
	while(!q.empty()){
		u=q.top().second;
		visited[u]=1;
		q.pop();
		if(set[u]==0)
			return dist[u];
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			w=graph[u][i].second;
			if((dist[v]==-1 ||dist[v]>dist[u]+w) && !visited[v]){
				dist[v]=dist[u]+w;
				q.push(make_pair(dist[v], v));
			}
		}
	}
	return -1;
}

int main(){
	int N, M, A, B, i, u, v, d;
	while(cin>>N>>M>>A>>B && N+M+A+B!=0){
		vector <pair<int, int>> graph[N];
		int set[N];
		memset(set, -1, sizeof(set));
		for(i=0; i<A; i++){
			cin>>u;
			set[u]=1;
		}
		for(i=0; i<B; i++){
			cin>>u;
			set[u]=0;
		}
		for(i=0; i<M; i++){
			cin>>u>>v>>d;
			graph[u].push_back(make_pair(v, d));
			graph[v].push_back(make_pair(u, d));
		}
		cout<<dijkstra(graph, N, set)<<"\n";
	}
	return 0;
}