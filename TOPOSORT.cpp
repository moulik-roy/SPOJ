#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n, m, i, x, y;
	cin>>n>>m;
	vector <int> graph[n+1], in_degree(n+1, 0), job_order;
	priority_queue <int, vector <int>, greater <int>> q;
	for(i=0; i<m; i++){
		cin>>x>>y;
		graph[x].push_back(y);
		in_degree[y]++;
	}
	for(i=1; i<=n; i++){
		if(in_degree[i]==0)
			q.push(i);
	}
	while(!q.empty()){
		x=q.top();
		job_order.push_back(x);
		q.pop();
		for(i=0; i<graph[x].size(); i++){
			y=graph[x][i];
			in_degree[y]--;
			if(in_degree[y]==0)
				q.push(y);
		}
	}
	if(job_order.size()<n)
		cout<<"Sandro fails.\n";
	else{
		for(i=0; i<job_order.size(); i++)
			cout<<job_order[i]<<" ";
		cout<<"\n";
	}
	return 0;
}