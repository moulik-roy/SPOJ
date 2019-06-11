#include <iostream>
using namespace std;

int main(){
	int T, N, i, index, max_outer_radius;
	cin>>T;
	while(T--){
		cin>>N;
		int r[N], R[N];
		for(i=0, index=1; i<N; i++){
			cin>>r[i]>>R[i];
			if(r[i]>r[index-1])
				index=i+1;
		}
		for(i=0, max_outer_radius=0; i<N; i++){
			if(i+1!=index && max_outer_radius<R[i])
				max_outer_radius=R[i];
		}
		if(r[index-1]<max_outer_radius)
			index=-1;
		cout<<index<<"\n";
	}
	return 0;
}