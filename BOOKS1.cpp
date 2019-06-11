#include <iostream>
#include <vector>
using namespace std;

bool partition(long int a[], long int n, long int partition_sum, long int k){
	long int i, sum, c;
	for(i=0, sum=0, c=1; i<n; i++){
		if(a[i]>partition_sum)
			return false;
		sum+=a[i];
		if(sum>partition_sum){
			sum=a[i];
			c++;
		}
	}
	if(c>k)
		return false;
	else
		return true;
}

int main(){
	long int N, m, k, i, max_pages, sum, max_sum, l, r, mid;
	cin>>N;
	while(N--){
		cin>>m>>k;
		long int pages[m];
		vector <long int> partitions;
		for(i=0, max_pages=0, sum=0; i<m; i++){
			cin>>pages[i];
			max_pages=max(max_pages, pages[i]);
			sum+=pages[i];
		}
		l=max_pages;	r=sum;	max_sum=sum;
		while(l<=r){
			mid=l+(r-l)/2;
			if(partition(pages, m, mid, k)){
				max_sum=min(max_sum, mid);
				r=mid-1;
			}
			else
				l=mid+1;
		}
		for(i=m-1, sum=0; i>=0; i--){
			if(sum+pages[i]>max_sum || i==k-2){
				sum=0;
				partitions.push_back(-1);
				k--;
			}
			sum+=pages[i];
			partitions.push_back(pages[i]);
		}
		for(i=partitions.size()-1; i>=0; i--){
			if(partitions[i]==-1)
				cout<<"/ ";
			else
				cout<<partitions[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
