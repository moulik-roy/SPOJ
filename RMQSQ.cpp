#include <iostream>
#include <climits>
using namespace std;

void build_tree(int seg_tree[], int a[], int i, int s, int e){
	if(s==e){
		seg_tree[i]=a[s];
		return;
	}
	build_tree(seg_tree, a, 2*i+1, s, (s+e)/2);
	build_tree(seg_tree, a, 2*i+2, ((s+e)/2)+1, e);
	seg_tree[i]=min(seg_tree[2*i+1], seg_tree[2*i+2]);
}

int query_tree(int seg_tree[], int qs, int qe, int i, int s, int e){
	if(qe<s || qs>e)
		return INT_MAX;
	else if(qs<=s && qe>=e)
		return seg_tree[i];
	else
		return min(query_tree(seg_tree, qs, qe, 2*i+1, s, (s+e)/2), query_tree(seg_tree, qs, qe, 2*i+2, ((s+e)/2)+1, e));
}

int main(){
	int N, Q, i, j;
	cin>>N;
	int a[N], seg_tree[4*N];
	for(i=0; i<N; i++)
		cin>>a[i];
	build_tree(seg_tree, a, 0, 0, N-1);
	cin>>Q;
	while(Q--){
		cin>>i>>j;
		cout<<query_tree(seg_tree, i, j, 0, 0, N-1)<<"\n";
	}
	return 0;
}