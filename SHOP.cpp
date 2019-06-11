#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int main(){
	int n, m, i, j, k, x, y, dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
	pair <int, int> src, dest, p;
	while(true){
		scanf("%d %d", &m, &n);
		if(n+m==0)
			break;
		string shop[n];
		int dist[n][m];
		memset(dist, -1, sizeof(dist));
		for(i=0; i<n; i++)
			cin>>shop[i];
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				if(shop[i][j]=='S'){
					src.first=i;
					src.second=j;
				}
				else if(shop[i][j]=='D'){
					shop[i][j]='0';
					dest.first=i;
					dest.second=j;
				}
			}
		}
		dist[src.first][src.second]=0;
		queue <pair<int, int>> q;
		q.push(src);
		while(!q.empty()){
			p=q.front();
			i=p.first;
			j=p.second;
			for(k=0; k<4; k++){
				x=i+dx[k];
				y=j+dy[k];
				if(x>=0 && x<n && y>=0 && y<m && shop[x][y]!='X' && (dist[x][y]==-1 || dist[x][y]>dist[i][j]+shop[x][y]-'0')){
					dist[x][y]=dist[i][j]+shop[x][y]-'0';
					q.push(make_pair(x, y));
				}
			}
			q.pop();
		}
		cout<<dist[dest.first][dest.second]<<"\n";
	}
	return 0;
}