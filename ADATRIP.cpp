#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

vector <int> dijkstra(vector <pair<int, int>> graph[], int n, int src){
	int i, u, v, w;
	vector <int> dist(n, -1), visited(n, 0);
	priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair<int, int>>> q;
	dist[src]=0;
	q.push(make_pair(dist[src], src));
	while(!q.empty()){
		u=q.top().second;
		visited[u]=1;
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			w=graph[u][i].second;
			if((dist[v]==-1 || dist[v]>dist[u]+w) && !visited[v]){
				dist[v]=dist[u]+w;
				q.push(make_pair(dist[v], v));
			}
		}
		q.pop();
	}
	return dist;
}

int main(){
	int N, M, Q, i, A, B, L, q, c, max_dist;
	cin>>N>>M>>Q;
	vector <pair<int, int>> graph[N];
	vector <int> dist;
	for(i=0; i<M; i++){
		cin>>A>>B>>L;
		if(A!=B){
			graph[A].push_back(make_pair(B, L));
			graph[B].push_back(make_pair(A, L));
		}
	}
	while(Q--){
		cin>>q;
		dist=dijkstra(graph, N, q);
		max_dist=*max_element(dist.begin(), dist.end());
		for(i=0, c=0; i<dist.size(); i++){
			if(dist[i]==max_dist)
				c++;
		}
		cout<<max_dist<<" "<<c<<"\n";
	}
	return 0;
}