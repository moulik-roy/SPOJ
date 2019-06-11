#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int mod(string s, int n){
	int i, d, r;
	for(i=0, r=0; i<s.length(); i++){
		d=s[i]-'0';
		r=(r*10+d)%n;
	}
	return r;
}

int main(){
	int K, n, rem;
	string s;
	cin>>K;
	while(K--){
		cin>>n;
		queue <string> q;
		set <int> prevMod;
		q.push("1");
		while(!q.empty()){
			s=q.front();
			rem=mod(s, n);
			if(rem==0)
				break;
			if(prevMod.find(rem)==prevMod.end()){
				q.push(s+"0");
				q.push(s+"1");
				prevMod.insert(rem);
			}
			q.pop();
		}
		cout<<s<<"\n";
	}
	return 0;
}