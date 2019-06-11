#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int N, i, j, r, count;
	cin>>N;
	for(i=2, count=1; i<=N; i++){
		r=sqrt(i);
		for(j=1; j<=r; j++){
			if(i%j==0)
				count++;
		}
	}
	cout<<count<<"\n";
	return 0;
}