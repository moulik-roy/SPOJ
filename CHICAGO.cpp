#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

double dijkstra(vector <pair<int, double>> graph[], int n){
    int i, u, v;
    double p;
    vector <int> visited(n+1, 0);
    vector <double> dist(n+1, -1);
    priority_queue <pair<double, int>> pq;
    dist[1]=1;
    pq.push(make_pair(dist[1], 1));
    while(!pq.empty() && !visited[n]){
        u=pq.top().second;
        visited[u]=1;
        pq.pop();
        for(i=0; i<graph[u].size(); i++){
            v=graph[u][i].first;
            p=graph[u][i].second;
            if(!visited[v] && dist[v]<dist[u]*p){
                dist[v]=dist[u]*p;
                pq.push(make_pair(dist[v], v));
            }
        }
        
    }
    return dist[n]*100;
}

int main(){
    int n, m, i, a, b;
    double p;
    while(cin>>n && n!=0){
        cin>>m;
        vector <pair<int, double>> graph[n+1];
        for(i=0; i<m; i++){
            cin>>a>>b>>p;
            graph[a].push_back(make_pair(b, p/100));
            graph[b].push_back(make_pair(a, p/100));
        }
        printf("%.6lf percent\n", dijkstra(graph, n));
    }
    return 0;
}