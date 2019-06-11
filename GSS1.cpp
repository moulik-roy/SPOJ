#include <iostream>
using namespace std;

struct node{
	long int prefix_sum, suffix_sum, sum, max_subarray_sum;
};

node merge(node left, node right){
	node parent;
	parent.prefix_sum=max(left.prefix_sum, left.sum+right.prefix_sum);
	parent.suffix_sum=max(right.suffix_sum, right.sum+left.suffix_sum);
	parent.sum=left.sum+right.sum;
	parent.max_subarray_sum=max(max(left.max_subarray_sum, right.max_subarray_sum), left.suffix_sum+right.prefix_sum);
	return parent;
}

void build_tree(node seg_tree[], long int a[], long int i, long int s, long int e){
	if(s==e){
		seg_tree[i].prefix_sum=a[s];
		seg_tree[i].suffix_sum=a[s];
		seg_tree[i].sum=a[s];
		seg_tree[i].max_subarray_sum=a[s];
		return;	
	}
	long int mid=s+(e-s)/2;
	build_tree(seg_tree, a, 2*i+1, s, mid);
	build_tree(seg_tree, a, 2*i+2, mid+1, e);
	seg_tree[i]=merge(seg_tree[2*i+1], seg_tree[2*i+2]);
}

node query_tree(node seg_tree[], long int qs, long int qe, long int i, long int s, long int e){
	if(qs==s && qe==e)
		return seg_tree[i];
	long int mid=s+(e-s)/2;
	if(qe<=mid)
		return query_tree(seg_tree, qs, qe, 2*i+1, s, mid);
	else if(qs>mid)
		return query_tree(seg_tree, qs, qe, 2*i+2, mid+1, e);
	else
		return merge(query_tree(seg_tree, qs, mid, 2*i+1, s, mid), query_tree(seg_tree, mid+1, qe, 2*i+2, mid+1, e));
}

int main(){
	long int N, M, i, x, y;
	cin>>N;
	long int a[N];
	node seg_tree[4*N];
	for(i=0; i<N; i++)
		cin>>a[i];
	build_tree(seg_tree, a, 0, 0, N-1);
	cin>>M;
	while(M--){
		cin>>x>>y;
		cout<<query_tree(seg_tree, x-1, y-1, 0, 0, N-1).max_subarray_sum<<"\n";
	}
	return 0;
}