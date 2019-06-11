#include <iostream>
#include <string>
using namespace std;

int dfs(string s[], int n, int i, int j, int **visited, int c){
	if(visited[i][j]==0)
		visited[i][j]=c;
	else if(visited[i][j]==c)
		return 1;
	else if(visited[i][j]!=c)
		return 0;
	switch(s[i][j]){
		case 'N': if(i-1>=0)
					return dfs(s, n, i-1, j, visited, c);
		case 'E': if(j+1<s[0].length())
					return dfs(s, n, i, j+1, visited, c);
		case 'S': if(i+1<n)
					return dfs(s, n, i+1, j, visited, c);
		case 'W': if(j-1>=0)
					return dfs(s, n, i, j-1, visited, c);
	}
}

int main(){
	int n, m, i, j, no_traps, count;
	cin>>n>>m;
	string s[n];
	int **visited=new int*[n];
	for(i=0; i<n; i++){
		visited[i]=new int[m];
		for(j=0; j<m; j++)
			visited[i][j]=0;
	}
	for(i=0; i<n; i++)
		cin>>s[i];
	for(i=0, no_traps=0, count=1; i<n; i++){
		for(j=0; j<m; j++){
			if(visited[i][j]==0){
				no_traps+=dfs(s, n, i, j, visited, count);
				count++;
			}
		}
	}
	cout<<no_traps<<"\n";
	return 0;
}