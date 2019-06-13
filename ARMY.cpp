#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T, NG, NM, i;
	cin>>T;
	while(T--){
		cin>>NG>>NM;
		int Godzilla[NG], MechaGodzilla[NM];
		for(i=0; i<NG; i++)
			cin>>Godzilla[i];
		for(i=0; i<NM; i++)
			cin>>MechaGodzilla[i];
		sort(Godzilla, Godzilla+NG);
		sort(MechaGodzilla, MechaGodzilla+NM);
		if(Godzilla[NG-1]<MechaGodzilla[NM-1])
			cout<<"MechaGodzilla\n";
		else
			cout<<"Godzilla\n";
	}
	return 0;
}