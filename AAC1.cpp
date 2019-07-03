#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int T, N, M, X, Y, i, u, v, s;
	cin>>T;
	while(T--){
		cin>>N>>M;
		vector <int> graph[N+1], dist(N+1, -1);
		queue <int> q;
		for(i=0; i<M; i++){
			cin>>X>>Y;
			graph[X].push_back(Y);
			graph[Y].push_back(X);
		}
		q.push(1);	dist[1]=0;
		while(!q.empty() && dist[N]==-1){
			s=q.size();
			while(s--){
				u=q.front();
				for(i=0; i<graph[u].size(); i++){
					v=graph[u][i];
					if(dist[v]==-1){
						dist[v]=dist[u]+1;
						q.push(v);
					}
				}
				q.pop();
			}
		}
		cout<<dist[N]<<"\n";
	}
	return 0;
}
