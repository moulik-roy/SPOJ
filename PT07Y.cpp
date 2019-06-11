#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool dfs(vector <int> graph[], int node, int parent, int visited[]){
	visited[node]=1;
	for(int i=0; i<graph[node].size(); i++){
		if(!visited[graph[node][i]]){
			if(dfs(graph, graph[node][i], node, visited))
				return true;
		}
		else if(graph[node][i]!=parent)
			return true;
	}
	return false;
}

int main(){
	int N, M, i, u, v;
	cin>>N>>M;
	vector <int> graph[N+1];
	int visited[N+1];
	memset(visited, 0, sizeof(visited));
	for(i=0; i<M; i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	if(dfs(graph, 1, -1, visited)==true)
		cout<<"NO";
	else{
		for(i=1; i<=N; i++){
			if(!visited[i])
				break;
		}
		if(i==N+1)
			cout<<"YES";
		else
			cout<<"NO";
	}
	return 0;
}