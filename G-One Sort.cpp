#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int t, i, n, l, c;
	cin>>t;
	while(t--){
		cin>>n;
		pair<int, int> a[n];
		for(i=0; i<n; i++){
			cin>>a[i].first;
			a[i].second=i;
		}
		sort(a, a+n);
		for(i=0, l=1, c=1; i<n-1; i++){
			if(a[i].second<a[i+1].second)
				l++;
			else if(c<l){
				c=l;
				l=1;
			}
		}
		if(c<l)
			c=l;
		c=n-c;
		cout<<c<<"\n";
	}
	return 0;
}
