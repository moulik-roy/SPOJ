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
	int N, i;
	cin>>N;
	int H[N], S[N], seg_tree[4*N];
	vector <int> height;
	for(i=0; i<N; i++)
		cin>>H[i];
	sort(H, H+N);
	build_tree(seg_tree, 0, 0, N-1);
	for(i=0; i<N; i++)
		cin>>S[i];
	for(i=N-1; i>=0; i--){
		height.push_back(findKth(seg_tree, H, S[i]+1, 0, 0, N-1));
		removeKth(seg_tree, S[i]+1, 0, 0, N-1);
	}
	for(i=N-1; i>=0; i--)
		cout<<height[i]<<"\n";
	return 0;
}