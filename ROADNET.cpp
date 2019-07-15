#include <iostream>
using namespace std;

int main(){
	int t, n, i, j, k, flag;
	cin>>t;
	while(t--){
		cin>>n;
		int dist[n][n];
		for(i=0; i<n; i++){
			for(j=0; j<n; j++)
				cin>>dist[i][j];
		}
		for(i=0; i<n-1; i++){
			for(j=i+1; j<n; j++){
				for(k=0, flag=0; k<n; k++){
					if(k!=i && k!=j && dist[i][k]+dist[k][j]==dist[i][j]){
						flag=1;
						break;
					}
				}
				if(flag==0)
					cout<<i+1<<" "<<j+1<<"\n";
			}
		}
		cout<<"\n";
	}
	return 0;
}