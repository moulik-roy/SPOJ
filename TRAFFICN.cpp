#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
using namespace std;

vector <long int> dijkstra(vector <pair<long int, long int>> graph[], long int n, long int src){
	long int i, u, v, w;
	vector <long int> dist(n+1, LONG_MAX), visited(n+1, 0);
	priority_queue <pair <long int, long int>, vector <pair<long int, long int>>, greater <pair<long int, long int>>> q;
	dist[src]=0;
	q.push(make_pair(dist[src], src));
	while(!q.empty()){
		u=q.top().second;
		visited[u]=1;
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			w=graph[u][i].second;
			if((dist[v]==LONG_MAX || dist[v]>dist[u]+w) && !visited[v]){
				dist[v]=dist[u]+w;
				q.push(make_pair(dist[v], v));
			}
		}
		q.pop();
	}
	return dist;
}
	
int main(){
	long int T, n, m, k, s, t, i, u, v, w, d;
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>s>>t;
		vector <pair<long int, long int>> graph[n+1], graph_inverse[n+1];
		vector <long int> d1, d2;
		for(i=0; i<m; i++){
			cin>>u>>v>>w;
			graph[u].push_back(make_pair(v, w));
			graph_inverse[v].push_back(make_pair(u, w));
		}
		d1=dijkstra(graph, n, s);
		d2=dijkstra(graph_inverse, n, t);
		for(i=0, d=d1[t]; i<k; i++){
			cin>>u>>v>>w;
			if(d1[u]!=LONG_MAX && d2[v]!=LONG_MAX && d1[v]!=LONG_MAX && d2[u]!=LONG_MAX)
				d=min(d, w+min(d1[u]+d2[v], d1[v]+d2[u]));
		}
		if(d==LONG_MAX)
			d=-1;
		cout<<d<<"\n";
	}
}