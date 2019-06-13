#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector <vector<int>> bfs(string s[], int n, int m){
	int i, j, k, size, x, y, dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
	vector <vector<int>> dist(n, vector<int>(m, -1));
	queue <pair<int, int>> q;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(s[i][j]=='1'){
				dist[i][j]=0;
				q.push(make_pair(i, j));
			}
		}
	}
	while(!q.empty()){
		size=q.size();
		while(size--){
			i=q.front().first;
			j=q.front().second;
			for(k=0; k<4; k++){
				x=i+dx[k];
				y=j+dy[k];
				if(x>=0 && x<n && y>=0 && y<m && dist[x][y]==-1){
					dist[x][y]=dist[i][j]+1;
					q.push(make_pair(x, y));
				}
			}
			q.pop();
		}
	}
	return dist;
}

int main(){
	int t, n, m, i, j;
	vector <vector<int>> dist;
	cin>>t;
	while(t--){
		cin>>n>>m;
		string bitmap[n];
		for(i=0; i<n; i++)
			cin>>bitmap[i];
		dist=bfs(bitmap, n, m);
		for(i=0; i<n; i++){
			for(j=0; j<m; j++)
				cout<<dist[i][j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}