#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

bool isPrime[10000];

void seive(){
	int i, j;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0]=isPrime[1]=false;
	for(i=2; i*i<10000; i++){
		if(isPrime[i]==true){
			for(j=i*i; j<10000; j+=i)
				isPrime[j]=false;
		}
	}
}

int main(){
	int t, n, i, j, src, num, dist[10000];
	string s;
	seive();
	cin>>t;
	while(t--){
		cin>>s;
		cin>>n;
		queue <string> q;
		memset(dist, -1, sizeof(dist));
		dist[stoi(s)]=0;
		q.push(s);
		while(!q.empty() && dist[n]==-1){
			for(i=0; i<4; i++){
				s=q.front();
				src=stoi(s);
				for(j=0; j<10; j++){
					if(i==0 && j==0)
						continue;
					s[i]=(char)(j+'0');
					num=stoi(s);
					if(isPrime[num] && dist[num]==-1){
						dist[num]=dist[src]+1;
						q.push(s);
					}
				}
			}
			q.pop();
		}
		if(dist[n]==-1)
			cout<<"Impossible\n";
		else
			cout<<dist[n]<<"\n";
	}
	return 0;
}
