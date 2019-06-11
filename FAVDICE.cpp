#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int t, N, i;
	double E;
	cin>>t;
	while(t--){
		cin>>N;
		for(i=1, E=1; i<N; i++)
			E=E+((double)N/i);
		printf("%.2lf\n", E);
	}
	return 0;
}