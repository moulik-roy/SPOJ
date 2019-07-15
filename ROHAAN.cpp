#include <iostream>
using namespace std;

int main(){
	int T, t, N, R, i, j, k, s, d, total_dist;
	cin>>T;
	for(t=1; t<=T; t++){
		cin>>N;
		int graph[N][N], dist[N][N];
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				cin>>graph[i][j];
				dist[i][j]=graph[i][j];
			}
		}
		for(k=0, total_dist=0; k<N; k++){
			for(i=0; i<N; i++){
				for(j=0; j<N; j++){
					if(dist[i][j]>dist[i][k]+dist[k][j])
						dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
		cin>>R;
		while(R--){
			cin>>s>>d;
			total_dist+=dist[s-1][d-1];
		}
		cout<<"Case #"<<t<<": "<<total_dist<<"\n";
	}
	return 0;
}