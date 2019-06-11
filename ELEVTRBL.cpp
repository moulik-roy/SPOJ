#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main(){
	int f, s, g, u, d, cur_floor, nextUp, nextDown;
	queue <int> q;
	cin>>f>>s>>g>>u>>d;
	int dist[f+1];
	memset(dist, -1, sizeof(dist));
	dist[s]=0;
	q.push(s);
	while(!q.empty() && dist[g]==-1){
		cur_floor=q.front();
		nextUp=cur_floor+u;
		if(nextUp<=f && dist[nextUp]==-1){
			dist[nextUp]=dist[cur_floor]+1;
			q.push(nextUp);
		}
		nextDown=cur_floor-d;
		if(nextDown>0 && dist[nextDown]==-1){
			dist[nextDown]=dist[cur_floor]+1;
			q.push(nextDown);
		}
		q.pop();
	}
	if(dist[g]==-1)
		cout<<"use the stairs\n";
	else
		cout<<dist[g]<<"\n";
	return 0;
}