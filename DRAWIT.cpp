#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
  
void dfs(vector <int> v[], int s, int visited[]){
	visited[s]=1;
	for(int i=0; i<v[s].size(); i++){
		if(!visited[v[s][i]])
			dfs(v, v[s][i], visited);
	}
}
 
int main(){
	int T, N, K, S, D, M, i, flag_scc, odd_degree;
	cin>>T;
	while(T--){
		cin>>N>>K;
		vector <int> graph[N+1];
		int visited[N+1], degree[N+1];
		memset(visited, 0, sizeof(visited));
		memset(degree, 0, sizeof(degree));
		for(i=0; i<K; i++){
			cin>>S>>D>>M;
			graph[S].push_back(D);
			graph[D].push_back(S);
			degree[S]+=M;
			degree[D]+=M;
		}
		dfs(graph, 1, visited);
		for(i=1, flag_scc=0, odd_degree=0, S=-1; i<=N; i++){
			if(!visited[i]){
				flag_scc=1;
				break;
			}
			if((degree[i]&1)==1){
				odd_degree++;
				if(S==-1)
					S=i;
			}
		}
		if(flag_scc==1 || odd_degree==1 || odd_degree>2)
			cout<<"NO\n";
		else if(odd_degree==0)
			cout<<"YES 1\n";
		else if(odd_degree==2)
			cout<<"YES "<<S<<"\n";
	}
	return 0;
}