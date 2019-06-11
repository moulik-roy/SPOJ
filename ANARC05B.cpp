#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int na, nb, i, p, a, b, sum_A, sum_B, max_sum;
	while(cin>>na && na!=0){
		int A[na], prefix_A[na+1];
		for(i=1, prefix_A[0]=0; i<=na; i++){
			cin>>A[i-1];
			prefix_A[i]=prefix_A[i-1]+A[i-1];
		}
		cin>>nb;
		int B[nb], prefix_B[nb+1];
		for(i=1, prefix_B[0]=0; i<=nb; i++){
			cin>>B[i-1];
			prefix_B[i]=prefix_B[i-1]+B[i-1];
		}
		for(i=1, a=0, b=0, max_sum=0; i<=na; i++){
			if(binary_search(B, B+nb, A[i-1])){
				p=lower_bound(B, B+nb, A[i-1])-B;
				sum_A=prefix_A[i]-prefix_A[a];
				sum_B=prefix_B[p+1]-prefix_B[b];
				max_sum+=max(sum_A, sum_B);
				a=i;
				b=p+1;
			}
		}
		sum_A=prefix_A[na]-prefix_A[a];
		sum_B=prefix_B[nb]-prefix_B[b];
		max_sum+=max(sum_A, sum_B);
		cout<<max_sum<<"\n";
	}
	return 0;
}
