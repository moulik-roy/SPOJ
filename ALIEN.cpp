#include <iostream>
using namespace std;

int main(){
	int T, At, Bt, i, start, sum, max_stations, no_people;
	cin>>T;
	while(T--){
		cin>>At>>Bt;
		int people[At];
		for(i=0; i<At; i++)
			cin>>people[i];
		for(i=0, start=0, sum=0, max_stations=0, no_people=0; i<At; i++){
			sum+=people[i];
			while(sum>Bt && start<=i)
				sum-=people[start++];
			if(max_stations<i-start+1 || (max_stations==i-start+1 && no_people>sum)){
				max_stations=i-start+1;
				no_people=sum;
			}
		}
		cout<<no_people<<" "<<max_stations<<"\n";
	}
	return 0;
}