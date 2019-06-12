#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
using namespace std;

set <pair<int, int>> shortestPathEdges;

int dijkstraShortesPath(vector <pair<int, int>> graph[], int N, int src, int dest){
	int i, j, u, v, w;
	vector <int> dist(N, -1), visited(N, 0), prev[N];
	priority_queue <pair <int, int>, vector <pair<int, int>>, greater <pair<int, int>>> pq;
	dist[src]=0;
	pq.push(make_pair(dist[src], src));
	while(!pq.empty()){
		u=pq.top().second;
		pq.pop();
		visited[u]=1;
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			w=graph[u][i].second;
			if((dist[v]==-1 || dist[v]>dist[u]+w) && !visited[v]){
				dist[v]=dist[u]+w;
				pq.push(make_pair(dist[v], v));
				prev[v].clear();
				prev[v].push_back(u);
			}
			else if(dist[v]==dist[u]+w)
				prev[v].push_back(u);
		}
	}
	if(dist[dest]==-1)
		return -1;
	visited.assign(N, 0);
	queue <int> q;
	q.push(dest);
	while(!q.empty()){
		u=q.front();
		visited[u]=1;
		for(i=0; i<prev[u].size(); i++){
			if(!visited[prev[u][i]])
				q.push(prev[u][i]);
			shortestPathEdges.insert(make_pair(prev[u][i], u));
		}
		q.pop();
	}
	return dist[dest];
}

int dijkstraAlmostShortestPath(vector <pair<int, int>> graph[], int N, int src, int dest){
	int i, u, v, w;
	vector <int> dist(N, -1), visited(N, 0);
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
			if(shortestPathEdges.find(make_pair(u, v))==shortestPathEdges.end()){
				if((dist[v]==-1 || dist[v]>dist[u]+w) && !visited[v]){
					dist[v]=dist[u]+w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
	}
	shortestPathEdges.clear();
	return dist[dest];
}

int main() {
	int N, M, S, D, U, V, P, i, d;
	while(cin>>N>>M && N+M!=0){
		cin>>S>>D;
		vector <pair<int, int>> graph[N];
		for(i=0; i<M; i++){
			cin>>U>>V>>P;
			graph[U].push_back(make_pair(V, P));
		}
		d=dijkstraShortesPath(graph, N, S, D);
		if(d==-1)
			cout<<"-1\n";
		else{
			d=dijkstraAlmostShortestPath(graph, N, S, D);
			cout<<d<<"\n";
		}
	}
	return 0;
}
