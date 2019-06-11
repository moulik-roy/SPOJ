#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
 
stack <int> st;
 
void dfs(vector <int> v[], int s, int visited[]){
	visited[s]=1;
	for(int i=0; i<v[s].size(); i++){
		if(!visited[v[s][i]])
			dfs(v, v[s][i], visited);
	}
	st.push(s);
}
 
void dfs2(vector <int> v[], int s, int component[], int c, int visited[]){
	visited[s]=1;
	component[s]=c;
	for(int i=0; i<v[s].size(); i++){
		if(!visited[v[s][i]])
			dfs2(v, v[s][i], component, c, visited);
	}
}
 
int main(){
	int t, n, i, j, u, c, no_scc;
	cin>>t;
	while(t--){
		cin>>n;
		vector <int> graph[n+1], graph_inv[n+1];
		int visited[n+1], scc[n+1];
		for(i=1; i<=n; i++){
			cin>>c;
			while(c--){
				cin>>u;
				graph[u].push_back(i);
				graph_inv[i].push_back(u);
			}
		}
		memset(visited, 0, sizeof(visited));
		for(i=1, no_scc=0; i<=n; i++){
			if(!visited[i])
				dfs(graph, i, visited);
		}
		memset(visited, 0, sizeof(visited));
		while(!st.empty()){
			u=st.top();
			if(!visited[u])
				dfs2(graph_inv, u, scc, no_scc++, visited);
			st.pop();	
		}
		int in_degree[no_scc];
		memset(in_degree, 0, sizeof(in_degree));
		for(i=1; i<=n; i++){
			for(j=0; j<graph[i].size(); j++){
				if(scc[i]!=scc[graph[i][j]])
					in_degree[scc[graph[i][j]]]++;
			}
		}
		for(i=0, c=0; i<no_scc; i++){
			if(in_degree[i]==0)
				c++;
		}
		if(c>1)
			cout<<0<<"\n";
		else{
			for(i=1, c=0; i<=n; i++){
				if(in_degree[scc[i]]==0)
					c++;
			}
			cout<<c<<"\n";
		}
	}
	return 0;
}