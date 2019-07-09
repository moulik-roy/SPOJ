#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int main(){
	int n, m, i, j, k, x, y, dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
	cin>>n>>m;
	string grid[n];
	int dist[n][m];
	memset(dist, -1, sizeof(dist));
	for(i=0; i<n; i++)
		cin>>grid[i];
	dist[0][0]=0;
	queue <pair<int, int>> q;
	q.push(make_pair(0, 0));
	while(!q.empty() && dist[n-1][m-1]==-1){
		i=q.front().first;
		j=q.front().second;
		for(k=0; k<4; k++){
			x=i+(grid[i][j]-'0')*dx[k];
			y=j+(grid[i][j]-'0')*dy[k];
			if(x>=0 && x<n && y>=0 && y<m && dist[x][y]==-1){
				dist[x][y]=dist[i][j]+1;
				q.push(make_pair(x, y));
			}
		}
		q.pop();
	}
	cout<<dist[n-1][m-1]<<"\n";
	return 0;
}