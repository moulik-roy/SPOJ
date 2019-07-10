#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int main(){
	int t, N, i, j, k, sx, sy, ex, ey, x, y, mask, min_count, dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
	cin>>t;
	while(t--){
		cin>>N;
		int A[N][N], visited[N][N][1025];
		memset(visited, 0, sizeof(visited));
		for(i=0; i<N; i++){
			for(j=0; j<N; j++)
				cin>>A[i][j];
		}
		cin>>sx>>sy>>ex>>ey;
		visited[sx][sy][(1<<A[sx][sy])]=1;
		queue <pair<pair<int, int>, int>> q;
		q.push(make_pair(make_pair(sx, sy), (1<<A[sx][sy])));
		while(!q.empty()){
			i=q.front().first.first;
			j=q.front().first.second;
			mask=q.front().second;
			for(k=0; k<4; k++){
				x=i+dx[k];
				y=j+dy[k];
				if(x>=0 && x<N && y>=0 && y<N && !visited[x][y][mask]){
					visited[x][y][mask|(1<<A[x][y])]=1;
					q.push(make_pair(make_pair(x, y), mask|(1<<A[x][y])));
				}
			}
			q.pop();
		}
		for(i=0, min_count=10; i<1025; i++){
			if(visited[ex][ey][i]==1)
				min_count=min(min_count, __builtin_popcount(i));
		}
		cout<<min_count<<"\n";
	}
	return 0;
}