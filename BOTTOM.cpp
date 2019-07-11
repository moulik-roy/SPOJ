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

void dfs2(vector <int> graph[], int u, int visited[], int component[], int scc){
	visited[u]=1;
	component[u]=scc;
	for(int i=0; i<graph[u].size(); i++){
		if(!visited[graph[u][i]])
			dfs2(graph, graph[u][i], visited, component, scc);
	}
}

int main(){
	int V, E, i, j, u, v, no_scc;
	while(cin>>V && V!=0){
		cin>>E;
		vector <int> graph[V+1], graph_inverse[V+1];
		int visited[V+1], component[V+1];
		for(i=0; i<E; i++){
			cin>>u>>v;
			graph[u].push_back(v);
			graph_inverse[v].push_back(u);
		}
		memset(visited, 0, sizeof(visited));
		for(i=1, no_scc=0; i<=V; i++){
			if(!visited[i])
				dfs(graph, i, visited);
		}
		memset(visited, 0, sizeof(visited));
		memset(component, -1, sizeof(component));
		while(!st.empty()){
			if(!visited[st.top()])
				dfs2(graph_inverse, st.top(), visited, component, no_scc++);
			st.pop();
		}
		int bottom[no_scc];
		memset(bottom, 0, sizeof(bottom));
		for(i=1; i<=V; i++){
			for(j=0; j<graph[i].size(); j++){
				if(component[i]!=component[graph[i][j]]){
					bottom[component[i]]=1;
					break;
				}
			}
		}
		for(i=1; i<=V; i++){
			if(bottom[component[i]]==0)
				cout<<i<<" ";
		}
		cout<<"\n";
	}
	return 0;
}