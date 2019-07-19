#include <iostream>
using namespace std;

struct node{
	int maximum, second_maximum;
};

node merge(node left, node right){
	node parent;
	parent.maximum=max(left.maximum, right.maximum);
	parent.second_maximum=min(max(left.maximum, right.second_maximum), max(left.second_maximum, right.maximum));
	return parent;
}

void build_tree(node seg_tree[], int A[], int i, int s, int e){
	if(s==e){
		seg_tree[i].maximum=A[s];
		seg_tree[i].second_maximum=-1;
		return;
	}
	int mid=(s+e)/2;
	build_tree(seg_tree, A, 2*i+1, s, mid);
	build_tree(seg_tree, A, 2*i+2, mid+1, e);
	seg_tree[i]=merge(seg_tree[2*i+1], seg_tree[2*i+2]);
}

void update(node seg_tree[], int index, int value, int i, int s, int e){
	if(s==e){
		seg_tree[i].maximum=value;
		seg_tree[i].second_maximum=-1;
		return;
	}
	int mid=(s+e)/2;
	if(index<=mid)
		update(seg_tree, index, value, 2*i+1, s, mid);
	else
		update(seg_tree, index, value, 2*i+2, mid+1, e);
	seg_tree[i]=merge(seg_tree[2*i+1], seg_tree[2*i+2]);
}

node query_tree(node seg_tree[], int qs, int qe, int i, int s, int e){
	if(qs==s && qe==e)
		return seg_tree[i];
	int mid=(s+e)/2;
	if(qe<=mid)
		return query_tree(seg_tree, qs, qe, 2*i+1, s, mid);
	else if(qs>mid)
		return query_tree(seg_tree, qs, qe, 2*i+2, mid+1, e);
	else
		return merge(query_tree(seg_tree, qs, mid, 2*i+1, s, mid), query_tree(seg_tree, mid+1, qe, 2*i+2, mid+1, e));
}

int main(){
	int N, i, Q, x, y;
	char op;
	cin>>N;
	int A[N];
	node seg_tree[4*N];
	for(i=0; i<N; i++)
		cin>>A[i];
	build_tree(seg_tree, A, 0, 0, N-1);
	cin>>Q;
	while(Q--){
		cin>>op;
		if(op=='U'){
			cin>>i>>x;
			update(seg_tree, i-1, x, 0, 0, N-1);
		}
		else{
			cin>>x>>y;
			node max_sum=query_tree(seg_tree, x-1, y-1, 0, 0, N-1);
			cout<<max_sum.maximum+max_sum.second_maximum<<"\n";
		}
	}
	return 0;
}