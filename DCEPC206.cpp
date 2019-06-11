#include <iostream>
using namespace std;

long int merge(long int a[], long int l, long int m, long int r){
	long int i, j, k, sum, temp[r-l+1];
	i=l;	j=m+1;	k=0;	sum=0;
	while(i<=m && j<=r){
		if(a[i]<a[j]){
			sum=sum+(a[i]*(r-j+1));
			temp[k++]=a[i++];
		}
		else if(a[i]>=a[j])
			temp[k++]=a[j++];
	}
	while(i<=m)
		temp[k++]=a[i++];
	while(j<=r)
		temp[k++]=a[j++];
	for(i=l; i<=r; i++)
		a[i]=temp[i-l];
	return sum;
}

long int merge_sort(long int a[], long int l, long int r){
	long int m, sum=0;
	if(l<r){
		m=l+(r-l)/2;
		sum=merge_sort(a, l, m);
		sum+=merge_sort(a, m+1, r);
		sum+=merge(a, l, m, r);
	}
	return sum;
}

int main(){
	long int T, N, i;
	cin>>T;
	while(T--){
		cin>>N;
		long int a[N];
		for(i=0; i<N; i++)
			cin>>a[i];
		cout<<merge_sort(a, 0, N-1)<<"\n";
	}
	return 0;
}
