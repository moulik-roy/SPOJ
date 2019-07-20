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
	int T, n, m, k, s, t, i, d, c, l, u, v, q, min_dist;
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>s>>t;
		vector <pair<int, int>> graph[n+1], graph_inverse[n+1];
		vector <int> dist_s, dist_t;
		for(i=0; i<m; i++){
			cin>>d>>c>>l;
			graph[d].push_back(make_pair(c, l));
			graph_inverse[c].push_back(make_pair(d, l));
		}
		dist_s=dijkstra(graph, n, s);
		dist_t=dijkstra(graph_inverse, n, t);
		for(i=0, min_dist=dist_s[t]; i<k; i++){
			cin>>u>>v>>q;
			if(dist_s[u]!=INT_MAX && dist_t[v]!=INT_MAX)
				min_dist=min(min_dist, dist_s[u]+dist_t[v]+q);
			if(dist_s[v]!=INT_MAX && dist_t[u]!=INT_MAX)
				min_dist=min(min_dist, dist_s[v]+dist_t[u]+q);
		}
		if(min_dist==INT_MAX)
			min_dist=-1;
		cout<<min_dist<<"\n";
	}
}