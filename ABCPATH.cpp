#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dx[8]={0, 1, 1, 1, 0, -1, -1, -1}, dy[8]={1, 1, 0, -1, -1, -1, 0, 1};

int dfs(string s[], int H, int W, int i, int j, vector <vector<int>> &dp){
	int k, x, y;
	if(dp[i][j]!=-1)
		return dp[i][j];
	dp[i][j]=1;
	for(k=0; k<8; k++){
		x=i+dx[k];
		y=j+dy[k];
		if(x>=0 && x<H && y>=0 && y<W && s[x][y]==s[i][j]+1)
			dp[i][j]=max(dp[i][j], 1+dfs(s, H, W, x, y, dp));
	}
	return dp[i][j];
}

int main(){
	int C, H, W, i, j, max_length;
	C=1;
	while(cin>>H>>W && H+W!=0){
		string grid[H];
		vector <vector<int>> dp(H, vector<int>(W, -1));
		for(i=0; i<H; i++)
			cin>>grid[i];
		for(i=0, max_length=0; i<H; i++){
			for(j=0; j<W; j++){
				if(grid[i][j]=='A')
					max_length=max(max_length, dfs(grid, H, W, i, j, dp));
			}
		}
		cout<<"Case "<<C++<<": "<<max_length<<"\n";
	}
	return 0;
}