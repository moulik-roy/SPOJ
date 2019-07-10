#include <iostream>
#include <string>
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

void dfs2(vector <int> graph[], int u, int visited[]){
	visited[u]=1;
	for(int i=0; i<graph[u].size(); i++){
		if(!visited[graph[u][i]])
			dfs(graph, graph[u][i], visited);
	}
}

int main(){
	int t, N, i, j, no_groups;
	cin>>t;
	while(t--){
		cin>>N;
		string Known[N];
		vector <int> graph[N], graph_inverse[N];
		int visited[N];
		for(i=0; i<N; i++)
			cin>>Known[i];
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				if(Known[i][j]=='Y'){
					graph[i].push_back(j);
					graph_inverse[j].push_back(i);
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		for(i=0, no_groups=0; i<N; i++){
			if(!visited[i])
				dfs(graph, i, visited);
		}
		memset(visited, 0, sizeof(visited));
		while(!st.empty()){
			if(!visited[st.top()]){
				dfs2(graph_inverse, st.top(), visited);
				no_groups++;
			}
			st.pop();
		}
		cout<<no_groups<<"\n";
	}
	return 0;
}