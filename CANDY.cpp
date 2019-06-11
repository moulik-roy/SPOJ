#include <iostream>
using namespace std;

int main(){
	int N, i, count, sum;
	while(cin>>N && N!=-1){
		int candies[N];
		for(i=0, sum=0; i<N; i++){
			cin>>candies[i];
			sum=sum+candies[i];
		}
		if(sum%N==0){
		    sum=sum/N;
		    for(i=0, count=0; i<N; i++){
		        if(candies[i]<sum)
		            count=count+(sum-candies[i]);
		    }
		    cout<<count<<"\n";
		}
		else
		    cout<<"-1\n";
	}
	return 0;
}