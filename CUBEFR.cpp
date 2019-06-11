#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int T, N, i, j, cube, CFN[1000001];
	memset(CFN, 0, sizeof(CFN));
	for(i=2; i*i*i<=1000000; i++){
		if(CFN[i]==0){
			cube=i*i*i;
			for(j=cube; j<=1000000; j+=cube)
				CFN[j]=-1;
		}
	}
	for(i=1, j=1; i<=1000000; i++){
		if(!CFN[i])
			CFN[i]=j++;
	}
	cin>>T;
	for(i=1; i<=T; i++){
		cin>>N;
		cout<<"Case "<<i<<": ";
		if(CFN[N]!=-1)
			cout<<CFN[N]<<"\n";
		else
			cout<<"Not Cube Free\n";
	}
	return 0;
}