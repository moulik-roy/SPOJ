#include <iostream>
using namespace std;

int main(){
	int T, N, i, j, max_length;
	cin>>T;
	while(T--){
		cin>>N;
		int A[N], lis[N], lds[N];
		for(i=0; i<N; i++)
			cin>>A[i];
		for(i=0; i<N; i++){
			lis[i]=1;
			for(j=0; j<i; j++){
				if(A[j]<A[i] && lis[i]<lis[j]+1)
					lis[i]=lis[j]+1;
			}
		}
		for(i=N-1; i>=0; i--){
			lds[i]=1;
			for(j=N-1; j>i; j--){
				if(A[j]<A[i] && lds[i]<lds[j]+1)
					lds[i]=lds[j]+1;
			}
		}
		for(i=1, max_length=lis[0]+lds[0]-1; i<N; i++)
			max_length=max(max_length, lis[i]+lds[i]-1);
		cout<<max_length<<"\n";
	}
	return 0;
}