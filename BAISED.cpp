#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
	long int T, N, i, min_badness;
	string team_name;
	cin>>T;
	while(T--){
		cin>>N;
		int preferred_place[N];
		for(i=0; i<N; i++)
			cin>>team_name>>preferred_place[i];
		sort(preferred_place, preferred_place+N);
		for(i=0, min_badness=0; i<N; i++)
			min_badness=min_badness+abs(i-preferred_place[i]+1);
		cout<<min_badness<<"\n";
	}
	return 0;
}