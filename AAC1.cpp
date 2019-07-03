#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int T, N, M, X, Y, i, u, v, s, c;
	cin>>T;
	while(T--){
		cin>>N>>M;
		vector <int> graph[N+1], visited(N+1, 0);
		queue <int> q;
		for(i=0; i<M; i++){
			cin>>X>>Y;
			graph[X].push_back(Y);
			graph[Y].push_back(X);
		}
		q.push(1);
		c=0;
		while(!q.empty() && !visited[N]){
			s=q.size();
			while(s--){
				u=q.front();
				visited[u]=1;
				for(i=0; i<graph[u].size(); i++){
					v=graph[u][i];
					if(!visited[v])
						q.push(v);
				}
				q.pop();
			}
			c++;
		}
		cout<<c-1<<"\n";
	}
	return 0;
}
