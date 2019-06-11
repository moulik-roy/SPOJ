#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int t, n, i, count, min_operations;
	cin>>t;
	while(t--){
		cin>>n;
		pair <int, int> book[n];
		for(i=0; i<n; i++){
			cin>>book[i].first;
			book[i].second=i;
		}
		sort(book, book+n);
		for(i=0, count=1, min_operations=1; i<n-1; i++){
			if(book[i].second<book[i+1].second)
				count++;
			else if(min_operations<count){
				min_operations=count;
				count=1;
			}
		}
		if(min_operations<count)
			min_operations=count;
		min_operations=n-min_operations;
		cout<<min_operations<<"\n";
	}
	return 0;
}
