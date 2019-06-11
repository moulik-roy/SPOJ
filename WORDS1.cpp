#include <iostream>
using namespace std;

void dfs(int graph[26][26], int visited[26], int src){
	visited[src]=1;
	for(int i=0; i<26; i++){
		if(graph[src][i]==1 && !visited[i])
			dfs(graph, visited, i);
	}
}

int main(){
	int T, N, n, i, source, sink, flag;
	string s;
	cin>>T;
	while(T--){
		cin>>N;
		int graph[26][26]={0}, v[26]={0}, in_degree[26]={0}, out_degree[26]={0}, visited[26]={0};
		for(i=0; i<N; i++){
			cin>>s;
			n=s.length();
			in_degree[s[n-1]-'a']++;
			out_degree[s[0]-'a']++;
			graph[s[0]-'a'][s[n-1]-'a']=1;
			v[s[0]-'a']=1;
			v[s[n-1]-'a']=1;
		}
		for(i=0, source=-1, sink=-1, flag=0; i<26; i++){
			if(out_degree[i]-in_degree[i]==1){
				if(source==-1)
					source=i;
				else{
					flag=1;
					break;
				}
			}
			else if(in_degree[i]-out_degree[i]==1){
				if(sink==-1)
					sink=i;
				else{
					flag=1;
					break;
				}
			}
			else if(in_degree[i]!=out_degree[i]){
				flag=1;
				break;
			}
		}
		if((source==-1 && sink!=-1) || (source!=-1 && sink==-1))
			flag=1;
		if(flag==0){
			if(source==-1 && sink==-1){
				for(i=0; i<26; i++){
					if(v[i]==1){
						source=i;
						break;
					}
				}
			}	
			dfs(graph, visited, source);
			for(i=0; i<26; i++){
				if(v[i]==1 && !visited[i]){
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
			cout<<"The door cannot be opened.\n";
		else
			cout<<"Ordering is possible.\n";
	}
	return 0;
}