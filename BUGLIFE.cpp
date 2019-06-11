#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	 int T, t, n, m, i, u, v, flag;
	 cin>>T;
	 for(t=1; t<=T; t++){
	 	cin>>n>>m;
	 	vector <int> graph[n+1], colour(n+1, -1);
	 	queue <int> q;
	 	for(i=0, flag=0; i<m; i++){
	 		cin>>u>>v;
	 		graph[u].push_back(v);
	 		graph[v].push_back(u);
	 	}
	 	for(i=1; i<=n; i++){
	 		if(colour[i]==-1){
	 			q.push(i);
	 			colour[i]=1;
	 			while(!q.empty()){
	 				u=q.front();
	 				for(i=0; i<graph[u].size(); i++){
	 					v=graph[u][i];
	 					if(colour[v]==-1){
	 						colour[v]=1-colour[u];
	 						q.push(v);
	 					}
	 					else if(colour[v]==colour[u]){
	 						flag=1;
	 						break;
	 					}
	 				}
	 				q.pop();
	 				if(flag==1)
	 					break;
	 			}
	 		}
	 		if(flag==1)
	 			break;
	 	}
	 	cout<<"Scenario #"<<t<<":\n";
	 	if(flag==1)
	 		cout<<"Suspicious bugs found!\n";
	 	else
	 		cout<<"No suspicious bugs found!\n";
	 }
	return 0;
}