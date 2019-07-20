#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

stack <int> st;

void dfs(vector <int> graph[], int u, int visited[]){
	visited[u]=1;
	for(int i=0; i<graph[u].size(); i++){
		if(!visited[graph[u][i]])
			dfs(graph, graph[u][i], visited);
	}
	st.push(u);
}

int main(){
	int N, K, W, i, u, prev;
	cin>>N>>K;
	vector <int> graph[N+1];
	int visited[N+1], parent[N+1];
	memset(visited, 0, sizeof(visited));
	memset(parent, -1, sizeof(parent));
	for(i=1; i<=K; i++){
		cin>>W;
		while(W--){
			cin>>u;
			graph[i].push_back(u);
		}
	}
	for(i=1, prev=0; i<=N; i++){
		if(!visited[i])
			dfs(graph, i, visited);
	}
	while(!st.empty()){
		u=st.top();
		parent[u]=prev;
		prev=u;
		st.pop();
	}
	for(i=1; i<=N; i++)
		cout<<parent[i]<<" ";
	cout<<"\n";
	return 0;
}