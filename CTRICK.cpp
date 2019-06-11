#include <iostream>
#include <cstring>
using namespace std;

void update(int BIT[], int n, int i, int val){
	while(i<=n){
		BIT[i]+=val;
		i+=(i&(-i));
	}
}

int getSum(int BIT[], int i){
	int sum=0;
	while(i>0){
		sum+=BIT[i];
		i-=(i&(-i));
	}
	return sum;
}

int main(){
	int t, n, i, p, positions_left, l, r, m, sum;
	cin>>t;
	while(t--){
		cin>>n;
		int BIT[n+1], card_position[n];
		memset(BIT, 0, sizeof(BIT));
		for(i=1; i<=n; i++)
			update(BIT, n, i, 1);
		for(i=1, p=1, positions_left=n; i<=n; i++, positions_left--){
			p=(p+i)%positions_left;
			if(p==0)
				p=positions_left;
			l=1;	r=n;
			while(l<=r){
				m=(l+r)/2;
				sum=getSum(BIT, m);
				if(sum<p)
					l=m+1;
				else
					r=m-1;
			}
			card_position[l-1]=i;
			update(BIT, n, l, -1);
		}
		for(i=0; i<n; i++)
			cout<<card_position[i]<<" ";
		cout<<"\n";
	}
	return 0;
}