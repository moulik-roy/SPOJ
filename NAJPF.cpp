#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int T, i, j;
	string A, B;
	cin>>T;
	while(T--){
		cin>>A>>B;
		int lps[B.length()];
		vector <int> positions;
		lps[0]=0;	i=1;	j=0;
		while(i<B.length()){
			if(B[i]==B[j]){
				lps[i]=lps[j]+1;
				i++;
				j++;
			}
			else{
				if(j!=0)
					j=lps[j-1];
				else{
					lps[i]=0;
					i++;
				}
			}
		}
		i=0;	j=0;
		while(i<A.length()){
			if(A[i]==B[j]){
				i++;
				j++;
			}
			if(j==B.length()){
				positions.push_back(i-B.length()+1);
				j=lps[j-1];
			}
			else if(i<A.length() && A[i]!=B[j]){
				if(j!=0)
					j=lps[j-1];
				else
					i++;
			}
		}
		if(positions.size()==0)
			cout<<"Not Found\n\n";
		else{
			cout<<positions.size()<<"\n";
			for(i=0; i<positions.size(); i++)
				cout<<positions[i]<<" ";
			cout<<"\n\n";
		}
	}
	return 0;
}