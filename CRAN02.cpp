#include <iostream>
#include <map>
using namespace std;

int main(){
	long int T, n, i, a, sum, count;
	cin>>T;
	while(T--){
		cin>>n;
		map <long int, long int> prevSum;
		for(i=0, sum=0, count=0; i<n; i++){
			cin>>a;
			sum=sum+a;
			if(sum==0)
				count++;
			if(prevSum.find(sum)!=prevSum.end())
				count+=prevSum[sum];
			prevSum[sum]++;
		}
		cout<<count<<"\n";
	}
	return 0;
}