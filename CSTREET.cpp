#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector <int> PrimsMST(vector <pair<int, int>> graph[], int n, int src){
	int i, u, v, w;
	vector <int> dist(n+1, -1), visited(n+1, 0);
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
			if((dist[v]==-1 || dist[v]>w) && !visited[v]){
				dist[v]=w;
				q.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int main(){
	int t, p, n, m, i, a, b, c, mst_cost, min_price;
	cin>>t;
	while(t--){
		cin>>p>>n>>m;
		vector <pair<int, int>> graph[n+1];
		vector <int> MST;
		for(i=0; i<m; i++){
			cin>>a>>b>>c;
			graph[a].push_back(make_pair(b, c));
			graph[b].push_back(make_pair(a, c));	
		}
		MST=PrimsMST(graph, n, 1);
		for(i=1, mst_cost=0; i<=n; i++)
			mst_cost+=MST[i];
		min_price=p*mst_cost;
		cout<<min_price<<"\n";
	}
	return 0;
}