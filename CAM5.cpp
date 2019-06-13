#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void dfs(vector <int> graph[], int s, bool visited[]){
	visited[s]=true;
	for(int i=0; i<graph[s].size(); i++){
		if(!visited[graph[s][i]])
			dfs(graph, graph[s][i], visited);
	}
}

int main(){
	int t, N, e, i, a, b, no_people;
	cin>>t;
	while(t--){
		cin>>N>>e;
		vector <int> graph[N];
		bool visited[N];
		memset(visited, false, sizeof(visited));
		while(e--){
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for(i=0, no_people=0; i<N; i++){
			if(!visited[i]){
				no_people++;
				dfs(graph, i, visited);
			}
		}
		cout<<no_people<<"\n";
	}
	return 0;
}