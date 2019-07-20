#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
using namespace std;

vector <int> dijkstra(vector <pair<int, int>> graph[], int n, int src){
	int i, u, v, w;
	vector <int> dist(n+1, INT_MAX), visited(n+1, 0);
	priority_queue <pair <int, int>, vector <pair<int, int>>, greater <pair<int, int>>> q;
	dist[src]=0;
	q.push(make_pair(dist[src], src));
	while(!q.empty()){
		u=q.top().second;
		q.pop();
		visited[u]=1;
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			w=graph[u][i].second;
			if(dist[v]>dist[u]+w && !visited[v]){
				dist[v]=dist[u]+w;
				q.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}
	
int main(){
	int T, n, m, k, s, t, i, u, v, w, d;
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>s>>t;
		vector <pair<int, int>> graph[n+1], graph_inverse[n+1];
		vector <int> d1, d2;
		for(i=0; i<m; i++){
			cin>>u>>v>>w;
			graph[u].push_back(make_pair(v, w));
			graph_inverse[v].push_back(make_pair(u, w));
		}
		d1=dijkstra(graph, n, s);
		d2=dijkstra(graph_inverse, n, t);
		for(i=0, d=d1[t]; i<k; i++){
			cin>>u>>v>>w;
			if(d1[u]!=INT_MAX && d2[v]!=INT_MAX && d1[v]!=INT_MAX && d2[u]!=INT_MAX)
				d=min(d, w+min(d1[u]+d2[v], d1[v]+d2[u]));
		}
		if(d==INT_MAX)
			d=-1;
		cout<<d<<"\n";
	}
}