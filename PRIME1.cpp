#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	long int t, m, n, i, j, flag, s;
	vector <long int> primes;
	primes.push_back(2);
	for(i=3; i<=32000; i+=2){
		flag=1;
		for(j=0; j<primes.size() && primes[j]*primes[j]<=i; j++){
			if(i%primes[j]==0){
				flag=0;
				break;
			}
		}
		if(flag==1)
			primes.push_back(i);
	}
	cin>>t;
	while(t--){
		cin>>m>>n;
		if(m==1)
			m=2;
		bool isPrime[n-m+1];
		memset(isPrime, true, sizeof(isPrime));
		for(i=0; i<primes.size() && primes[i]*primes[i]<=n; i++){
			if(primes[i]>=m)
				s=2*primes[i];
			else
				s=m+(primes[i]-(m%primes[i]))%primes[i];
			for(j=s; j<=n; j+=primes[i])
				isPrime[j-m]=false;
		}
		for(i=m; i<=n; i++){
			if(isPrime[i-m]==true)
				cout<<i<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
