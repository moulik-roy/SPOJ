#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int t, n, u, l, r, val, q, i;
	cin>>t;
	while(t--){
		cin>>n>>u;
		int a[n+1];
		memset(a, 0, sizeof(a));
		while(u--){
			cin>>l>>r>>val;
			a[l]+=val;
			a[r+1]-=val;
		}
		for(i=1; i<=n; i++)
			a[i]+=a[i-1];
		cin>>q;
		while(q--){
			cin>>i;
			cout<<a[i]<<"\n";
		}
	}
	return 0;
}