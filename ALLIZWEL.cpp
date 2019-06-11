#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int visited[100][100], dx[8]={0, 1, 1, 1, 0, -1, -1, -1}, dy[8]={1, 1, 0, -1, -1, -1, 0, 1};

bool dfs(string matrix[], int R, int C, int i, int j, string s, int index){
	int k, x, y;
	visited[i][j]=1;
	if(index==s.length())
		return true;
	for(k=0; k<8; k++){
		x=i+dx[k];
		y=j+dy[k];
		if(x>=0 && x<R && y>=0 && y<C && matrix[x][y]==s[index] && !visited[x][y]){
			if(dfs(matrix, R, C, x, y, s, index+1))
				return true;
		}
	}
	visited[i][j]=0;
	return false;
}


int main(){
	int t, R, C, i, j, flag;
	cin>>t;
	while(t--){
		cin>>R>>C;
		string matrix[R], s="ALLIZZWELL";
		for(i=0; i<R; i++)
			cin>>matrix[i];
		memset(visited, 0, sizeof(visited));
		for(i=0, flag=0; i<R; i++){
			for(j=0; j<C; j++){
				if(matrix[i][j]=='A'){
					if(dfs(matrix, R, C, i, j, s, 1)){
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}