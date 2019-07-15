#include <iostream>
using namespace std;

int main(){
	int T, P, M, i, start, sum, max_planets, min_autobots;
	cin>>T;
	while(T--){
		cin>>P>>M;
		int no_autobots[P];
		for(i=0; i<P; i++)
			cin>>no_autobots[i];
		for(i=0, start=0, sum=0, max_planets=0, min_autobots=0; i<P; i++){
			sum+=no_autobots[i];
			while(sum>M && start<=i)
				sum-=no_autobots[start++];
			if(max_planets<i-start+1 || (max_planets==i-start+1 && min_autobots>sum)){
				max_planets=i-start+1;
				min_autobots=sum;
			}
		}
		cout<<min_autobots<<" "<<max_planets<<"\n";
	}
	return 0;
}