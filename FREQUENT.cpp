#include <iostream>
using namespace std;

struct node{
	int start_num, end_num, start_count, end_count, max_freq;
};

node merge(node left, node right){
	node parent;
	parent.start_num=left.start_num;
	parent.end_num=right.end_num;
	if(left.start_num==right.start_num)
		parent.start_count=left.start_count+right.start_count;
	else
		parent.start_count=left.start_count;
	if(left.end_num==right.end_num)
		parent.end_count=left.end_count+right.end_count;
	else
		parent.end_count=right.end_count;
	parent.max_freq=max(left.max_freq, right.max_freq);
	if(left.end_num==right.start_num)
		parent.max_freq=max(parent.max_freq, left.end_count+right.start_count);
	return parent;
}

void build_tree(node seg_tree[], int a[], int i, int s, int e){
	if(s==e){
		seg_tree[i].start_num=a[s];
		seg_tree[i].end_num=a[s];
		seg_tree[i].start_count=1;
		seg_tree[i].end_count=1;
		seg_tree[i].max_freq=1;
		return;
	}
	int mid=s+(e-s)/2;
	build_tree(seg_tree, a, 2*i+1, s, mid);
	build_tree(seg_tree, a, 2*i+2, mid+1, e);
	seg_tree[i]=merge(seg_tree[2*i+1], seg_tree[2*i+2]);
}

node query_tree(node seg_tree[], int qs, int qe, int i, int s, int e){
	if(qs==s && qe==e)
		return seg_tree[i];
	int mid=s+(e-s)/2;
	if(qe<=mid)
		return query_tree(seg_tree, qs, qe, 2*i+1, s, mid);
	else if(qs>mid)
		return query_tree(seg_tree, qs, qe, 2*i+2, mid+1, e);
	else
		return merge(query_tree(seg_tree, qs, mid, 2*i+1, s, mid), query_tree(seg_tree, mid+1, qe, 2*i+2, mid+1, e));
}

int main(){
	int n, q, i, j;
	while(cin>>n && n!=0){
		cin>>q;
		int a[n];
		node seg_tree[4*n];
		for(i=0; i<n; i++)
			cin>>a[i];
		build_tree(seg_tree, a, 0, 0, n-1);
		while(q--){
			cin>>i>>j;
			cout<<query_tree(seg_tree, i-1, j-1, 0, 0, n-1).max_freq<<"\n";
		}
	}
	return 0;
}