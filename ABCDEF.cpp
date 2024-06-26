#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	long int N, i, j, k, count;
	vector <long int> v1, v2;
	cin>>N;
	long int S[N];
	for(i=0; i<N; i++)
		cin>>S[i];
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			for(k=0; k<N; k++){
				v1.push_back(S[i]*S[j]+S[k]);
				if(S[k]!=0)
					v2.push_back((S[i]+S[j])*S[k]);
			}
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for(i=0, count=0; i<v1.size(); i++)
		count+=(upper_bound(v2.begin(), v2.end(), v1[i])-lower_bound(v2.begin(), v2.end(), v1[i]));
	cout<<count<<"\n";
	return 0;
}
