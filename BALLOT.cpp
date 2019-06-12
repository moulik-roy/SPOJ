#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int N, B, i, no_ballots, low, high, mid, max_people;
	while(cin>>N>>B && N!=-1 && B!=-1){
		int a[N];
		for(i=0; i<N; i++)
			cin>>a[i];	
		low=0;	high=*max_element(a, a+N);	max_people=high;
		while(low<high){
			mid=low+(high-low)/2;
			for(i=0, no_ballots=0; i<N; i++)
				no_ballots+=ceil(a[i]*1.0/mid);
			if(no_ballots<=B){
				max_people=min(max_people, mid);
				high=mid;
			}
			else
				low=mid+1;
		}
		cout<<max_people<<"\n";
	}
	return 0;
}