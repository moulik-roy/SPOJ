#include <iostream>
using namespace std;

int main() {
	int T, N, i, min_count;
	cin>>T;
	while(T--){
		cin>>N;
		int P[N];
		for(i=0; i<N; i++)
			cin>>P[i];
		for(i=N-2, min_count=P[N-1]; i>=0; i--)
			min_count=max(min_count+1, P[i]);
		cout<<min_count<<"\n";
	}
	return 0;
}