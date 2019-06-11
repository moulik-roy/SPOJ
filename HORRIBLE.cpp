#include <iostream>
#include <cstring>
using namespace std;

void build_tree(long int seg_tree[], long int a[], long int i, long int ss, long int se){
	if(ss==se){
		seg_tree[i]=a[ss];
		return;
	}
	long int mid=ss+(se-ss)/2;
	build_tree(seg_tree, a, 2*i+1, ss, mid);
	build_tree(seg_tree, a, 2*i+2, mid+1, se);
	seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];
}

void update_tree(long int seg_tree[], long int lazy[], long int qs, long int qe, long int val, long int i, long int ss, long int se){
	if(lazy[i]!=0){
		seg_tree[i]+=(se-ss+1)*lazy[i];
		if(ss!=se){
			lazy[2*i+1]+=lazy[i];
			lazy[2*i+2]+=lazy[i];
		}
		lazy[i]=0;
	}
	if(qs>se || qe<ss)
		return;
	if(qs<=ss && qe>=se){
		seg_tree[i]+=(se-ss+1)*val;
		if(ss!=se){
			lazy[2*i+1]+=val;
			lazy[2*i+2]+=val;
		}
		return;
	}
	long int mid=ss+(se-ss)/2;
	update_tree(seg_tree, lazy, qs, qe, val, 2*i+1, ss, mid);
	update_tree(seg_tree, lazy, qs, qe, val, 2*i+2, mid+1, se);
	seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];
}

long int query_tree(long int seg_tree[], long int lazy[], long int qs, long int qe, long int i, long int ss, long int se){
	if(lazy[i]!=0){
		seg_tree[i]+=(se-ss+1)*lazy[i];
		if(ss!=se){
			lazy[2*i+1]+=lazy[i];
			lazy[2*i+2]+=lazy[i];
		}
		lazy[i]=0;
	}
	if(qs>se || qe<ss)
		return 0;
	if(qs<=ss && qe>=se)
		return seg_tree[i];
	long int mid=ss+(se-ss)/2;
	return query_tree(seg_tree, lazy, qs, qe, 2*i+1, ss, mid)+query_tree(seg_tree, lazy, qs, qe, 2*i+2, mid+1, se);
}

int main(){
	long int T, N, C, t, p, q, v, ans;
	cin>>T;
	while(T--){
		cin>>N>>C;
		long int a[N], seg_tree[4*N], lazy[4*N];
		memset(a, 0, sizeof(a));
		memset(seg_tree, 0, sizeof(seg_tree));
		memset(lazy, 0, sizeof(lazy));
		while(C--){
			cin>>t;
			if(t==0){
				cin>>p>>q>>v;
				update_tree(seg_tree, lazy, p-1, q-1, v, 0, 0, N-1);
			}
			else{
				cin>>p>>q;
				ans=query_tree(seg_tree, lazy, p-1, q-1, 0, 0, N-1);
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}