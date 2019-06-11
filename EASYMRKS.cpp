#include <iostream>
using namespace std;

int main(){
	int T, t, N, K, i, a, min_marks;
	cin>>T;
	for(t=1; t<=T; t++){
		cin>>N>>K;
		min_marks=(N+1)*K;
		for(i=0; i<N; i++){
			cin>>a;
			min_marks=min_marks-a;
		}
		cout<<"Case "<<t<<": "<<min_marks<<"\n";
	}
	return 0;
}
