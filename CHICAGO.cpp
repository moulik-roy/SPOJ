#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

double dijkstra(vector <pair<int, double>> graph[], int n){
	int i, u, v;
	double p;
	vector <double> dist(n+1, -1);
	queue <int> q;
	dist[1]=1;
	q.push(1);
	while(!q.empty()){
		u=q.front();
		for(i=0; i<graph[u].size(); i++){
			v=graph[u][i].first;
			p=graph[u][i].second;
			if(dist[v]==-1 || dist[v]<dist[u]*p){
				dist[v]=dist[u]*p;
				q.push(v);
			}
		}
		q.pop();
	}
	return dist[n]*100;
}

int main(){
	int n, m, i, u, v;
	double p;
	while(cin>>n && n!=0){
		cin>>m;
		vector <pair<int, double>> graph[n+1];
		for(i=0; i<m; i++){
			cin>>u>>v>>p;
			graph[u].push_back(make_pair(v, p/100));
			graph[v].push_back(make_pair(u, p/100));
		}
		printf("%.6lf percent\n", dijkstra(graph, n));
	}
	return 0;
}