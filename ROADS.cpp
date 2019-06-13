#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dijkstra(vector <pair<int, pair<int, int>>> graph[], int N, int K){
	int i, u, v, dist, toll, L, T;
	priority_queue <pair <pair<int, int>, int>, vector <pair<pair<int, int>, int>>, greater <pair<pair<int, int>, int>>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	while(!q.empty()){
		u=q.top().second;
		dist=q.top().first.first;
		toll=q.top().first.second;
		q.pop();
		if(u==N)
			break;
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			L=graph[u][i].second.first;
			T=graph[u][i].second.second;
			if(toll+T<=K)
				q.push(make_pair(make_pair(dist+L, toll+T), v));
		}
	}
	if(u==N)
		return dist;
	else
		return -1;
}

int main(){
	int t, K, N, R, i, S, D, L, T;
	cin>>t;
	while(t--){
		cin>>K>>N>>R;
		vector <pair<int, pair<int, int>>> graph[N+1];
		for(i=0; i<R; i++){
			cin>>S>>D>>L>>T;
			graph[S].push_back(make_pair(D, make_pair(L, T)));
		}
		cout<<dijkstra(graph, N, K)<<"\n";
	}
	return 0;
}