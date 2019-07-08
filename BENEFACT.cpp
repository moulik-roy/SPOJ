#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

vector <int> bfs(vector <pair<int, int>> tree[], int n, int src){
	int i, u, v, w;
	vector <int> dist(n+1, -1);
	queue <int> q;
	dist[src]=0;
	q.push(src);
	while(!q.empty()){
		u=q.front();
		for(i=0; i<tree[u].size(); i++){
			v=tree[u][i].first;
			w=tree[u][i].second;
			if(dist[v]==-1){
				dist[v]=dist[u]+w;
				q.push(v);
			}
		}
		q.pop();
	}
	return dist;
}

int main(){
	int t, n, i, a, b, l, diameter, max_length;
	cin>>t;
	while(t--){
		cin>>n;
		vector <pair<int, int>> tree[n+1];
		vector <int> dist;
		for(i=1; i<n; i++){
			cin>>a>>b>>l;
			tree[a].push_back(make_pair(b, l));
			tree[b].push_back(make_pair(a, l));
		}
		dist=bfs(tree, n, 1);
		diameter=max_element(dist.begin(), dist.end())-dist.begin();
		dist=bfs(tree, n, diameter);
		max_length=*max_element(dist.begin(), dist.end());
		cout<<max_length<<"\n";
	}
	return 0;
}
