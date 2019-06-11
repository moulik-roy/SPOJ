#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int visited[52][52], dx[8]={0, 1, 1, 1, 0, -1, -1, -1}, dy[8]={1, 1, 0, -1, -1, -1, 0, 1};

void dfs(string s[], int H, int W, int i, int j, int length, int &max_length){
	int k, x, y;
	visited[i][j]=1;
	if(max_length<length)
		max_length=length;
	for(k=0; k<8; k++){
		x=i+dx[k];
		y=j+dy[k];
		if(x>=0 && x<H && y>=0 && y<W && s[x][y]==s[i][j]+1 && !visited[x][y])
			dfs(s, H, W, x, y, length+1, max_length);
	}
}

int main(){
	int C, H, W, i, j, max_length;
	C=1;
	while(cin>>H>>W && H+W!=0){
		string grid[H];
		for(i=0; i<H; i++)
			cin>>grid[i];
		memset(visited, 0, sizeof(visited));
		for(i=0, max_length=0; i<H; i++){
			for(j=0; j<W; j++){
				if(grid[i][j]=='A' && !visited[i][j])
					dfs(grid, H, W, i, j, 1, max_length);			
			}
		}
		cout<<"Case "<<C++<<": "<<max_length<<"\n";
	}
	return 0;
}