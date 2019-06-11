#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N, i, l, r, count;
	while(cin>>N && N!=0){
		int L[N];
		for(i=0; i<N; i++)
			cin>>L[i];
		sort(L, L+N);
		for(i=N-1, count=0; i>1; i--){
			l=0;	r=i-1;
			while(l<r){
				while(l<r && L[l]+L[r]>=L[i])
					r--;
				count=count+(r-l);
				l++;
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}
