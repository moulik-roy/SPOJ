#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;

vector <int> dijkstra(vector <pair<int, int>> graph[], int n, int src){
	int i, u, v, w;
	vector <int> dist(n, -1);
	set <pair <int, int>> st;
	dist[src]=0;
	st.emplace(make_pair(dist[src], src));
	while(!st.empty()){
		u=st.begin()->second;
		st.erase(st.begin());
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			w=graph[u][i].second;
			if(dist[v]==-1 || dist[v]>dist[u]+w){
                		if(dist[v]!=-1)
                    			st.erase(make_pair(dist[v], v));
				dist[v]=dist[u]+w;
				st.emplace(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int main(){
	int N, M, Q, i, A, B, L, q, max_dist, count;
	cin>>N>>M>>Q;
	vector <pair<int, int>> graph[N];
	vector <int> dist;
	for(i=0; i<M; i++){
		cin>>A>>B>>L;
		if(A!=B){
			graph[A].push_back(make_pair(B, L));
			graph[B].push_back(make_pair(A, L));
		}
	}
	while(Q--){
		cin>>q;
		dist=dijkstra(graph, N, q);
		max_dist=*max_element(dist.begin(), dist.end());
		for(i=0, count=0; i<dist.size(); i++){
			if(dist[i]==max_dist)
				count++;
		}
		cout<<max_dist<<" "<<count<<"\n";
	}
	return 0;
}
