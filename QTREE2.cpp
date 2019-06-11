#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

void dfs(vector <pair<int, int>> tree[], int node, int parent, int level[], int dist[], vector <int> dp[]){
	int i, u, w;
	dp[node][0]=parent;
	for(i=1; i<dp[node].size(); i++)
		dp[node][i]=dp[dp[node][i-1]][i-1];
	for(i=0; i<tree[node].size(); i++){
		u=tree[node][i].first;
		w=tree[node][i].second;
		if(u!=parent){
			level[u]=level[node]+1;
			dist[u]=dist[node]+w;
			dfs(tree, u, node, level, dist, dp);
		}
	}
}

int findLCA(vector <int> dp[], int level[], int a, int b){
	int i, t, diff;
	if(level[b]<level[a]){
		t=a;
		a=b;
		b=t;
	}
	diff=level[b]-level[a];
	for(i=0; i<dp[1].size(); i++){
		if((diff>>i)&1)
			b=dp[b][i];
	}
	if(a==b)
		return a;
	for(i=dp[1].size()-1; i>=0; i--){
		if(dp[a][i]!=dp[b][i]){
			a=dp[a][i];
			b=dp[b][i];
		}
	}
	return dp[a][0];
}

int findKth(vector <int> dp[], int level[], int a, int b, int k, int lca){
	int t, d, i;
	if(lca==a){
		d=level[b]-level[a]+1;
		k=d-k+1;
		t=a;
		a=b;
		b=t;
	}
	else if(lca!=a && lca!=b){
		if(level[a]-level[lca]+1<k){
			d=level[a]+level[b]+2-2*level[lca];
			k=d-k;
			t=a;
			a=b;
			b=t;
		}
	}
	for(i=0; i<dp[1].size() && k>1; i++){
		if(((k-1)>>i)&1)
			a=dp[a][i];
	}
	return a;
}

int main(){
	int t, N, i, a, b, cost, k, lca, d;
	string s;
	cin>>t;
	while(t--){
		cin>>N;
		vector <pair<int, int>> tree[N+1];
		vector <int> dp[N+1];
		for(i=1, k=ceil(log2(N)); i<=N; i++)
			dp[i].resize(k);
		int level[N+1], dist_root[N+1];
		memset(level, 0, sizeof(level));
		memset(dist_root, 0, sizeof(dist_root));
		for(i=1; i<N; i++){
			cin>>a>>b>>cost;
			tree[a].push_back(make_pair(b, cost));
			tree[b].push_back(make_pair(a, cost));
		}
		dfs(tree, 1, 1, level, dist_root, dp);
		while(cin>>s && s.compare("DONE")!=0){
			if(s.compare("DIST")==0){
				cin>>a>>b;
				lca=findLCA(dp, level, a, b);
				if(lca==a || lca==b)
					d=abs(dist_root[a]-dist_root[b]);
				else
					d=dist_root[a]+dist_root[b]-2*dist_root[lca];
				cout<<d<<"\n";
			}
			else{
				cin>>a>>b>>k;
				lca=findLCA(dp, level, a, b);
				cout<<findKth(dp, level, a, b, k, lca)<<"\n";
			}
		}
	}
	return 0;
}