#include <iostream>
#include <algorithm>
using namespace std;

struct Order{
	int start_time, duration, price;
	bool operator<(const Order &ord){
		return start_time<ord.start_time;
	}
};

int lower_bound(Order order[], int n, int t){
	int low, high, mid;
	low=0;	high=n;
	while(low<high){
		mid=low+(high-low)/2;
		if(order[mid].start_time>=t)
			high=mid;
		else
			low=mid+1;
	}
	return low;
}

int main(){
	int T, n, i;
	cin>>T;
	while(T--){
		cin>>n;
		Order order[n];
		int dp[n+1];
		for(i=0; i<n; i++)
			cin>>order[i].start_time>>order[i].duration>>order[i].price;
		sort(order, order+n);
		for(i=n-1, dp[n]=0; i>=0; i--)
			dp[i]=max(dp[i+1], dp[lower_bound(order, n, order[i].start_time+order[i].duration)]+order[i].price);
		cout<<dp[0]<<"\n";
	}
	return 0;
}