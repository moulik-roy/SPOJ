#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long int N, K, i, l, r, count;
    cin>>N>>K;
    long int a[N];
    for(i=0, l=0, r=0, count=0; i<N; i++)
    	cin>>a[i];
    sort(a, a+N);
    while(r<N){
    	if(a[r]-a[l]==K){
    		count++;
    		l++;
    		r++;
    	}
    	else if(a[r]-a[l]>K)
    		l++;
    	else
    		r++;
    }
    cout<<count<<"\n";
    return 0;
}
