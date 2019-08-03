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
 
void dfs2(vector <int> graph[], int u, int visited[], int component[], int c){
	visited[u]=1;
	component[u]=c;
	for(int i=0; i<graph[u].size(); i++){
		if(!visited[graph[u][i]])
			dfs2(graph, graph[u][i], visited, component, c);
	}
}
 
int main(){
	int N, M, A, B, i, j, c, no_scc;
	cin>>N>>M;
	vector <int> graph[N+1], graph_inverse[N+1], capcity;
	int visited[N+1], scc[N+1];
	for(i=0, no_scc=0; i<M; i++){
		cin>>A>>B;
		graph[A].push_back(B);
		graph_inverse[B].push_back(A);
	}
	memset(visited, 0, sizeof(visited));
	for(i=1; i<=N; i++){
		if(!visited[i])
			dfs(graph_inverse, i, visited);
	}
	memset(visited, 0, sizeof(visited));
	memset(scc, -1, sizeof(scc));
	while(!st.empty()){
		if(!visited[st.top()])
			dfs2(graph, st.top(), visited, scc, no_scc++);
		st.pop();
	}
	int in_degree[no_scc];
	memset(in_degree, 0, sizeof(in_degree));
	for(i=1; i<=N; i++){
		for(j=0; j<graph_inverse[i].size(); j++){
			if(scc[i]!=scc[graph_inverse[i][j]])
				in_degree[scc[graph_inverse[i][j]]]++;
		}
	}
	for(i=0, c=0; i<no_scc; i++){
		if(in_degree[i]==0)
			c++;
	}
	if(c>1)
		cout<<0<<"\n";
	else{
		for(i=1; i<=N; i++){
			if(in_degree[scc[i]]==0)
				capcity.push_back(i);
		}
		cout<<capcity.size()<<"\n";
		for(i=0; i<capcity.size(); i++)
			cout<<capcity[i]<<" ";
		cout<<"\n";
	}
	return 0;
}