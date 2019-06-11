#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int bfs(string labyrinth[], int R, int C, pair <int, int> src, pair <int, int> &diameter){
	int i, x, y, length, dist[R][C], dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
	memset(dist, -1, sizeof(dist));
	dist[src.first][src.second]=0;
	length=0;
	queue <pair<int, int>> q;
	q.push(src);
	while(!q.empty()){
		src=q.front();
		for(i=0; i<4; i++){
			x=src.first+dx[i];
			y=src.second+dy[i];
			if(x>=0 && x<R && y>=0 && y<C && labyrinth[x][y]=='.' && dist[x][y]==-1){
				dist[x][y]=dist[src.first][src.second]+1;
				if(dist[x][y]>length){
					length=dist[x][y];
					diameter.first=x;
					diameter.second=y;
				}
				q.push(make_pair(x, y));
			}
		}
		q.pop();
	}
	return length;
}

int main(){
	int T, C, R, i, j, max_length;
	pair <int, int> s, d;
	cin>>T;
	while(T--){
		cin>>C>>R;
		string labyrinth[R];
		for(i=0; i<R; i++)
			cin>>labyrinth[i];
		for(i=0, s.first=-1; i<R; i++){
			for(j=0; j<C; j++){
				if(labyrinth[i][j]=='.'){
					s=make_pair(i, j);
					d=s;
					break;
				}
			}
			if(s.first!=-1)
				break;
		}
		max_length=bfs(labyrinth, R, C, s, d);
		max_length=bfs(labyrinth, R, C, d, s);
		cout<<"Maximum rope length is "<<max_length<<".\n";
	}
	return 0;
}