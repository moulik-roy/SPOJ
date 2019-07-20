#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> bfs(vector <int> tree[], int n, int s){
	int i;
	vector <int> dist(n, -1);
	queue <int> q;
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		s=q.front();
		for(i=0; i<tree[s].size(); i++){
			if(dist[tree[s][i]]==-1){
				dist[tree[s][i]]=dist[s]+1;
				q.push(tree[s][i]);
			}
		}
		q.pop();
	}
	return dist;
}

int main(){
	int T, N, a, b, i;
	cin>>T;
	while(T--){
		cin>>N;
		vector <int> tree[N], dist;
		for(i=1; i<N; i++){
			cin>>a>>b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		dist=bfs(tree, N, 0);
		i=max_element(dist.begin(), dist.end())-dist.begin();
		dist=bfs(tree, N, i);
		cout<<(*max_element(dist.begin(), dist.end())+1)/2<<"\n";
	}
	return 0;
}