#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n, k, i;
	cin>>n;
	int a[n];
	for(i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	deque <int> q;
	for(i=0; i<k; i++){
		while(!q.empty() && a[i]>=a[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	for(i=k; i<n; i++){
		cout<<a[q.front()]<<" ";
		while(!q.empty() && q.front()<=i-k)
			q.pop_front();
		while(!q.empty() && a[i]>=a[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	cout<<a[q.front()]<<"\n";
	return 0;
}