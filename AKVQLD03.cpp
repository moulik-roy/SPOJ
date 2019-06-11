#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void update_BIT(int BIT[], int N, int index, int val){
	while(index<=N){
		BIT[index]+=val;
		index=index+(index & (-index));
	}
}

int get_sum(int BIT[], int N, int index){
	int sum=0;
	while(index>0){
		sum+=BIT[index];
		index=index-(index & (-index));
	}
	return sum;
}

int main(){
	int N, Q, P, F, A, B;
	string s;
	cin>>N>>Q;
	int BIT[N+1];
	memset(BIT, 0, sizeof(BIT));
	while(Q--){
		cin>>s;
		if(s.compare("add")==0){
			cin>>P>>F;
			update_BIT(BIT, N, P, F);
		}
		else{
			cin>>A>>B;
			A=get_sum(BIT, N, A-1);
			B=get_sum(BIT, N, B);
			cout<<B-A<<"\n";
		}
	}
	return 0;
}
