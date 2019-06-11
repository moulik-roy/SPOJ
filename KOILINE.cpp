#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void build_tree(int seg_tree[], int i, int s, int e){
	if(s==e){
		seg_tree[i]=1;
		return;
	}
	int mid=s+(e-s)/2;
	build_tree(seg_tree, 2*i+1, s, mid);
	build_tree(seg_tree, 2*i+2, mid+1, e);
	seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];	
}

int findKth(int seg_tree[], int H[], int k, int i, int s, int e){
	if(s==e)
		return H[s];
	else if(seg_tree[2*i+1]>=k)
		return findKth(seg_tree, H, k, 2*i+1, s, (s+e)/2);
	else
		return findKth(seg_tree, H, k-seg_tree[2*i+1], 2*i+2, ((s+e)/2)+1, e);
}

void removeKth(int seg_tree[], int k, int i, int s, int e){
	if(s==e){
		seg_tree[i]=0;
		return;
	}
	else if(seg_tree[2*i+1]>=k)
		removeKth(seg_tree, k, 2*i+1, s, (s+e)/2);
	else
		removeKth(seg_tree, k-seg_tree[2*i+1], 2*i+2, ((s+e)/2)+1, e);
	seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];
}

int main(){
	int n, i;
	cin>>n;
	int H[n], S[n], seg_tree[4*n];
	vector <int> v;
	for(i=0; i<n; i++)
		cin>>H[i];
	sort(H, H+n);
	build_tree(seg_tree, 0, 0, n-1);
	for(i=0; i<n; i++)
		cin>>S[i];
	for(i=n-1; i>=0; i--){
		v.push_back(findKth(seg_tree, H, S[i]+1, 0, 0, n-1));
		removeKth(seg_tree, S[i]+1, 0, 0, n-1);
	}
	for(i=n-1; i>=0; i--)
		cout<<v[i]<<"\n";
	return 0;
}
