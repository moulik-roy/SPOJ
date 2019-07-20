#include <iostream>
#include <algorithm>
using namespace std;

struct Level{
	int L, H, E, A;
};

bool comparator(Level a, Level b){
	if(a.H==b.H){
		if(a.E==b.E)
			return (a.A>b.A);
		else
			return (a.E<b.E);
	}
	else
		return (a.H>b.H);
}

int main(){
	int N, i;
	cin>>N;
	Level a[N];
	for(i=0; i<N; i++){
		a[i].L=i+1;
		cin>>a[i].H>>a[i].E>>a[i].A;
	}
	if(N==1)
		cout<<"Easiest and Hardest is level 1\n";
	else{
		sort(a, a+N, comparator);
		cout<<"Easiest is level "<<a[0].L<<"\n";
		cout<<"Hardest is level "<<a[N-1].L<<"\n";
	}
	return 0;
}