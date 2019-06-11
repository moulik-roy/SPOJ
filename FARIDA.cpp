#include <iostream>
using namespace std;

int main(){
	long int T, C, N, i, coins, incl, excl, excl_new;
	cin>>T;
	for(C=1; C<=T; C++){
		cin>>N;
		for(i=0, incl=0, excl=0; i<N; i++){
			cin>>coins;
			excl_new=max(incl, excl);
			incl=excl+coins;
			excl=excl_new;
		}
		cout<<"Case "<<C<<": "<<max(incl, excl)<<"\n";
	}
	return 0;
}