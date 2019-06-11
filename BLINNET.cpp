#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int findSet(int parent[], int i){
	while(parent[i]!=i)
		i=parent[i];
	return i;
}

int main(){
	int t, n, i, p, u, v, w, cost;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		vector <pair<int, pair<int, int>>> edges;
		int parent [n+1];
		for(i=1; i<=n; i++){
			parent[i]=i;
			cin>>s;
			cin>>p;
			while(p--){
				cin>>u>>w;
				edges.push_back(make_pair(w, make_pair(i, u)));
			}
		}
		sort(edges.begin(), edges.end());
		for(i=0, cost=0; i<edges.size(); i++){
			u=findSet(parent, edges[i].second.first);
			v=findSet(parent, edges[i].second.second);
			if(u!=v){
				parent[v]=u;
				cost+=edges[i].first;
			}
		}
		cout<<cost<<"\n";
	}
	return 0;
}