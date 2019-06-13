#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

stack <int> st;

void dfs(vector <int> DAG[], int s, int visited[]){
	visited[s]=1;
	for(int i=0; i<DAG[s].size(); i++){
		if(!visited[DAG[s][i]])
			dfs(DAG, DAG[s][i], visited);
	}
	st.push(s);
}

int main(){
	int N, M, i, k, T_0, T_k;
	cin>>N>>M;
	vector <int> DAG[N+1];
	int visited[N+1];
	memset(visited, 0, sizeof(visited));
	for(i=0; i<M; i++){
		cin>>T_0>>k;
		while(k--){
			cin>>T_k;
			DAG[T_k].push_back(T_0);
		}
	}
	for(i=1; i<=N; i++)
		sort(DAG[i].begin(), DAG[i].end(), greater<int>());
	for(i=N; i>0; i--){
		if(!visited[i])
			dfs(DAG, i, visited);
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<"\n";
	return 0;
}
