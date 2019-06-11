#include <iostream>
using namespace std;

int main(){
	long int t, N, player;
	cin>>t;
	while(t--){
		cin>>N>>player;
		if(player==0)
			cout<<"Airborne wins.\n";
		else
			cout<<"Pagfloyd wins.\n";
	}
	return 0;
}