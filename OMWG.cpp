#include <iostream>
using namespace std;

int main(){
	int T, N, M, max_score;
	cin>>T;
	while(T--){
		cin>>N>>M;
		max_score=2*M*N-M-N;
		cout<<max_score<<"\n";
	}
	return 0;
}