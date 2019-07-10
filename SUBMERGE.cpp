#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void dfs(vector <int> graph[], int u, int parent[], int visited[], int disc[], int low[], int cut_vertices[]){
	static int time=0;
	int i, children, v;
	visited[u]=1;
	disc[u]=low[u]=time++;
	for(i=0, children=0; i<graph[u].size(); i++){
		v=graph[u][i];
		if(!visited[v]){
			children++;
			parent[v]=u;
			dfs(graph, v, parent, visited, disc, low, cut_vertices);
			low[u]=min(low[u], low[v]);
			if(parent[u]==-1 && children>1)
				cut_vertices[u]=1;
			else if(parent[u]!=-1 && disc[u]<=low[v])
				cut_vertices[u]=1;
		}
		else if(v!=parent[u])
			low[u]=min(low[u], disc[v]);
	}
}

int main(){
	int N, M, i, U, V, count;
	while(cin>>N>>M && N+M!=0){
		vector <int> graph[N+1];
		int parent[N+1], visited[N+1], disc[N+1], low[N+1], islands[N+1];
		memset(parent, -1, sizeof(parent));
		memset(visited, 0, sizeof(visited));
		memset(islands, 0, sizeof(islands));
		for(i=0; i<M; i++){
			cin>>U>>V;
			graph[U].push_back(V);
			graph[V].push_back(U);
		}
		for(i=1; i<=N; i++){
			if(!visited[i])
				dfs(graph, 1, parent, visited, disc, low, islands);
		}
		for(i=1, count=0; i<=N; i++){
			if(islands[i]==1)
				count++;
		}
		cout<<count<<"\n";
	}
	return 0;
}