#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> bfs(vector <int> tree[], int N, int src){
	int i, u, v;
	vector <int> dist(N+1, -1);
	queue <int> q;
	dist[src]=0;
	q.push(src);
	while(!q.empty()){
		u=q.front();
		for(i=0; i<tree[u].size(); i++){
			v=tree[u][i];
			if(dist[v]==-1){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
		q.pop();
	}
	return dist;
}

int main(){
	int N, i, u, v, max_length;
	cin>>N;
	vector <int> tree[N+1], dist;
	for(i=1; i<N; i++){
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dist=bfs(tree, N, 1);
	i=max_element(dist.begin(), dist.end())-dist.begin();
	dist=bfs(tree, N, i);
	max_length=*max_element(dist.begin(), dist.end());
	cout<<max_length<<"\n";
	return 0;
}