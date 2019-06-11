#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, k, i, l, r, count;
	cin>>n>>k;
	int a[n];
	for(i=0, l=0, r=0, count=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	while(r<n){
		if(a[r]-a[l]==k){
			count++;
			l++;
			r++;
		}
		else if(a[r]-a[l]>k)
			l++;
		else
			r++;
	}
	cout<<count<<"\n";
	return 0;
}