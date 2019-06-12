#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;

vector <int> dijkstra(vector <pair<int, int>> graph[], int n, int s){
	int i, u, v, w;
	vector <int> dist(n+1, -1), visited(n+1, 0);
	priority_queue <pair <int, int>, vector <pair<int, int>>, greater <pair<int, int>>> q;
	dist[s]=0;
	q.push(make_pair(dist[s], s));
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
	int t, n, i, p, u, w;
	string s, d;
	cin>>t;
	while(t--){
		cin>>n;
		vector <pair<int, int>> graph[n+1];
		map <string, int> city;
		vector <int> dist;
		for(i=1; i<=n; i++){
			cin>>s;
			city.insert(make_pair(s, i));
			cin>>p;
			while(p--){
				cin>>u>>w;
				graph[i].push_back(make_pair(u, w));
			}
		}
		cin>>p;
		while(p--){
			cin>>s>>d;
			dist=dijkstra(graph, n, city[s]);
			cout<<dist[city[d]]<<"\n";
		}	
	}
	return 0;
}
