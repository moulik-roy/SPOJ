#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	int T, N, M, i, u, v;
	cin>>T;
	while(T--){
		cin>>N;
		vector <int> graph[N+1], dist(N+1, -1), prev(N+1, -1), path;
		queue <int> q;
		for(i=1; i<N; i++){
			cin>>M;
			while(M--){
				cin>>u;
				graph[i].push_back(u);
			}
			sort(graph[i].begin(), graph[i].end());
		}
		dist[1]=0;
		q.push(1);
		while(!q.empty()){
			u=q.front();
			for(i=0; i<graph[u].size(); i++){
				v=graph[u][i];
				if(dist[v]==-1){
					dist[v]=dist[u]+1;
					prev[v]=u;
					q.push(v);
				}
			}
			q.pop();
		}
		cout<<dist[N]<<"\n";
		if(dist[N]!=-1){
			u=prev[N];
			while(u!=-1){
				path.push_back(u);
				u=prev[u];
			}
			for(i=path.size()-1; i>=0; i--)
				cout<<path[i]<<" ";
			cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}