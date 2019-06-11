#include <iostream>
using namespace std;

int main(){
	long int t, n, i, count, flag;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=2, flag=0; i*i<=n && flag==0; i++){
			if(n%i==0){
				count=0;
				while(n%i==0){
					n/=i;
					count++;
				}
				if(i%4==3 && count%2!=0)
					flag=1;
			}
		}
		if(n%4==3)
			flag=1;
		if(flag==0)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}