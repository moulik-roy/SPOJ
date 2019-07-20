#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector <int> dijkstra(vector <pair<int, int>> graph[], int src){
	int i, u, v, w;
	vector <int> dist(502, -1), visited(502, 0);
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
			if((dist[v]==-1 || dist[v]>dist[u]+w) && !visited[v]){
				dist[v]=dist[u]+w;
				q.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int main(){
	vector <pair<int, int>> graph[502];
	vector <int> dist;
	int N, A, B, W, U, Q, V;
	cin>>N;
	while(N--){
		cin>>A>>B>>W;
		graph[A].push_back(make_pair(B, W));
		graph[B].push_back(make_pair(A, W));
	}
	cin>>U>>Q;
	dist=dijkstra(graph, U);
	while(Q--){
		cin>>V;
		if(dist[V]==-1)
			cout<<"NO PATH\n";
		else
			cout<<dist[V]<<"\n";
	}
	return 0;
}