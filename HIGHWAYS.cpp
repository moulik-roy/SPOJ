#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main(){
	int t, n, m, i, u, v, w, src, dest;
	cin>>t;
	while(t--){
		cin>>n>>m>>src>>dest;
		vector <pair<int, int>> graph[n+1];
		vector <int> distance(n+1, -1), visited(n+1, 0);
		priority_queue <pair <int, int>, vector <pair<int, int>>, greater <pair<int, int>>> q;
		distance[src]=0;
		for(i=0; i<m; i++){
			cin>>u>>v>>w;
			graph[u].push_back(make_pair(v, w));
			graph[v].push_back(make_pair(u, w));
		}
		q.push(make_pair(distance[src], src));
		while(!q.empty()){
			u=q.top().second;
			q.pop();
			visited[u]=1;
			for(i=0; i<graph[u].size(); i++){
				v=graph[u][i].first;
				w=graph[u][i].second;
				if((distance[v]==-1 || distance[v]>distance[u]+w) && !visited[v]){
					distance[v]=distance[u]+w;
					q.push(make_pair(distance[v], v));
				}
			}
		}
		if(distance[dest]==-1)
			cout<<"NONE\n";
		else
			cout<<distance[dest]<<"\n";
	}
	return 0;
}