#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector <int> dijkstra(vector <pair<int, int>> graph[], int V, int src){
	int i, u, v, w;
	vector <int> dist(V+1, -1), visited(V+1, 0);
	priority_queue <pair <int, int>, vector <pair<int, int>>, greater <pair<int, int>>> q;
	dist[src]=0;
	q.push(make_pair(dist[src], src));
	while(!q.empty()){
		u=q.top().second;
		visited[u]=1;
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
	return dist;
}

int main(){
	int T, V, K, i, a, b, c, A, B;
	cin>>T;
	while(T--){
		cin>>V>>K;
		vector <pair<int, int>> graph[V+1];
		vector <int> dist;
		for(i=0; i<K; i++){
			cin>>a>>b>>c;
			graph[a].push_back(make_pair(b, c));
		}
		cin>>A>>B;
		dist=dijkstra(graph, V, A);
		if(dist[B]==-1)
			cout<<"NO\n";
		else
			cout<<dist[B]<<"\n";
	}
	return 0;
}