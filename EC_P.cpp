#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

void dfs(vector <int> graph[], int u, int parent[], int visited[], int disc[], int low[], vector <pair<int, int>> &bridges){
	static int time=0;
	int i, v;
	visited[u]=1;
	disc[u]=low[u]=time++;
	for(i=0; i<graph[u].size(); i++){
		v=graph[u][i];
		if(!visited[v]){
			parent[v]=u;
			dfs(graph, v, parent, visited, disc, low, bridges);
			low[u]=min(low[u], low[v]);
			if(disc[u]<low[v])
				bridges.push_back(make_pair(min(u, v), max(u, v)));
		}
		else if(v!=parent[u])
			low[u]=min(low[u], disc[v]);
	}
}

int main(){
	int NC, T, N, M, i, a, b;
	cin>>NC;
	for(T=1; T<=NC; T++){
		cin>>N>>M;
		vector <int> graph[N+1];
		vector <pair<int, int>> bridges;
		int parent[N+1], visited[N+1], disc[N+1], low[N+1];
		memset(parent, -1, sizeof(parent));
		memset(visited, 0, sizeof(visited));
		for(i=0; i<M; i++){
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(graph, 1, parent, visited, disc, low, bridges);
		cout<<"Caso #"<<T<<"\n";
		if(bridges.size()==0)
			cout<<"Sin bloqueos\n";
		else{
			cout<<bridges.size()<<"\n";
			sort(bridges.begin(), bridges.end());
			for(i=0; i<bridges.size(); i++)
				cout<<bridges[i].first<<" "<<bridges[i].second<<"\n";
		}
	}
	return 0;
}