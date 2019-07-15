#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1000000007
using namespace std;

int dfs(vector <long int> graph[], long int u, long int dest, long int dp[]){
	if(dp[u]!=-1)
		return dp[u];
	dp[u]=0;
	for(int i=0; i<graph[u].size(); i++)
		dp[u]=(dp[u]+dfs(graph, graph[u][i], dest, dp))%MOD;
	return dp[u];
}

int main(){
	long int D, C, B, S, T, i, X, Y, count_paths;
	cin>>D;
	while(D--){
		cin>>C>>B>>S>>T;
		vector <long int> graph[C+1];
		long int dp[C+1];
		memset(dp, -1, sizeof(dp));
		for(i=0, dp[T]=1; i<B; i++){
			cin>>X>>Y;
			graph[X].push_back(Y);
		}
		count_paths=dfs(graph, S, T, dp);
		cout<<count_paths<<"\n";
	}
	return 0;
}