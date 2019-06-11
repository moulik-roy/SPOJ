#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main(){
	int t, n, i;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		getchar();
		map <string, int> m;
		for(i=0; i<n; i++){
			getline(cin, s);
			m[s]++;
		}
		for(map<string, int>::iterator it=m.begin(); it!=m.end(); it++)
			cout<<it->first<<" "<<it->second<<"\n";
	}
	return 0;
}
