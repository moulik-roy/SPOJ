#include <iostream>
#include <string>
using namespace std;

int main(){
	long int T, N, K, i, sum, count;
	string s;
	cin>>T;
	while(T--){
		cin>>N>>K;
		cin>>s;
		long int freq[N+1]={0};
		freq[0]=1;
		for(i=0, sum=0, count=0; i<N; i++){
			sum+=(s[i]-'0');
			if(sum>=K)
				count+=freq[sum-K];
			freq[sum]++;
		}
		cout<<count<<"\n";
	}
	return 0;
}