#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long int N, M, i, low, high, mid, sum, max_height;
	cin>>N>>M;
	long int height[N];
	for(i=0; i<N; i++)
		cin>>height[i];
	low=0;		high=*max_element(height, height+N);		max_height=0;
	while(low<high){
		mid=low+(high-low)/2;
		for(i=0, sum=0; i<N; i++){
			if(height[i]>mid)
				sum=sum+(height[i]-mid);
		}
		if(sum>=M){
			max_height=max(max_height, mid);
			low=mid+1;
		}
		else
			high=mid;
	}
	cout<<max_height<<"\n";
	return 0;
}