#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int test_cases, t, Q, i, position, prev, flag;
	string S, T;
	cin>>test_cases;
	getchar();
	for(t=1; t<=test_cases; t++){
		cout<<"Case "<<t<<":\n";
		getline(cin, S);
		cin>>Q;
		getchar();
		vector <int> indexes[26];
		for(i=0; i<S.length(); i++)
			indexes[S[i]-'a'].push_back(i);
		while(Q--){
			getline(cin, T);
			for(i=0, prev=-1, flag=0; i<T.length(); i++){
				position=lower_bound(indexes[T[i]-'a'].begin(), indexes[T[i]-'a'].end(), prev+1)-indexes[T[i]-'a'].begin();
				if(position==indexes[T[i]-'a'].size()){
					flag=1;
					break;
				}
				prev=indexes[T[i]-'a'][position];
			}
			if(flag==0)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}