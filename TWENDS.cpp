#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> dp;

int max_sum(int cards[], int i, int j){
	int x, y;
	if(i==j)
		return cards[i];
	else if(i>j)
		return 0;
	else if(dp[i][j]!=-1)
		return dp[i][j];
	if(cards[j]>cards[i+1])
		x=cards[i]+max_sum(cards, i+1, j-1);
	else
		x=cards[i]+max_sum(cards, i+2, j);
	if(cards[j-1]>cards[i])
		y=cards[j]+max_sum(cards, i, j-2);
	else
		y=cards[j]+max_sum(cards, i+1, j-1);
	dp[i][j]=max(x, y);
	return dp[i][j];
}

int main(){
	int m, n, i, sum, p;
	m=1;
	while(cin>>n && n!=0){
		int cards[n];
		for(i=0, sum=0; i<n; i++){
			cin>>cards[i];
			sum+=cards[i];
		}
		dp.clear();
		dp.assign(n, vector<int>(n, -1));
		p=2*max_sum(cards, 0, n-1)-sum;
		cout<<"In game "<<m++<<", the greedy strategy might lose by as many as "<<p<<" points.\n";
	}
	return 0;
}