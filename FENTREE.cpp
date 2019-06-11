#include <iostream>
#include <cstring>
using namespace std;

void update(long int BIT[], long int n, long int i, long int val){
	while(i<=n){
		BIT[i]+=val;
		i+=(i&(-i));
	}
}

long int getSum(long int BIT[], long int N, long int i){
	long int sum=0;
	while(i>0){
		sum+=BIT[i];
		i-=(i&(-i));
	}
	return sum;
}

int main(){
	long N, Q, i, l, r, x, sum;
	char ch;
	cin>>N;
	long int a[N], BIT[N+1];
	memset(BIT, 0, sizeof(BIT));
	for(i=0; i<N; i++){
		cin>>a[i];
		update(BIT, N, i+1, a[i]);
	}
	cin>>Q;
	while(Q--){
		cin>>ch;
		if(ch=='q'){
			cin>>l>>r;
			sum=getSum(BIT, N, r)-getSum(BIT, N, l-1);
			cout<<sum<<"\n";
		}
		else{
			cin>>i>>x;
			update(BIT, N, i, x);
		}
	}
	return 0;
}