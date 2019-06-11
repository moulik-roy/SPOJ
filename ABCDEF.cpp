#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	long int n, i, j, k, c;
	vector <long int> v1, v2;
	cin>>n;
	long int a[n];
	for(i=0; i<n; i++)
		cin>>a[i];
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			for(k=0; k<n; k++){
				v1.push_back(a[i]*a[j]+a[k]);
				if(a[k]!=0)
					v2.push_back((a[i]+a[j])*a[k]);
			}
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for(i=0, c=0; i<v1.size(); i++)
		c=c+(upper_bound(v2.begin(), v2.end(), v1[i])-lower_bound(v2.begin(), v2.end(), v1[i]));
	cout<<c<<"\n";
	return 0;
}
