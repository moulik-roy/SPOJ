#include <iostream>
using namespace std;

long int merge(long int a[], long int l, long int m, long int r){
	long int i, j, k, inv_cnt, temp[r-l+1];
	i=l;	j=m+1;	k=0;	inv_cnt=0;
	while(i<=m && j<=r){
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else if(a[i]>a[j]){
			inv_cnt+=(m+1-i);
			temp[k++]=a[j++];
		}
	}
	while(i<=m)
		temp[k++]=a[i++];
	while(j<=r)
		temp[k++]=a[j++];
	for(i=l; i<=r; i++)
		a[i]=temp[i-l];
	return inv_cnt;
}

long int merge_sort(long int a[], long int l, long int r){
	long int m, inv_cnt=0;
	if(l<r){
		m=l+(r-l)/2;
		inv_cnt=merge_sort(a, l, m);
		inv_cnt+=merge_sort(a, m+1, r);
		inv_cnt+=merge(a, l, m, r);
	}
	return inv_cnt;
}

int main(){
	long int t, n, i;
	cin>>t;
	while(t--){
		cin>>n;
		long int a[n];
		for(i=0; i<n; i++)
			cin>>a[i];
		cout<<merge_sort(a, 0, n-1)<<"\n";
	}
	return 0;
}
