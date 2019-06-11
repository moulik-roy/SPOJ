#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void dfs(vector <long int> graph[], bool visited[], long int s){
	visited[s]=true;
	for(int i=0; i<graph[s].size(); i++){
		if(!visited[graph[s][i]])
			dfs(graph, visited, graph[s][i]);
	}
}

int main(){
	long int N, M, i, u, v, count;
	cin>>N>>M;
	vector <long int> graph[N];
	bool visited[N];
	memset(visited, false, sizeof(visited));
	for(i=0; i<M; i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(i=0, count=0; i<N; i++){
		if(!visited[i]){
			dfs(graph, visited, i);
			count++;
		}
	}
	cout<<count-1<<"\n";
	return 0;
}